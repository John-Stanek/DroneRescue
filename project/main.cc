#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <memory>
#include "image.h"

#include "greyscale_filter.h"
#include "gaussian.h"
#include "sobel.h"
#include "non_max_suppression.h"
#include "double_threshold_filter.h"
#include "hysteresis_filter.h"
#include "canny_edge_detect_filter.h"

using namespace std;

int main(int argc, const char* argv[]) {
    // Get input file, filter type, and output file from command line
    // argc = # of arguments
    // argv = an array of arguments
    const char* inputFile = argv[1];
    std::string filterType(argv[2]);
    const char* outputFile(argv[3]);
    
    // Create available filters (unique_ptr handles dynamic memory)
    std::map<std::string, unique_ptr<Filter>> filters;
    //filters["greyscale"] = unique_ptr<Filter>(new GreyScaleFilter());
    //filters["gaussian"] = unique_ptr<Filter>(new GaussianBlurFilter(1,5));
    //filters["sobel"] = unique_ptr<Filter>(new SobelFilter());
    //filters["non-max-suppression"] = unique_ptr<Filter>(new NonMaxSuppression());
    //filters["double-threshold"] = unique_ptr<Filter>(new DoubleThresholdFilter(0.05 , 0.09));
    filters["canny-edge-detect"] = unique_ptr<Filter>(new CannyEdgeDetectFilter());

    // Create input and output vectors
    Image input(inputFile);
    Image output;
    std::vector<Image*> inputs;
    std::vector<Image*> outputs;
    inputs.push_back(&input);
    outputs.push_back(&output);

    // Apply filter based on filter type
    filters[filterType]->Apply(inputs, outputs);
    
    // Save output image
    output.SaveAs(outputFile);
}

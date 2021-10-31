#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <memory>
#include "image.h"
#include "greyscale_filter.h"
#include "threshold_filter.h"
#include "mean_blur_filter.h"
#include "double_threshold_filter.h"
#include "sobel.h"
#include "gaussian.h"

using namespace std;

int main(int argc, const char* argv[]) {
    // Get input file, filter type, and output file from command line
    // argc = # of arguments
    // argv = an array of arguments
    const char* inputFile = argv[1];
    std::string filterType(argv[2]);
    const char* outputFile(argv[3]);
    const char* outputFile2(argv[4]);

    // Create available filters (unique_ptr handles dynamic memory)
    std::map<std::string, unique_ptr<Filter>> filters;
    filters["greyscale"] = unique_ptr<Filter>(new GreyScaleFilter());
    filters["threshold"] = unique_ptr<Filter>(new ThresholdFilter(0.5));
    filters["threshold-low"] = unique_ptr<Filter>(new ThresholdFilter(0.25));
    filters["threshold-high"] = unique_ptr<Filter>(new ThresholdFilter(0.75));
    filters["mean_blur"] = unique_ptr<Filter>(new MeanBlurFilter());
    filters["double-threshold"] = unique_ptr<Filter>(new DoubleThresholdFilter(0.10, 0.35));
    filters["sobel"] = unique_ptr<Filter>(new SobelFilter());
    filters["gaussian"] = unique_ptr<Filter>(new GaussianBlurFilter(1.0, 5.0));
    // Create input and output vectors
    Image input(inputFile);
    Image output;
    Image output2;
    std::vector<Image*> inputs;
    std::vector<Image*> outputs;
    inputs.push_back(&input);
    outputs.push_back(&output);
    outputs.push_back(&output2);

    // Apply filter based on filter type
    filters[filterType]->Apply(inputs, outputs);
    
    // Save output image
    output.SaveAs(outputFile);
    output2.SaveAs(outputFile2);
}

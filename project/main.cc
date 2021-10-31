#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <memory>
#include "image.h"
<<<<<<< HEAD

#include "sharpen_filter.h"
=======
#include "greyscale_filter.h"
#include "threshold_filter.h"
#include "mean_blur_filter.h"
#include "double_threshold_filter.h"
#include "sobel.h"
>>>>>>> 7e2e8d21cf6e8d747e5349630cdd94e55e4699aa

using namespace std;

int main(int argc, const char* argv[]) {
    // Get input file, filter type, and output file from command line
    // argc = # of arguments
    // argv = an array of arguments
    const char* inputFile = argv[1];
    std::string filterType(argv[2]);
    const char* outputFile(argv[3]);
<<<<<<< HEAD
    
    // Create available filters (unique_ptr handles dynamic memory)
    std::map<std::string, unique_ptr<Filter>> filters;
    filters["sharpen"] = unique_ptr<Filter>(new SharpenFilter());
    //filters["greyscale"] = unique_ptr<Filter>(new GreyScaleFilter());
    //filters["threshold"] = unique_ptr<Filter>(new ThresholdFilter(0.5));
    //filters["threshold-low"] = unique_ptr<Filter>(new ThresholdFilter(0.25));
    //filters["threshold-high"] = unique_ptr<Filter>(new ThresholdFilter(0.75));
    //filters["mean_blur"] = unique_ptr<Filter>(new MeanBlurFilter());

    // Create input and output vectors
    Image input(inputFile);
    Image output;
=======
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
    // Create input and output vectors
    Image input(inputFile);
    Image output;
    Image output2;
>>>>>>> 7e2e8d21cf6e8d747e5349630cdd94e55e4699aa
    std::vector<Image*> inputs;
    std::vector<Image*> outputs;
    inputs.push_back(&input);
    outputs.push_back(&output);
<<<<<<< HEAD
=======
    outputs.push_back(&output2);
>>>>>>> 7e2e8d21cf6e8d747e5349630cdd94e55e4699aa

    // Apply filter based on filter type
    filters[filterType]->Apply(inputs, outputs);
    
    // Save output image
    output.SaveAs(outputFile);
<<<<<<< HEAD
=======
    output2.SaveAs(outputFile2);
>>>>>>> 7e2e8d21cf6e8d747e5349630cdd94e55e4699aa
}

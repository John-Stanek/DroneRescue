#ifndef BLOB_DETECTION_H
#define BLOB_DETECTION_H

#include "imageio/filter.h"

using namespace imageio;

/**
 * @brief Class for applying Blob detection to an image.
 * 
 */

// Creating your own Filter class is simple. Just override ApplyInternal().
class BlobDetection : public Filter {
public:
    // 1 input, 1 output
    BlobDetection() : Filter(1, 1) {}

/**
 * @brief Overloads Filter ApplyInternal method and applies blob detection filter
 * @param parameter-inputs: a vector of input images to be filtered with blob detection
 * @param parameter-outputs a vector of output images that are the result of blob detection being applied to inputs
 */

protected:
    void ApplyInternal(const vector<IImage *> &inputs, const vector<IImage *> &outputs) {
        // Do not modify any of the inputs
        // Outputs are assumed to be empty images, resize them first
        const IImage& input = *inputs[0];
        IImage& output = *outputs[0];

        // pick 1 or 2
        // 1. resize image to have same dimensions as input (does not copy pixels over)
        output.Resize(input);        
        //2. copy image to output
        //output.CopyFrom(input);

        // loop over pixels
        for (int x = 0; x < input.GetWidth(); ++x) {
            for (int y = 0; y < input.GetHeight(); ++y) {
                // do stuff
                // Color pixel = input.GetPixel(x, y) etc...
                Color pixel = input.GetPixel(x, y);
                if (pixel.Red() <= 265 && pixel.Red() >= 210) {
                    if (pixel.Green() <= 200 && pixel.Green() >= 110) {
                        if (pixel.Blue() <= 60 && pixel.Blue() >= 10) {
                            output.SetPixel(x, y, Color(1.0, 1.0, 1.0, 1.0));                                                    
                        }
                    }
                } else {
                    output.SetPixel(x, y, Color(0.0, 0.0, 0.0, 1.0));
                }
            }
        }
    }
};

#endif //SAMPLE_FILTER_H
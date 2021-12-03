#ifndef BLOB_DETECTION_H
#define BLOB_DETECTION_H

#include "imageio/filter.h"

using namespace imageio;

// Creating your own Filter class is simple. Just override ApplyInternal().
class BlobDetection : public Filter {
public:
    // 1 input, 1 output
    BlobDetection() : Filter(1, 1) {}
        
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
                if (pixel.Red() <= 265 && pixel.Red() >= 220) {
                    if (pixel.Green() <= 200 && pixel.Green() >= 100) {
                        if (pixel.Blue() <= 62 && pixel.Blue() >= 10) {
                            pixel.R = pixel.GetLuminance();
                            pixel.B = pixel.GetLuminance();
                            pixel.G = pixel.GetLuminance();
                            pixel.A = 1.0;
                            output.SetPixel(x, y, pixel);                                                    
                        }
                    }
                } else {
                    output.SetPixel(x, y, Color(0.0, 0.0, 0.0, pixel.Alpha()));
                }
            }
        }
    }
};

#endif //SAMPLE_FILTER_H
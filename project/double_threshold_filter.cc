#include "double_threshold_filter.h"

DoubleThresholdFilter::DoubleThresholdFilter(float weak, float strong) {
    strong_threshold_ratio = strong;
    weak_threshold_ratio = weak;
}

void DoubleThresholdFilter::Apply(std::vector<Image*> original, std::vector<Image*> filtered) {
    *filtered[0] = *original[0];
    float strong = 1.0;
    float weak = 0.10;
    float none = 0.0;
    float max = 0.0;

    for(int x=0; x<filtered[0]->GetWidth(); x++) {
        for(int y=0; y<filtered[0]->GetHeight(); y++) {
            Color pixel = filtered[0]->GetPixel(x, y);
            if(pixel.Red() >= max) {
              max = pixel.Red();
            }
            if(pixel.Green() >= max) {
              max = pixel.Green();
            }
            if(pixel.Blue() >= max) {
              max = pixel.Blue();
            }
        }
    }

    float highThreshold = strong_threshold_ratio*max;
    float lowThreshold = weak_threshold_ratio*highThreshold;
  
    for(int x=0; x<filtered[0]->GetWidth(); x++) {
        for(int y=0; y<filtered[0]->GetHeight(); y++) {
            Color pixel = filtered[0]->GetPixel(x, y);
            float alpha = pixel.Alpha();
            if(pixel.Red() >= highThreshold){
                pixel = strong;
            }
            else if(pixel.Red() <= highThreshold && pixel.Red() >= lowThreshold) {
                pixel = weak;
            } else if(pixel.Red() < lowThreshold){
                pixel = none;
            } 
            pixel.SetAlpha(alpha);
            filtered[0]->SetPixel(x, y, pixel);
        }
    }
}

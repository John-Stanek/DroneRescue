#include "double_threshold_filter.h"

DoubleThresholdFilter::DoubleThresholdFilter(float sThresh, float wThresh) {
    strong_threshold_ratio = sThresh;
    weak_threshold_ratio = wThresh;
}

void DoubleThresholdFilter::Apply(std::vector<Image*> original, std::vector<Image*> filtered) {
    *filtered[0] = *original[0];
    float highThreshold = 1.0*strong_threshold_ratio;
    float weakThreshold = 1.0*weak_threshold_ratio;
    float strong = 1.0;
    float weak = 0.25;
    float none = 0.0;

    for(int x=0; x<filtered[0]->GetWidth(); x++) {
        for(int y=0; y<filtered[0]->GetHeight(); y++) {
            Color pixel = filtered[0]->GetPixel(x, y);
            if(pixel.Red() < highThreshold && pixel.Red() >= weakThreshold) {
                pixel = weak;
                filtered[0]->SetPixel(x, y, pixel);                
            } else if(pixel.Red() > highThreshold) {
                pixel = strong;
                filtered[0]->SetPixel(x, y, pixel);
            } else {
                pixel = none;
                filtered[0]->SetPixel(x, y, pixel);
            } 
        }
    }
}
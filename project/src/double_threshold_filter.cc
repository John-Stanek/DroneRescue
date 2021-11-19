#include "double_threshold_filter.h"

DoubleThresholdFilter::DoubleThresholdFilter(float weak, float strong) {
    strong_threshold_ratio = strong;
    weak_threshold_ratio = weak;
}

void DoubleThresholdFilter::Apply(std::vector<Image*> original, std::vector<Image*> filtered) {
    *filtered[0] = *original[0];

    float highThreshold = strong_threshold_ratio;
    float lowThreshold = weak_threshold_ratio*highThreshold;
  
    for(int x=0; x<filtered[0]->GetWidth(); x++) {
        for(int y=0; y<filtered[0]->GetHeight(); y++) {
            Color pixel = filtered[0]->GetPixel(x, y);
            float alpha = pixel.Alpha();
            if(pixel.Red() >= highThreshold){
                pixel = 1.0;
            }
            else if(pixel.Red() <= highThreshold && pixel.Red() >= lowThreshold) {
                pixel = 0.10;
            } else if(pixel.Red() < lowThreshold){
                pixel = 0.0;
            } 
            pixel.SetAlpha(alpha);
            filtered[0]->SetPixel(x, y, pixel);
        }
    }
}

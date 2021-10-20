#include "threshold_filter.h"

ThresholdFilter::ThresholdFilter(float value) {
    threshold = value;
}

void ThresholdFilter::Apply(std::vector<Image*> original, std::vector<Image*> filtered) {
    *filtered[0] = *original[0];
    for (int x=0; x<filtered[0]->GetWidth(); x++) {
        for (int y=0; y<filtered[0]->GetHeight(); y++) {
            Color pixel = filtered[0]->GetPixel(x, y);
            float lum = 0.2126*pixel.Red() + 0.7152*pixel.Green() + 0.0722*pixel.Blue();
            if (lum < threshold) {
                pixel = 0.0;
                filtered[0]->SetPixel(x, y, pixel);
            } else {
                pixel = 1;
                filtered[0]->SetPixel(x, y, pixel);
            }
        }
    }
}
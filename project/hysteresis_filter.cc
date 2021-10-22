#include "hysteresis_filter.h"

void HysteresisFilter::Apply(std::vector<Image*> original, std::vector<Image*> filtered) {
    *filtered[0] = *original[0];
    float strong = 1.0;
    float weak = 0.25;
    float none = 0.0;

    for(int x=0; x<filtered[0]->GetWidth(); x++) {
        for(int y=0; y<filtered[0]->GetHeight(); y++) {
            Color pixel = filtered[0]->GetPixel(x, y);
            if(pixel.Red() == weak) {
                if(filtered[0]->GetPixel(x, y-1).Red() == strong || filtered[0]->GetPixel(x, y+1).Red() == strong ||
                    filtered[0]->GetPixel(x-1, y-1).Red() == strong || filtered[0]->GetPixel(x-1, y).Red() == strong ||
                    filtered[0]->GetPixel(x-1, y+1).Red() == strong || filtered[0]->GetPixel(x+1, y-1).Red() == strong ||
                    filtered[0]->GetPixel(x+1, y).Red() == strong || filtered[0]->GetPixel(x+1, y+1).Red() == strong) {
                    
                    pixel = strong;
                } else {
                    pixel = none;
                }
                filtered[0]->SetPixel(x, y, pixel);
            }
        }
    }
}

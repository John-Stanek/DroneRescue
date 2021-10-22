#include "hysteresis_filter.h"

void HysteresisFilter::Apply(std::vector<Image*> original, std::vector<Image*> filtered) {
    *filtered[0] = *original[0];
    float strong = 255.0;
    float weak = 25.0;
    float none = 0.0;

    for(int x=0; x<filtered[0]->GetWidth(); x++) {
        for(int y=0; y<filtered[0]->GetHeight(); y++) {
            Color pixel = filtered[0]->GetPixel(x, y);
            if(pixel.Red()*255 == weak) {
                if(filtered[0]->GetPixel(x, y-1).Red()*255 >= strong || filtered[0]->GetPixel(x, y+1).Red()*255 >= strong ||
                    filtered[0]->GetPixel(x-1, y-1).Red()*255 >= strong || filtered[0]->GetPixel(x-1, y).Red()*255 >= strong ||
                    filtered[0]->GetPixel(x-1, y+1).Red()*255 >= strong || filtered[0]->GetPixel(x+1, y-1).Red()*255 >= strong ||
                    filtered[0]->GetPixel(x+1, y).Red()*255 >= strong || filtered[0]->GetPixel(x+1, y+1).Red()*255 >= strong) {
                    
                    pixel = strong;
                }
            } else {
                pixel = none;
            }
            filtered[0]->SetPixel(x, y, pixel);
        }
    }
}

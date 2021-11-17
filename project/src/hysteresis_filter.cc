#include "hysteresis_filter.h"

void HysteresisFilter::Apply(std::vector<Image*> original, std::vector<Image*> filtered) {
    *filtered[0] = *original[0];

    for(int x=0; x<filtered[0]->GetWidth(); x++) {
        for(int y=0; y<filtered[0]->GetHeight(); y++) {
            Color pixel = filtered[0]->GetPixel(x, y);
            float alpha = pixel.Alpha();
            if(pixel.Red() <= 0.10 && pixel.Red() >= 0.09) {
                if(filtered[0]->GetPixel(x, y-1).Red() == 1.0 || filtered[0]->GetPixel(x, y+1).Red() == 1.0 ||
                    filtered[0]->GetPixel(x-1, y-1).Red() == 1.0 || filtered[0]->GetPixel(x-1, y).Red() == 1.0 ||
                    filtered[0]->GetPixel(x-1, y+1).Red() == 1.0 || filtered[0]->GetPixel(x+1, y-1).Red() == 1.0 ||
                    filtered[0]->GetPixel(x+1, y).Red() == 1.0 || filtered[0]->GetPixel(x+1, y+1).Red() == 1.0) {
                  pixel = 1.0;  
                } else {
                  pixel = 0.0;
                }
            }
            pixel.SetAlpha(alpha);
            filtered[0]->SetPixel(x, y, pixel);
        }
    }
}


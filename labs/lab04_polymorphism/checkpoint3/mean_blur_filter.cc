#include "mean_blur_filter.h"

void MeanBlurFilter::Apply(std::vector<Image*> original, std::vector<Image*> filtered) {
    *filtered[0] = *original[0];
    for (int x=0; x<filtered[0]->GetWidth(); x++) {
        for (int y=0; y<filtered[0]->GetHeight(); y++) {
            unsigned char* pixel = filtered[0]->GetPixel(x, y);
            float add[3] = {0,0,0};
            for (int i=x-1; i<=x+1; i++) {
                for (int j=y-1; j<=y+1; j++) {
                    if (i != -1 && j != -1 && i != filtered[0]->GetWidth() && j != filtered[0]->GetHeight()) {
                        unsigned char* neighbor = original[0]->GetPixel(i, j);
                        for(int k=0; k<3; k++) {
                            add[k] += neighbor[k] * (1.0/9.0);
                        } 
                    }
                }
                filtered[0]->SetPixel(x, y, pixel, add);
            }
        }
    }
}
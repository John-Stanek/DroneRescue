#include <iostream>
#include "greyscale_filter.h"
#include "color.h"


void GreyScaleFilter::Apply(std::vector<Image*> original, std::vector<Image*> filtered) {
    *filtered[0] = *original[0];
    for (int x=0; x<original[0]->GetWidth(); x++) {
        for (int y=0; y<original[0]->GetHeight(); y++) {
            Color pixel = filtered[0]->GetPixel(x, y);        
            float lum = (0.2126*pixel.Red() + 0.7152*pixel.Green() + 0.0722*pixel.Blue());
            pixel = lum;
            filtered[0]->SetPixel(x, y, pixel);
        }
    }
}

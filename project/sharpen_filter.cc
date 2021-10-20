#include "sharpen_filter.h"

void SharpenFilter::Apply(std::vector<Image*> original, std::vector<Image*> filtered){
	float kernel[][3] =  {
    {0.0, -1.0, 0.0},
    {-1.0, 5.0, -1.0},
    {0.0, -1.0, 0.0}
	};
	
	*filtered[0] = *original[0];
    for (int x=0; x<original[0]->GetWidth(); x++) {
        for (int y=0; y<original[0]->GetHeight(); y++) {
            Color pixel = Color();
            for (int i=-1; i<=1; i++) {
                for (int j=-1; j<=1; j++) {
                    if (i+x != -1 && j+y != -1 && i+x != original[0]->GetWidth() && j+y != original[0]->GetHeight()) {
                        Color neighbor = original[0]->GetPixel(i+x, j+y);
                        pixel = pixel + (neighbor * kernel[j+1][i+1]);
                    }
                }
            }
            if (pixel.Red() < 0){
				pixel.SetRed(0);
			}
			if (pixel.Red() > 1){
				pixel.SetRed(1);
			}
			if (pixel.Green() < 0){
				pixel.SetGreen(0);
			}
			if (pixel.Green() > 1){
				pixel.SetGreen(1);
			}
			if (pixel.Blue() < 0){
				pixel.SetBlue(0);	
			}
			if (pixel.Blue() > 1){
				pixel.SetBlue(1);
			}
			if (pixel.Alpha() < 0){
				pixel.SetAlpha(0);	
			}
			if (pixel.Alpha() > 1){
				pixel.SetAlpha(1);
			}
            filtered[0]->SetPixel(x, y, pixel);
        }
    }
}

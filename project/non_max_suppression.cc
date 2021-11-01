#include "non_max_suppression.h"
#include <stdlib.h>
#include <cmath>

void NonMaxSuppression::Apply(std::vector<Image*> original, std::vector<Image*> filtered){
	*filtered[0] = *original[0];
	//original[0] = intensity
	//original[1] = direction

	int originalWidth = original[0]->GetWidth();
	int originalHeight = original[0]->GetHeight();
	
	double angle =0;
	
	for (int x = 1; x < originalWidth; x++) {
		for (int y = 1; y < originalHeight; y++) {
			Color pixel = filtered[0]->GetPixel(x,y);
			pixel = 0.0;
			angle = original[1]->GetPixel(x,y).Red();
			angle = angle * (180 / M_PI);
			double q = 1;
			double r = 1;
			//angle 0
            if ((0 <= angle < 22.5) || (157.5 <= angle <= 180)){
                q = original[0]->GetPixel(x, y+1).Red();
                r = original[0]->GetPixel(x, y-1).Red();
            }
            //angle 45
            else if(22.5 <= angle < 67.5){
                q = original[0]->GetPixel(x+1, y-1).Red();
                r = original[0]->GetPixel(x-1, y+1).Red();
            }
            //angle 90
            else if(67.5 <= angle < 112.5){
                q = original[0]->GetPixel(x+1, y).Red();
                r = original[0]->GetPixel(x-1, y).Red();
            }
            //angle 135
            else if(112.5 <= angle < 157.5){
                q = original[0]->GetPixel(x-1, y-1).Red();
                r = original[0]->GetPixel(x+1, y+1).Red();
            }
            if ((original[0]->GetPixel(x, y).Red() >= q) && (original[0]->GetPixel(x, y).Red() >= r)){
                pixel = original[0]->GetPixel(x, y);
            }
            else{
                pixel = Color(0,0,0,1);
            }
			filtered[0]->SetPixel(x, y, pixel);
		}
	}
}



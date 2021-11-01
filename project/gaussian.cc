#include "gaussian.h"
#include "color.h"
#include <math.h>

GaussianBlurFilter::GaussianBlurFilter() {}

GaussianBlurFilter::GaussianBlurFilter(float sigma, int size){
    this->sigma = sigma;
    this->size = size;
}

void GaussianBlurFilter::Apply(std::vector<Image*> original, std::vector<Image*> filtered){
    *filtered[0] = *original[0];
    float kernel[size][size];
    for(int x = 0; x < size; x++){
        for(int y = 0; y < size; y++){
            float normal = 1 / (2.0 * M_PI * sigma * sigma);
            float final = exp(-((x*x + y*y) / (2.0 * sigma * sigma))) * normal;

            kernel[x][y] = final;
        }
    }
    for(int x = 0; x < original[0]->GetWidth(); x++){
        for(int y = 0; y < original[0]->GetHeight(); y++){
            Color add(0,0,0,1);
            for(int i = -size/2; i <= size/2; i++){
                for(int j = -size/2; j <= size/2; j++){
                    if(i+x < original[0]->GetWidth() && j+y < original[0]->GetHeight() && i+x > -1 && j +y> -1){
                        add = add + original[0]->GetPixel(i+x,j+y)*(kernel[i+size/2][j+size/2]);   
                    }
                }
            }
            add.SetAlpha(1.0);
            add.SetRed(add.Red() * 3);
            add.SetGreen(add.Green() * 3);
            add.SetBlue(add.Blue()* 3);
            
            
            if (add.Red() < 0) {
				add.SetRed(0);
			}
			if (add.Red() > 1) {
				add.SetRed(1);
			}
			if (add.Green() < 0) {
				add.SetGreen(0);
			}
			if (add.Green() > 1) {
				add.SetGreen(1);
			}
			if (add.Blue() < 0) {
				add.SetBlue(0);
			}
			if (add.Blue() > 1) {
				add.SetBlue(1);
			}
			
            filtered[0]->SetPixel(x, y, add);
        }
    }
    //filtered[0]->Normalize();
}

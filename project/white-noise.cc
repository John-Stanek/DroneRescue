#include "white-noise.h"
#include <stdlib.h>
#include <cmath>

WhiteNoise::WhiteNoise(){}

void WhiteNoise::Apply(std::vector<Image*> original, std::vector<Image*> filtered){
	*(filtered[0]) = *(original[0]);

	/*
	uses kernel:
	{0,   -1/9,    0}
	{-1/9, 4/9, -1/9}
	{0,   -1/9,    0}
	*/

	int originalWidth = original[0]->GetWidth();
	int originalHeight = original[0]->GetHeight();
	for (int x = 0; x < originalWidth; x++) {
		for (int y = 0; y < originalHeight; y++) {
			int randVal1 = rand()%10 + 1;
			int randVal2 = rand()%10 + 1;
			Color pixel = filtered[0]->GetPixel(x,y);
			pixel = 0.0;
				for (int i=x-1; i<=x+1; i++) {
	                for (int j=y-1; j<=y+1; j++) {
	                if (i != -1 && j != -1 && i != filtered[0]->GetWidth() && j != filtered[0]->GetHeight()) {        
	                    	Color neighbor = original[0]->GetPixel(i,j);
							if(i == x && j == y){
								neighbor = neighbor * (4.0/9.0);
								pixel = pixel + neighbor;
							}
							else if( (i%2==0 && j%2!=0) || (i%2!=0 && j%2 ==0)){
								neighbor = neighbor * (1.0/9.0);
								pixel = pixel - neighbor;
							}
					}
					
				}
			}

			filtered[0]->SetPixel(x, y, pixel);
		}
	}
}


#include "sobel.h"
#include "color.h"
#include <math.h>
#include <cmath>


void SobelFilter::Apply(std::vector<Image*> original, std::vector<Image*> filtered){
    *filtered[0] = *original[0];
    filtered.push_back(original[0]);
    
    Image Dx = *original[0];
    Image Dy = *original[0];
    Image Ix = *original[0]; 
    Image Iy = *original[0];
    
    Image direction = *original[0];
    Image intensity = *original[0];
    
    float xkernel[3][3] = {{-1,0,1}, {-2,0,2}, {-1,0,1}};
    float ykernel[3][3] = {{1,2,1}, {0,0,0}, {-1,-2,-1}};
    int size = 3;
    
    for(int x = 0; x < original[0]->GetWidth(); x++){
        for(int y = 0; y < original[0]->GetHeight(); y++){
            Color xColor(0,0,0,1);
            Color yColor(0,0,0,1);
            for(int i = 0; i < 3; i++){
                for(int j = 0; j < 3; j++){
                    Color newX(0,0,0,1);
                    Color newY(0,0,0,1);
                    newX = original[0]->GetPixel(x+i-size/2, y+j-size/2);
                    newY = original[0]->GetPixel(x+i-size/2,y+j-size/2);
                    newX = newX * xkernel[i][j];
                    newY = newY * ykernel[i][j];
                    xColor = xColor + newX;
                    yColor = yColor + newY;
                }
            }

            Dx.SetPixel(x, y, xColor);
            Dy.SetPixel(x, y, yColor);
            if(xColor.Red() > 1){
                xColor.SetRed(1);
                xColor.SetGreen(1);
                xColor.SetBlue(1);
            }
            if(xColor.Red() < 0){
                xColor.SetRed(0);
                xColor.SetGreen(0);
                xColor.SetBlue(0);
            }
            if(yColor.Red() > 1){
                yColor.SetRed(1);
                yColor.SetGreen(1);
                yColor.SetBlue(1);
            }
            if(yColor.Red() < 0){
                yColor.SetRed(0);
                yColor.SetGreen(0);
                yColor.SetBlue(0);
            }
            xColor.SetAlpha(1);
            yColor.SetAlpha(1);
            Ix.SetPixel(x, y, xColor);
            Iy.SetPixel(x, y, yColor);
            
         }
    }

    for(int i=0; i<Dx.GetWidth(); i++) {
        for(int j=0; j<Dy.GetHeight(); j++) {
            float xtemp = Dx.GetPixel(i, j).Red();
            float ytemp = Dy.GetPixel(i, j).Red();
            // if(xtemp > 1){
            //     xtemp = 1;
            // }
            // if(ytemp > 1){
            //     ytemp = 1;
            // }
            float varArcTan = GetArcTan(xtemp, ytemp);
            Color ArcTanColor(varArcTan,varArcTan,varArcTan, 1);
            // if( ArcTanColor.Red() > 1){
            //         ArcTanColor.SetRed(1);
            //         ArcTanColor.SetGreen(1);
            //         ArcTanColor.SetBlue(1);
            // }
            // if( ArcTanColor.Red() < 0){
            //         ArcTanColor.SetRed(1);
            //         ArcTanColor.SetGreen(1);
            //         ArcTanColor.SetBlue(1);
            // }
            direction.SetPixel( i, j, ArcTanColor);
        }
    }

    for(int i = 0; i < Ix.GetWidth(); i++){
        for(int j = 0; j < Ix.GetHeight(); j++){
            float xtemp = Ix.GetPixel(i, j).Red();
            float ytemp = Iy.GetPixel(i, j).Red();
            float varHypot = GetHypot(xtemp, ytemp);
            Color HypotColor(varHypot, varHypot, varHypot, 1);
            intensity.SetPixel(i, j, HypotColor);
        }
    }

    *filtered[0] = intensity;
    *filtered[1] = direction;
    
}
float SobelFilter::GetHypot(float Ix, float Iy){
        float temp = sqrt(Ix*Ix + Iy*Iy);
        return temp;
}

float SobelFilter::GetArcTan(float Ix, float Iy){
    float temp = atan2(Iy, Ix);
    return temp;
    
}
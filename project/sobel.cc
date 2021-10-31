#include "sobel.h"
#include "color.h"
#include <math.h>
#include <cmath>


void SobelFilter::Apply(std::vector<Image*> original, std::vector<Image*> filtered){
    *filtered[0] = *original[0];
    *filtered[1] = *original[0];
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
    for(int i = 0; i < Ix.GetWidth(); i++){
        for(int j = 0; j < Ix.GetHeight(); j++){
            float xtemp = Dx.GetPixel(i, j).Red();
            float ytemp = Dy.GetPixel(i, j).Red();
            if(xtemp > 1){
                xtemp = 1;
            }
            if(ytemp > 1){
                ytemp = 1;
            }
            float varArcTan = GetArcTan(xtemp, ytemp);
            xtemp = Ix.GetPixel(i, j).Red();
            ytemp = Iy.GetPixel(i, j).Red();
            float varHypot = GetHypot(xtemp, ytemp);
            Color ArcTanColor(varArcTan,varArcTan,varArcTan, 1);
            Color HypotColor(varHypot, varHypot, varHypot, 1);
                if( ArcTanColor.Red() > 1){
                        ArcTanColor.SetRed(1);
                        ArcTanColor.SetGreen(1);
                        ArcTanColor.SetBlue(1);
                }
                if( ArcTanColor.Red() < 0){
                        ArcTanColor.SetRed(1);
                        ArcTanColor.SetGreen(1);
                        ArcTanColor.SetBlue(1);
                }
            direction.SetPixel( i, j, ArcTanColor);
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
    //std::cout<<"This is Ix: "<<Ix<<"This is Iy: "<<Iy<<std::endl;
    float temp = atan2(Iy, Ix);
    // if(temp > 1){
    //     temp = 1;
    // }
    // if(temp < 0){
    //     temp = 0;
    // }
    //temp = temp + M_PI/2;
    //temp = temp / M_PI;
    //temp = temp * 255.0;
    //std::cout<<temp<<std::endl;
    return temp;
    
}
// void SobelFilter::IntensityConv(const Image& original, Image& filtered){
//     float xkernel[3][3] = {{-1,0,1}, {-2,0,2}, {-1,0,1}};
//     float ykernel[3][3] = {{1,2,1}, {0,0,0}, {-1,-2,-1}};
//     int size = 3;
//     for(int x = 0; x < original[0]->GetWidth(); x++){
//         for(int y = 0; y < original[0]->GetHeight(); y++){
//             Color xColor(0,0,0,1);
//             Color yColor(0,0,0,1);
//             for(int i = 0; i < 3; i++){
//                 for(int j = 0; j < 3; j++){
//                     //if(i < original[0]->GetWidth() | j < original[0]->GetHeight() | i > -1 | j > -1){
//                     Color newX(0,0,0,1);
//                     Color newY(0,0,0,1);
//                     newX = original[0]->GetPixel(x+i-size/2, y+j-size/2);
//                     //std::cout<<newX.getRed()<<std::endl;
//                     newY = original[0]->GetPixel(x+i-size/2,y+j-size/2);
//                     newX = newX * xkernel[i][j];
//                     newY = newY * ykernel[i][j];
//                     xColor = xColor + newX;
//                     yColor = yColor + newY;
//                     //std::cout<<xColor.getRed()<<std::endl;
//                     //}
//                 }
//             }
//             //std::cout<<"int x: "<<x<<"int y: "<<y<<std::endl;
//             //std::cout<<xColor.getAlpha()<<std::endl;
//             if(xColor.getRed() > 1){
//                 xColor.setRed(1);
//                 xColor.setGreen(1);
//                 xColor.setBlue(1);
//             }
//             if(xColor.getRed() < 0){
//                 xColor.setRed(0);
//                 xColor.setGreen(0);
//                 xColor.setBlue(0);
//             }
//             if(yColor.getRed() > 1){
//                 yColor.setRed(1);
//                 yColor.setGreen(1);
//                 yColor.setBlue(1);
//             }
//             if(yColor.getRed() < 0){
//                 yColor.setRed(0);
//                 yColor.setGreen(0);
//                 yColor.setBlue(0);
//             }
//             xColor.setAlpha(1);
//             yColor.setAlpha(1);
//             //std::cout<<"This is xColor: "<<xColor.getRed()<<std::endl;
//             Ix.SetPixel(x, y, xColor);
//             Iy.SetPixel(x, y, yColor);



// //             //int G = (int)sqrt((Ix * Ix) + (Iy * Iy));
// //             // int theta = atan(Ix, Iy);
            
//         }
//     }
// //     void SobelFiler::DirectionConv(std::vector<Image*> original, std::vector<Image*> filtered){
// //         float xkernel[3][3] = {{-1,0,1}, {-2,0,2}, {-1,0,1}};
// //         float ykernel[3][3] = {{1,2,1}, {0,0,0}, {-1,-2,-1}};
// //         int size = 3;
// //         for(int x = 0; x < original[0]->GetWidth(); x++){
// //             for(int y = 0; y < original[0]->GetHeight(); y++){
// //                 Color xColor(0,0,0,1);
// //                 Color yColor(0,0,0,1);
// //                 for(int i = 0; i < 3; i++){
// //                     for(int j = 0; j < 3; j++){
// //                         //if(i < original[0]->GetWidth() | j < original[0]->GetHeight() | i > -1 | j > -1){
// //                         Color newX(0,0,0,1);
// //                         Color newY(0,0,0,1);
// //                         newX = original[0]->GetPixel(x+i-size/2, y+j-size/2);
// //                         //std::cout<<newX.getRed()<<std::endl;
// //                         newY = original[0]->GetPixel(x+i-size/2,y+j-size/2);
// //                         newX = newX * xkernel[i][j];
// //                         newY = newY * ykernel[i][j];
// //                         xColor = xColor + newX;
// //                         yColor = yColor + newY;
// //                         //std::cout<<xColor.getRed()<<std::endl;
// //                         //}
// //                     }
// //                 }
// //                 //std::cout<<"int x: "<<x<<"int y: "<<y<<std::endl;
// //                 //std::cout<<xColor.getAlpha()<<std::endl
// //                 xColor.setAlpha(1);
// //                 yColor.setAlpha(1);
// //                 //std::cout<<"This is xColor: "<<xColor.getRed()<<std::endl;
// //                 Ix.SetPixel(x, y, xColor);
// //                 Iy.SetPixel(x, y, yColor);



// //     //             //int G = (int)sqrt((Ix * Ix) + (Iy * Iy));
// //     //             // int theta = atan(Ix, Iy);
                
// //             }
// //         }
//   //   }

// //}
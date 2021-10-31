#include "filter.h"
#ifndef SOBEL_FILTER_H_
#define SOBEL_FILTER_H_

class SobelFilter : public Filter {
    public:
    SobelFilter(){};
    ~SobelFilter(){}
    void Apply(std::vector<Image*> original, std::vector<Image*> filtered);
    //char *Gaussian_Kernel(float size, float signma);
    float GetHypot(float Ix, float Iy);
    float GetArcTan(float Ix, float Iy);
    void DirectionConv(Image& image, Image& image1);
    void IntensityConv(Image& image, Image& image1);
    
};
#endif
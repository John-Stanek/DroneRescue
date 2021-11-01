#include "filter.h"
#ifndef GAUSSIAN_BLURFILTER_H_
#define GAUSSIAN_BLURFILTER_H_

class GaussianBlurFilter : public Filter {
    public:
    GaussianBlurFilter();
    GaussianBlurFilter(float sigma, int size);
    //GaussianBlurFilter(const GaussianBlurFilter& sigma);
    ~GaussianBlurFilter(){}
    void Apply(std::vector<Image*> original, std::vector<Image*> filtered);
    //char *Gaussian_Kernel(float size, float signma);

    private:
        float sigma;
        int size;
     
};
#endif
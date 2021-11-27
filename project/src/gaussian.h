#include "filter.h"
#ifndef GAUSSIAN_BLURFILTER_H_
#define GAUSSIAN_BLURFILTER_H_

class GaussianBlurFilter : public Filter {
    public:
    /**
     * @brief Construct a new Gaussian Blur Filter object
     * 
     */
    GaussianBlurFilter();
    /**
     * @brief Construct a new Gaussian Blur Filter object with a size and sigma
     * 
     * @param sigma 
     * @param size 
     */
    GaussianBlurFilter(float sigma, int size);
    /**
     * @brief Destroy the Gaussian Blur object
     * 
     */

    ~GaussianBlurFilter(){}
    /**
     * @brief Appply manipulates the image runs the gaussian blur on the image
     * 
     * @param original 
     * @param filtered 
     */
    void Apply(std::vector<Image*> original, std::vector<Image*> filtered);
   

    private:
    /**
     * @brief Two private variable size and sigma. Size is how large the kernel is.
     * 
     */
        float sigma;
        int size;
     
};
#endif

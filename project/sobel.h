#include "filter.h"
#ifndef SOBEL_FILTER_H_
#define SOBEL_FILTER_H_

class SobelFilter : public Filter {
    public:
    /**
     * @brief Construct a new Sobel Filter object
     * 
     */
    SobelFilter(){};
    /**
     * @brief Destroy the Sobel Filter object
     * 
     */
    ~SobelFilter(){}
    /**
     * @brief Appply manipulates the image and creates two output images
     * 
     * @param original 
     * @param filtered 
     * 
     */
    void Apply(std::vector<Image*> original, std::vector<Image*> filtered);
    /**
     * @brief Get the Hypotonuse of the image color values
     * @param Ix
     * @param Iy
     * @return float
     * 
     */
    float GetHypot(float Ix, float Iy);
    /**
     * @brief Get the Arc Tan of the image color values
     * 
     * @param Ix 
     * @param Iy 
     * @return float 
     */
    float GetArcTan(float Ix, float Iy);


    
};
#endif

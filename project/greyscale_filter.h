#ifndef GREY_SCALE_FILTER_H_
#define GREY_SCALE_FILTER_H_

#include "filter.h"
/**
 * @brief The class for the grey scale filter.
 *      Used to apply a grey scale filter to an image.
 *      Inherits from Filter and has no child classes. 
 */

class GreyScaleFilter : public Filter {
public:
    /**
     * @brief Overrides the base class method and applies the greyscale fitler to an image.
     * 
     * @param original - a vector of images.
     * @param filtered - a vector of images with the grey scale filter applied.
     */
    
    void Apply(std::vector<Image*> original, std::vector<Image*> filtered);
};

#endif
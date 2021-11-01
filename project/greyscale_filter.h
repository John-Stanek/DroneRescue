#ifndef GREY_SCALE_FILTER_H_
#define GREY_SCALE_FILTER_H_

#include "filter.h"
<<<<<<< HEAD

class GreyScaleFilter : public Filter {
public:
=======
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
    
>>>>>>> 7e2e8d21cf6e8d747e5349630cdd94e55e4699aa
    void Apply(std::vector<Image*> original, std::vector<Image*> filtered);
};

#endif
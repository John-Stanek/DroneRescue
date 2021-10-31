#ifndef MEAN_BLUR_FILTER_H
#define MEAN_BLUR_FILTER_H

#include <iostream>
#include "filter.h"

/**
 * @brief The class for the mean blur filter.
 *      Used to apply a mean blur filter to an image.
 *      Inhereits from Filter and has no child classes.
 * 
 */

class MeanBlurFilter : public Filter {
public:

    /**
     * @brief Overrides the base class method and applies the mean blur filter to an image
     * 
     * @param original - a vector of images.
     * @param filtered - a vector of images with the mean blur filter applied.
     */

    void Apply(std::vector<Image*> original, std::vector<Image*> filtered);
};

#endif
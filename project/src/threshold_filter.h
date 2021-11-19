#ifndef THRESHOLD_FILTER_H
#define THRESHOLD_FILTER_H

#include <iostream>
#include "filter.h"

/**
 * @brief The class for the threhold filter.
 *      Used to apply the threshold filter to an image.
 *      Inherits from Filter and has no child classes.
 * 
 */

class ThresholdFilter : public Filter {
private:
    float threshold;
public:

    /**
     * @brief Construct a new Threshold Filter object
     * 
     * @param threshold - a decimal value set the threshold to.
     */

    ThresholdFilter(float threshold);

    /**
     * @brief Overrides the base class method and applies the threshold filter to an image.
     * 
     * @param original - a vector of images.
     * @param filtered - a vector of images each of which has been applied the threshold filter.
     */

    void Apply(std::vector<Image*> original, std::vector<Image*> filtered);
};

#endif
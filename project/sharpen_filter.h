#ifndef SHARPEN_FILTER_H
#define SHARPEN_FILTER_H

#include "filter.h"

/**
 * @brief The Sharpen Filter class
 *
 *   Inherits from the Filter class. Has no subclasses.
 * 
 */
class SharpenFilter : public Filter {
public:

    /**
     * @brief Applies the Sharpen filter to the Image* vector original
     * @return Adds the filtered images to the Image* vector filtered
     * @param original - a Image* vector of input images
     * @param filtered - a Image* vector of the filtered input images
     */
    void Apply(std::vector<Image*> original, std::vector<Image*> filtered);
};


#endif
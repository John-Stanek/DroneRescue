#ifndef HYSTERESIS_FILTER_H
#define HYSTERESIS_FILTER_H

#include "filter.h"

/**
 * @brief The class for the hysterisis filter.
 *   Inherits from the Filter class.
 *   Has no child classes.
 *   
 */

class HysteresisFilter : public Filter {
public:

    /**
     * @brief Applies the hysterisis filter to Images. 
     * @param original - a vector of images for the hystereis filter to be applied.
     * @param filtered - the resulting vector of filtered images.
     */

    void Apply(std::vector<Image*> original, std::vector<Image*> filtered);
};

#endif

#ifndef DOUBLE_THRESHOLD_FILTER_H
#define DOUBLE_THRESHOLD_FILTER_H

#include "filter.h"

/**
 * @brief The Double Threshold Filter class
 *
 *   Inherits from the Filter class.
 *   This class has no subclasses
 * 
 */

class DoubleThresholdFilter : public Filter {
private:
    float strong_threshold_ratio;
    float weak_threshold_ratio;
public:

    /**
     * @brief Construct a new Double Threshold Filter object
     * @return Returns an object of the type DoubleThresholdFilter.
     * @param strong - a float value for the strong threshold ratio. 
     * @param weak - a float value for the weak threshold ratio.
     */

    DoubleThresholdFilter(float strong, float weak);

    /**
     * @brief Applies the double threshold filter to the vector of Images original
     * @return Returns a vector of images that were applied the double threshold filter
     * @param original - a vector of input images
     * @param filtered - a vector of the filtered input images
     */

    void Apply(std::vector<Image*> original, std::vector<Image*> filtered);
};

#endif

#ifndef FILTER_H_
#define FILTER_H_

#include <iostream>
#include <vector>
#include "image.h"

<<<<<<< HEAD
class Filter {
public:
=======
/**
 * @brief This is the abstract Filter class which handles all types of image processing filters.
 *  All filters inherit from this class.
 * 
 */

class Filter {
public:
    /**
     * @brief A pure virtual function to be overriden by child classes to apply a 
     *   specific filter to an image.
     * 
     * @param original - A vector of images to be filtered.
     * @param filtered - A vector of images after filter has been applied.
     */
>>>>>>> 7e2e8d21cf6e8d747e5349630cdd94e55e4699aa
    virtual void Apply(std::vector<Image*> original, std::vector<Image*> filtered);
};

#endif
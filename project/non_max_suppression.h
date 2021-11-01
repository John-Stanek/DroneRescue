/**
 * @file non_max_suppression.h
 *
 * 
 */

#ifndef NMS_Filter
#define NMS_Filter

/*******************************************************************************
 * Includes
 ******************************************************************************/
 
#include <iostream>
#include "filter.h"

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The class used to apply the Non max suppression filter. Inherits from filter class.
 *
 */
 
class NonMaxSuppression : public Filter {
public:
/**
  * @brief Apply Non max suppression filter to original image and save end result to filtered variable.
  *
  * @return Nothing.
  */
    void Apply(std::vector<Image*> original, std::vector<Image*> filtered);
};

#endif //NMS_Filter

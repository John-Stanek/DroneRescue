/**
 * @file white_noise.h
 *
 * @copyright 2021 3081W, All rights reserved.
 */
 
#ifndef WHITE_NOISE
#define WHITE_NOISE

/*******************************************************************************
 * Includes
 ******************************************************************************/


#include "filter.h"

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief Class used for applying the white noise filter to an image.
 *
 */

class WhiteNoise : public Filter {
	public:
/**
  * @brief Applies the filter to original image and saves it in filtered.
  *
  * @return Nothing.
  */
		void Apply(std::vector<Image*> original, std::vector<Image*> filtered);
};

#endif //WHITE_NOISE

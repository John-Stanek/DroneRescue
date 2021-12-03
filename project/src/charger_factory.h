#ifndef CHARGER_FACTORY
#define CHARGER_FACTORY

#include <iostream>
#include <vector>
#include "factory.h"

/**
 * @brief This is the abstract Filter class which handles all types of image processing filters.
 *  All filters inherit from this class.
 * 
 */

class ChargerFactory : public Factory {
public:

	ChargerFactory();
	~ChargerFactory();
    /**
     * @brief A pure virtual function to be overriden by child classes to apply a 
     *   specific filter to an image.
     * 
     * @param original - A vector of images to be filtered.
     * @param filtered - A vector of images after filter has been applied.
     */
    Entity* CreateEntity(picojson::object &entityData);
    
};

#endif

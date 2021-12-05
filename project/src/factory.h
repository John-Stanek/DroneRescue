#ifndef FACTORY
#define FACTORY

#include <iostream>
#include <vector>
#include "entity.h"
#include "picojson.h"
#include "drone.h"

/**
 * @brief This is the abstract Factory class which handles all types of entity creation
 *  All factories inherit from this class.
 * 
 */
 
class Factory {
public:
	
	/**
	* @brief a destructor to remove everything from the factory when it goes out of scope
	*/
    virtual ~Factory(){};
    
    /**
     * @brief A virtual function to be overriden by child classes to apply a 
     *   create a specific entity type
     * 
     * @param entityData - A reference to a picojson::object that contains data to be used for how an entity is created.
     * @return A newly created entity object
     */
     
    virtual Entity* CreateEntity(picojson::object &entityData){return NULL;};
    
    
};

#endif

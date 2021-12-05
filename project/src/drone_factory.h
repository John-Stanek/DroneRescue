#ifndef DRONE_FACTORY
#define DRONE_FACTORY

#include <iostream>
#include <vector>
#include "factory.h"

/**
 * @brief This is the DroneFactory class which handles entity creation for drone type entities
 * 
 */


class DroneFactory : public Factory {
public:
	/**
	* @brief a constructor to intitalize everything in the drone factory when it is created
	*/
	DroneFactory();
	
	/**
	* @brief a destructor to remove everything from the drone factory when it goes out of scope
	*/
	~DroneFactory();
    /**
     * @brief A function to be create a new entity of type drone
     * 
     * @param entityData - A reference to a picojson::object that contains data to be used for how an entity is created.
     * @return A newly created drone object
     */
    Entity* CreateEntity(picojson::object &entityData, ICameraController& cameraController);
    
};

#endif

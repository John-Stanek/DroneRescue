#ifndef ROBOT_FACTORY
#define ROBOT_FACTORY

#include <iostream>
#include <vector>
#include "factory.h"

/**
 * @brief This is the RobotFactory class which handles entity creation for robot type entities
 * 
 */

class RobotFactory : public Factory {
public:
	
	/**
	* @brief a constructor to intitalize everything in the robot factory when it is created
	*/
	RobotFactory();
	
	/**
	* @brief a destructor to remove everything from the robot factory when it goes out of scope
	*/
	~RobotFactory();
     /**
     * @brief A function to be create a new entity of type robot
     * 
     * @param entityData - A reference to a picojson::object that contains data to be used for how an entity is created.
     * @return A newly created robot object
     */
    Entity* CreateEntity(picojson::object &entityData, ICameraController& cameraController);
    
};

#endif

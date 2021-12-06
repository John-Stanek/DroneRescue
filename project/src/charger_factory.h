#ifndef CHARGER_FACTORY
#define CHARGER_FACTORY

#include <iostream>
#include <vector>
#include "factory.h"

/**
 * @brief This is the ChargerFactory class which handles entity creation for recharge station type entities
 * 
 */

class ChargerFactory : public Factory {
public:
	/**
	* @brief a constructor to intitalize everything in the charger factory when it is created
	*/
	ChargerFactory();
	
	/**
	* @brief a destructor to remove everything from the charger factory when it goes out of scope
	*/
	~ChargerFactory();
    /**
     * @brief A function to be create a new entity of type charger
     * 
     * @param entityData - A reference to a picojson::object that contains data to be used for how an entity is created.A camera controller object to deal with processing images and taking pictures.
     * @return A newly created charger object
     */
    Entity* CreateEntity(picojson::object &entityData, ICameraController& cameraController);
    
     /**
     * @brief A function to be create a new entity of type charger
     * 
     * @param entityData - A reference to a picojson::object that contains data to be used for how an entity is created.
     * @return A newly created charger object
     */
    Entity* CreateEntity(picojson::object &entityData);
    
};

#endif

#ifndef HOSPITAL_FACTORY
#define HOSPITAL_FACTORY

#include <iostream>
#include <vector>
#include "factory.h"

/**
 * @brief This is the HospitalFactory class which handles entity creation for hospital type entities
 * 
 */


class HospitalFactory : public Factory {
public:

	/**
	* @brief a constructor to intitalize everything in the hospital factory when it is created
	*/
	HospitalFactory();
	
	/**
	* @brief a destructor to remove everything from the hospital factory when it goes out of scope
	*/
	~HospitalFactory();
    /**
     * @brief A function to be create a new entity of type hospital
     * 
     * @param entityData - A reference to a picojson::object that contains data to be used for how an entity is created.A camera controller object to deal with processing images and taking pictures.
     * @return A newly created hospital object
     */
    Entity* CreateEntity(picojson::object &entityData, ICameraController& cameraController);
    
    /**
     * @brief A function to be create a new entity of type hospital
     * 
     * @param entityData - A reference to a picojson::object that contains data to be used for how an entity is created.
     * @return A newly created hospital object
     */
    Entity* CreateEntity(picojson::object &entityData);
};

#endif

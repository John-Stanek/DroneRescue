#ifndef COMP_FACTORY
#define COMP_FACTORY

#include <iostream>
#include <vector>
#include "factory.h"
#include "drone_factory.h"
#include "robot_factory.h"
#include "charger_factory.h"
#include "hospital_factory.h"
#include "entity.h"

/**
 * @brief This is the CompositeFactory class which handles entity creation for all entity types by using the composite factory pattern. Other Files only need to know about this class and it will do all of the work to create any type of entity.
 * 
 */

class CompositeFactory : public Factory {	
	
public:

	/**
	* @brief a constructor to intitalize everything in the composite factory when it is created
	*/
    CompositeFactory();
    
    /**
	* @brief a destructor to remove everything from the composite factory when it goes out of scope
	*/
    ~CompositeFactory();
    /**
     * @brief A function to be create a new entity of any type
     * 
     * @param entityData - A reference to a picojson::object that contains data to be used for how an entity is created.
     * @return A newly created entity object
     */
    Entity* CreateEntity(picojson::object &entityData);
    
    /**
     * @brief A function to add factories to a factory list
     * 
     * @param factory - A pointer to a factory type factory to be added to a list
     */
    void AddFactory(Factory* factory);
    
   
   /**
     * @brief Four factory type factories to be used by composite factory. One for each type: DroneFactory, RobotFactory, RechargeFactory, and HospitalFactory.
     * 
     */
    Factory* droneFactory;
    Factory* robotFactory;
    Factory* rechargeFactory;
    Factory* hospitalFactory;
    
    
    
};

#endif

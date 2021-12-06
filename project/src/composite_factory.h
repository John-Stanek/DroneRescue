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
 * @brief This is the abstract Filter class which handles all types of image processing filters.
 *  All filters inherit from this class.
 * 
 */

class CompositeFactory : public Factory {	
	
public:


    CompositeFactory();
    ~CompositeFactory();
    /**
     * @brief A pure virtual function to be overriden by child classes to apply a 
     *   specific filter to an image.
     * 
     * @param original - A vector of images to be filtered.
     * @param filtered - A vector of images after filter has been applied.
     */
    Entity* CreateEntity(picojson::object &entityData, ICameraController& cameraController);
    
    void AddFactory(Factory* factory);
    
   
    Factory* droneFactory;
    Factory* robotFactory;
    Factory* rechargeFactory;
    Factory* hospitalFactory;
    
    
    
};

#endif

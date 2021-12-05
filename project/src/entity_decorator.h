#ifndef DEC_H
#define DEC_H

#include <iostream>
#include <vector>
#include "entity.h"
#include "drone.h"


/**
 * @brief The EntityDecorator Class represents a class to be used to create decorator patterns for entity objects
 * 
 */
class EntityDecorator : public Entity{
protected:
    /**
     * @brief An entity object to be given new attributes
     */
    Entity *ent;
public:

    /**
         * @brief Construct a new EntityDecorator object using an existing entity object
         * @param ent - An Entity pointer of an existing object
         * @return
         *   Returns a new instance of a the EntityDecorator class.
         */
	EntityDecorator(Entity *ent) : ent(ent) {}

    /**
    * @brief Update the existing entity object
    */
    void Update(){
        ent->Update(0.01);
    }
    /**
    * @brief Get the position of the entity object
    * @param index - The index of the pos array that is requested
    * @return
    *   A position value of a given index as type double
    */
    double GetPosition(int index){
        return ent->GetPosition(index);
    }
	
};

#endif

/**
 * @file Entity.h
 *
 * @copyright 2021 3081W, All rights reserved.
 */

#ifndef ENTITY_H
#define ENTITY_H

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <iostream>
#include <string>
#include <vector>
#include <chrono>

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The base class for all entities.
 *
 *  All other entities inherit from this class.
 *  Sub Classes of this class include Drone, Tree, and Robot.
 *  
 */
class Entity
{ 
    public:

      Entity();

      Entity(std::vector<double>position, std::vector<double>velocity, std::string name = "Unknown Entity");

      ~Entity();

      void update(double dt);

      void report();

      double getLifeTime() const;
      /**
       * @brief Sets position of an entity to the argument vector position.
       * 
       * @returns Updates the entity's position and returns nothing.
       */
      void setPosition(std::vector<double> position);

      void setVelocity(std::vector<double> velocity);

      std::string getName() const;

      int getID() const;

      static int getEntityCount();
    
    private:

      std::string name;
      std::vector<double> position;
      std::vector<double> velocity;

      std::chrono::time_point<std::chrono::system_clock> startTime;
      std::chrono::time_point<std::chrono::system_clock> endTime;

      int id;
      static int count;  // global count, used to set ID for new instances
  
};

#endif
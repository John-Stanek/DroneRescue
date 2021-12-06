#ifndef SIMULATION_H
#define SIMULATION_H

#include "entity.h"
#include "factory.h"
#include "composite_factory.h"
#include "camera_controller.h"
#include "entity.h"

/**
 * @brief The Simulation Class serves as the facade for the drone search and rescue simulation.
 *   All access to the simulation from the web app is made through this facade.
 */
 
class Simulation {
	public:
		/**
		 * @brief Constructs a new Simulation object
		 * @return
		 *   Returns a new instance of the Simulation class.
		 */
		Simulation();
		
		/**
		 * @brief The destructor for the Simulation class. Deletes the entities vector
		 * and the composite factory.
		 */
		~Simulation();
		
		/**
		 * @brief Updates all entities within the simulation. Update functions
		 * differently according to the type of entity.
		 */
		void Update(double dt, double arrows[4], bool moves[2]);
		
		/**
		 * @brief Called after all entities are updated to send updated entity information
		 * to the web server.
		 */
		void FinishUpdate(picojson::object& returnValue);
		
		/**
		 * @brief Creates a new entity within the simulation. The new entity is added to
		 * the entities vector. Uses the composite factory within the Simulation.
		 * Adds a cameraController to the entity.
		 */
		void CreateEntity(picojson::object& entityData, ICameraController& cameraController);
		
		/**
		 * @brief Alternative version of CreateEntity that does not add a cameraController
		 * to the new entity. Used for testing.
		 */
		void CreateEntity(picojson::object& entityData);
		
		/**
		 * @brief Returns the entity* within the entities vector at a given index
		 * @return
		 * 	Returns the entity* at the given index
		 */
		Entity* GetEntity(int index){return entities[index];}
		
	private:
	
		/**
		 * @brief A vector of all the entites within the simulation.
		 */
		std::vector<Entity*> entities;
		
		/**
		 * @brief A composite factory used to create all of the entities
		 * within the simulation. Contains drone, recharge station,
		 * and robot factories.
		 */
		CompositeFactory* composite_factory;
};
	
#endif

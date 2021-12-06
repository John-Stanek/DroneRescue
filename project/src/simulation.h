#ifndef SIMULATION_H
#define SIMULATION_H

#include "entity.h"
#include "factory.h"
#include "composite_factory.h"
#include "camera_controller.h"
#include "entity.h"

class Simulation {
	public:
		Simulation();
		~Simulation();
		void Update(double dt, double arrows[4], bool moves[2]);
		void FinishUpdate(picojson::object& returnValue);
		void CreateEntity(picojson::object& entityData, ICameraController& cameraController);
		void CreateEntity(picojson::object& entityData);
		Entity* GetEntity(int index){return entities[index];}
	private:
		std::vector<Entity*> entities;
		CompositeFactory* composite_factory;
};
	
#endif

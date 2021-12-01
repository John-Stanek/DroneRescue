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
		void Update(double dt);
		void FinishUpdate(picojson::object& returnValue);
		void CreateEntity(picojson::object& entityData, ICameraController& cameraController);
	private:
		std::vector<Entity*> entities;
		CompositeFactory composite_factory;
};
	
#endif

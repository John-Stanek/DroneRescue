#ifndef SIMULATION_H
#define SIMULATION_H

class Simulation {
	public:
		Simulation();
		~Simulation();
		Update(double dt);
		CreateEntity(picojson::object& entityData, ICameraController& cameraController);
	private:
		std::vector<Entity*> entities;
};
	
#endif

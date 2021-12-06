#include "simulation.h"

Simulation::Simulation() {
	entities = std::vector<Entity*>();
	composite_factory = new CompositeFactory();
}


Simulation::~Simulation() {
	delete composite_factory;
	for (Entity* entity : entities) {
		delete entity;
	}
}

void Simulation::Update(double dt, double arrows[4], bool moves[2]) {
	//arrows stores keyboard input for manual movement
	//moves stores the movement option to be used
    for (Entity* entity : entities) {
		entity->Update(dt, arrows, moves);
	}
}

void Simulation::FinishUpdate(picojson::object& returnValue) {
	
	// Called after all updating is done.
	// Loops through all entities to update their position and direction
    for (Entity* entity : entities) {
		picojson::object entity_json;
		entity_json["entityId"] = picojson::value(entity->GetID());
		
		// Save the position as an array
		picojson::array pos;
		pos.push_back(picojson::value(entity->GetPos()[0]));
		pos.push_back(picojson::value(entity->GetPos()[1]));
		pos.push_back(picojson::value(entity->GetPos()[2]));
		entity_json["pos"] = picojson::value(pos);

		// Save the direction as an array
		picojson::array dir;
		dir.push_back(picojson::value(entity->GetDir()[0]));
		dir.push_back(picojson::value(entity->GetDir()[1]));
		dir.push_back(picojson::value(entity->GetDir()[2]));
		entity_json["dir"] = picojson::value(dir);
		// Send the compile picojson data to the UI in the returnValue variable
		returnValue["entity"+std::to_string(int(entity->GetID()))] = picojson::value(entity_json);
	}
}

void Simulation::CreateEntity(picojson::object& entityData, ICameraController& cameraController) {
	std::cout << (picojson::value)entityData << std::endl;
	entities.push_back(composite_factory->CreateEntity(entityData, cameraController));
}

void Simulation::CreateEntity(picojson::object& entityData) {
	std::cout << (picojson::value)entityData << std::endl;
	entities.push_back(composite_factory->CreateEntity(entityData));
}

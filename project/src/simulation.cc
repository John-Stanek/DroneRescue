#include "simulation.h"

Simulation::Simulation() {
}


Simulation::~Simulation() {
}

void Simulation::Update(double dt) {
	//// Below is an example of how to use keyboard commands:
    //deleteThisDrone.SetJoystick(
        //IsKeyDown("ArrowRight") ? 1 : (IsKeyDown("ArrowLeft") ? -1 : 0),
        //IsKeyDown("w") ? 1 : (IsKeyDown("s") ? -1 : 0),
        //IsKeyDown("ArrowUp") ? -1 : (IsKeyDown("ArrowDown") ? 1 : 0),
        //IsKeyDown("a") ? 1 : (IsKeyDown("d") ? -1 : 0)
    //);
    
    //// Below is an example of how to update an entity.  
    //// This code should be in the simulation facade, not here!
    //deleteThisDrone.Update(dt);
    
    for (Entity* entity : entities) {
		entity->Update(dt);
	}
}

void Simulation::FinishUpdate(picojson::object& returnValue) {
	printf("starting FinishUpdate");
	
	// Called after all updating is done.

    // Below is an example of how to send the position and direction to the UI.  
    // In general you will want to loop through entities that have changed to update
    // their position and direction:
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
		returnValue["entity"+std::to_string(entity->GetID())] = picojson::value(entity_json);
	}
	printf("ending FinishUpdate");
}

void Simulation::CreateEntity(picojson::object& entityData, ICameraController& cameraController) {
	entities.push_back(composite_factory.CreateEntity(entityData));
}

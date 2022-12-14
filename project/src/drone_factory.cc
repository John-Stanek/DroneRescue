#include "drone_factory.h"
#include "factory.h"
#include <fstream>

DroneFactory::DroneFactory(){}
DroneFactory::~DroneFactory(){}
Entity* DroneFactory::CreateEntity(picojson::object &entityData, ICameraController& cameraController){

	//parse json object aka entityData
    
	if ((entityData["name"].get<std::string>().compare (0, 5, "drone") == 0) ||
	    (entityData["name"].get<std::string>().compare (0, 12, "rescue drone") == 0)) {
		//if entity is drone or rescue drone:
		//set all appropriate fields of drone from json data

    	Drone* newDrone = new Drone(cameraController);
    	newDrone->SetName(entityData["name"].get<std::string>());

	    newDrone->SetID(entityData["entityId"].get<double>());
	    if(entityData["speed"].is<double>()){
	    	newDrone->SetSpeed(entityData["speed"].get<double>());
	    }
	    

	    // Get the position as an arra\n");
	    if(!entityData["position"].is<picojson::array>()){
	    	printf("Error converting to array\n");
	    	exit(1);
	    }
	    picojson::array position = entityData["position"].get<picojson::array>();

	    newDrone->SetX(position[0].get<double>());
	    newDrone->SetY(position[1].get<double>());
	    newDrone->SetZ(position[2].get<double>());

	    // Get the direction as an array
	    picojson::array dir = entityData["direction"].get<picojson::array>();
	    double temp[3];
	    temp[0] = dir[0].get<double>();
	    temp[1] = dir[1].get<double>();
	    temp[2] = dir[2].get<double>();
	    newDrone->SetDir(temp);
	    return newDrone;
	}
	return NULL;
}
Entity* DroneFactory::CreateEntity(picojson::object &entityData){

	//parse json object aka entityData

	if ((entityData["name"].get<std::string>().compare (0, 5, "drone") == 0) ||
	    (entityData["name"].get<std::string>().compare (0, 12, "rescue drone") == 0)) {
		//if entity is drone or rescue drone:
		//set all appropriate fields of drone from json data

    	Drone* newDrone = new Drone();
    	newDrone->SetName(entityData["name"].get<std::string>());

	    newDrone->SetID(entityData["entityId"].get<double>());
	    if(entityData["speed"].is<double>()){
	    	newDrone->SetSpeed(entityData["speed"].get<double>());
	    }
	    

	    // Get the position as an arra\n");
	    if(!entityData["position"].is<picojson::array>()){
	    	printf("Error converting to array\n");
	    	exit(1);
	    }
	    picojson::array position = entityData["position"].get<picojson::array>();

	    newDrone->SetX(position[0].get<double>());
	    newDrone->SetY(position[1].get<double>());
	    newDrone->SetZ(position[2].get<double>());

	    // Get the direction as an array
	    picojson::array dir = entityData["direction"].get<picojson::array>();
	    double temp[3];
	    temp[0] = dir[0].get<double>();
	    temp[1] = dir[1].get<double>();
	    temp[2] = dir[2].get<double>();
	    newDrone->SetDir(temp);
	    return newDrone;
	}
	return NULL;
}

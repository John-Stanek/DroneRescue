#include "drone_factory.h"
#include "factory.h"
#include <fstream>

DroneFactory::DroneFactory(){}
DroneFactory::~DroneFactory(){}
Entity* DroneFactory::CreateEntity(picojson::object &entityData){

	//parse json object aka entityData

    // Print out actual json:
    // picojson::value val(entityData);
    // std::cout << val.serialize() << std::endl;
    

    if (entityData["name"].get<std::string>() == "drone") {

    	Drone* newDrone = new Drone();
    	

	    newDrone->SetID(entityData["entityId"].get<double>());
	    newDrone->SetSpeed(entityData["speed"].get<double>());

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
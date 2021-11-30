#include "robot_factory.h"
#include "factory.h"
#include <fstream>

RobotFactory::RobotFactory(){}
RobotFactory::~RobotFactory(){}

Entity* RobotFactory::CreateEntity(picojson::object &entityData){

	//parse json object aka entityData

    // Print out actual json:
    // picojson::value val(entityData);
    // std::cout << val.serialize() << std::endl;


    if (entityData["name"].get<std::string>() == "robot") {
    	Robot* newRobot = new Robot();
    	
	    newRobot->SetID(entityData["entityId"].get<double>());

	    if(!entityData["position"].is<picojson::array>()){
	    	printf("Error converting to array\n");
	    	exit(1);
	    }
	    // Get the position as an array
	    picojson::array position = entityData["position"].get<picojson::array>();
	    newRobot->SetX(position[0].get<double>());
	    newRobot->SetY(position[1].get<double>());
	    newRobot->SetZ(position[2].get<double>());
	    return newRobot;
	}
	return NULL;
}

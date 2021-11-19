#include "compositedronefactory.h"
#include "dronefactory.h"
#include "factory.h"


DroneFactory::CreateEntity(picojson::object entityData){
	
	//parse json object aka entityData

    // Print out actual json:
    picojson::value val(entityData);
    std::cout << val.serialize() << std::endl;

    // Use your simulatin facade to create a new entity.
    // Below is an example on how to get data values from picojson.
    // The code should be in the factory, not here!
    if (entityData["name"].get<std::string>() == "drone") {
        deleteThisDrone.id = entityData["entityId"].get<double>();
        deleteThisDrone.speed = entityData["speed"].get<double>();

        // Get the position as an array
        picojson::array position = entityData["position"].get<picojson::array>();
        deleteThisDrone.pos[0] = position[0].get<double>();
        deleteThisDrone.pos[1] = position[1].get<double>();
        deleteThisDrone.pos[2] = position[1].get<double>();

        // Get the direction as an array
        picojson::array dir = entityData["direction"].get<picojson::array>();
        deleteThisDrone.dir[0] = dir[0].get<double>();
        deleteThisDrone.dir[1] = dir[1].get<double>();
        deleteThisDrone.dir[2] = dir[1].get<double>();
    }
	

	for(DroneFactory dfactory : factories){
		//type = ;;;

		Drone* drone = dfactory->Create(type);
		if(drone){
			return drone;
		}
		return NULL;
	}
	
}

AddFactory(DroneFactory factory){
	factories.push_back(factory);
}

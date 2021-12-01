#include "drone_factory.h"
#include "factory.h"

void Factory::CreateEntity(picojson::object entityData){
	
	//parse json object aka entityData

    // Print out actual json:
    picojson::value val(entityData);
    std::cout << val.serialize() << std::endl;

    // Use your simulatin facade to create a new entity.
    // Below is an example on how to get data values from picojson.
    // The code should be in the factory, not here!
    if (entityData["name"].get<std::string>() == "drone") {

	    newDrone.id = entityData["entityId"].get<double>();
	    newDrone.speed = entityData["speed"].get<double>();

	    // Get the position as an array
	    picojson::array position = entityData["position"].get<picojson::array>();
	    newDrone.pos[0] = position[0].get<double>();
	    newDrone.pos[1] = position[1].get<double>();
	    newDrone.pos[2] = position[1].get<double>();

	    // Get the direction as an array
	    picojson::array dir = entityData["direction"].get<picojson::array>();
	    newDrone.dir[0] = dir[0].get<double>();
	    newDrone.dir[1] = dir[1].get<double>();
	    newDrone.dir[2] = dir[1].get<double>();
	    
	    return newDrone;
	}
	return NULL;
}

#include "charger_factory.h"
#include "factory.h"

void Factory::CreateEntity(picojson::object entityData){
	
	//parse json object aka entityData

    // Print out actual json:
    picojson::value val(entityData);
    std::cout << val.serialize() << std::endl;

    // Use your simulatin facade to create a new entity.
    // Below is an example on how to get data values from picojson.
    // The code should be in the factory, not here!
    if (entityData["name"].get<std::string>() == "charger") {
    	
	    newCharger.id = entityData["entityId"].get<double>();

	    // Get the position as an array
	    picojson::array position = entityData["position"].get<picojson::array>();
	    newCharger.pos[0] = position[0].get<double>();
	    newCharger.pos[1] = position[1].get<double>();
	    newCharger.pos[2] = position[2].get<double>();
	    
	    return newCharger;
	}
	return NULL;
}

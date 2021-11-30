#include "hospital_factory.h"
#include "factory.h"

void Factory::CreateEntity(picojson::object entityData){
	
	//parse json object aka entityData

    // Print out actual json:
    picojson::value val(entityData);
    std::cout << val.serialize() << std::endl;

    // Use your simulatin facade to create a new entity.
    // Below is an example on how to get data values from picojson.
    // The code should be in the factory, not here!
    if (entityData["name"].get<std::string>() == "hospital") {
    	
	    newHospital.id = entityData["entityId"].get<double>();

	    // Get the position as an array
	    picojson::array position = entityData["position"].get<picojson::array>();
	    newHospital.pos[0] = position[0].get<double>();
	    newHospital.pos[1] = position[1].get<double>();
	    newHospital.pos[2] = position[1].get<double>();
	    
	    return newHospital;
	}
	return NULL;
}

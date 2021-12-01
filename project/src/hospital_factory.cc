#include "hospital_factory.h"
#include "factory.h"

HospitalFactory::HospitalFactory(){}
HospitalFactory::~HospitalFactory(){}

Entity* HospitalFactory::CreateEntity(picojson::object &entityData){

	//parse json object aka entityData

    // Print out actual json:
    // picojson::value val(entityData);
    // std::cout << val.serialize() << std::endl;

    if (entityData["name"].get<std::string>() == "hospital") {

    	Hospital* newHospital = new Hospital();
    	
	    newHospital->SetID(entityData["entityId"].get<double>());

	    if(!entityData["position"].is<picojson::array>()){
	    	printf("Error converting to array\n");
	    	exit(1);
	    }
	    // Get the position as an array
	    picojson::array position = entityData["position"].get<picojson::array>();
	    newHospital->SetX(position[0].get<double>());
	    newHospital->SetY(position[1].get<double>());
	    newHospital->SetZ(position[2].get<double>());
	    
	    return newHospital;
	}
	return NULL;
}

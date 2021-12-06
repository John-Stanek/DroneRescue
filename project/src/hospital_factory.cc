#include "hospital_factory.h"
#include "factory.h"

HospitalFactory::HospitalFactory(){}
HospitalFactory::~HospitalFactory(){}

Entity* HospitalFactory::CreateEntity(picojson::object &entityData, ICameraController& cameraController){

	//parse json object aka entityData

    if ((entityData["name"].get<std::string>().compare (0, 8, "hospital")) == 0) {
    	Hospital* newHospital = new Hospital();
    	//if entity is robot:
		//set all appropriate fields of robot from json data

    	
    	//newHospital->SetName((char*)entityData["name"].get<std::string>().c_str());
	    newHospital->SetID(entityData["entityId"].get<double>());
		newHospital->SetName(entityData["name"].get<std::string>());

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
Entity* HospitalFactory::CreateEntity(picojson::object &entityData){

	//parse json object aka entityData

    if ((entityData["name"].get<std::string>().compare (0, 8, "hospital")) == 0) {
		Hospital* newHospital = new Hospital();
    	//if entity is robot:
		//set all appropriate fields of robot from json data

    	
    	//newHospital->SetName((char*)entityData["name"].get<std::string>().c_str());
	    newHospital->SetID(entityData["entityId"].get<double>());
		newHospital->SetName(entityData["name"].get<std::string>());

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

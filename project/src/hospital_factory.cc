#include "hospital_factory.h"
#include "factory.h"

HospitalFactory::HospitalFactory(){}
HospitalFactory::~HospitalFactory(){}

Entity* HospitalFactory::CreateEntity(picojson::object &entityData, ICameraController& cameraController){

	//parse json object aka entityData

    // Print out actual json:
    // picojson::value val(entityData);
    // std::cout << val.serialize() << std::endl;

    if ((entityData["name"].get<std::string>().compare (0, 8, "hospital")) == 0) {

    	Hospital* newHospital = new Hospital();
    	newHospital->SetName(entityData["name"].get<std::string>());
    	//newHospital->SetName((char*)entityData["name"].get<std::string>().c_str());
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

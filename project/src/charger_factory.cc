#include "charger_factory.h"
#include "factory.h"

ChargerFactory::ChargerFactory(){}
ChargerFactory::~ChargerFactory(){}

Entity* ChargerFactory::CreateEntity(picojson::object &entityData){

	//parse json object aka entityData

    // Print out actual json:
    // picojson::value val(entityData);
    // std::cout << val.serialize() << std::endl;

    if ((entityData["name"].get<std::string>().compare (0, 16, "recharge station")) == 0) {

    	Charger* newCharger = new Charger();
    	
    	//newCharger->SetName((char*)entityData["name"].get<std::string>().c_str());
	    newCharger->SetID(entityData["entityId"].get<double>());

	    if(!entityData["position"].is<picojson::array>()){
	    	printf("Error converting to array\n");
	    	exit(1);
	    }
	    // Get the position as an array
	    picojson::array position = entityData["position"].get<picojson::array>();
	    newCharger->SetX(position[0].get<double>());
	    newCharger->SetY(position[1].get<double>());
	    newCharger->SetZ(position[2].get<double>());
	    
	    return newCharger;
	}
	return NULL;
}
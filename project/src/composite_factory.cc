#include "composite_factory.h"
#include "factory.h"

static std::vector<Factory*> factories;

//TODO: MEMORY LEAKS NEED TO BE FIXED

CompositeFactory::CompositeFactory(){

	//std::vector<Factory*> factories;
	Factory* droneFactory = new DroneFactory();
	Factory* robotFactory = new RobotFactory();
	Factory* rechargeFactory = new ChargerFactory();
	Factory* hospitalFactory = new HospitalFactory();

	factories = std::vector<Factory*>();

	AddFactory(droneFactory);
	AddFactory(robotFactory);
	AddFactory(rechargeFactory);
	AddFactory(hospitalFactory);
}

CompositeFactory::~CompositeFactory(){
	//cant do this unless they are declared in .h, but that causes other problems
	/*delete droneFactory;
	delete robotFactory;
	delete rechargeFactory;
	delete hospitalFactory;*/
}


Entity* CompositeFactory::CreateEntity(picojson::object &entityData){
	//parse json object aka entityData

    // Print out actual json:
    //picojson::value val(entityData);
    //std::cout << picojson::value(entityData) << std::endl;
    //std::cout << val.serialize() << std::endl;

    //check every factory for successful return
	for(Factory* dfactory : factories){
		Entity* entity = dfactory->CreateEntity(entityData);
		if(entity){
			return entity;
		}
		
	}
	return NULL;
}

void CompositeFactory::AddFactory(Factory* factory){
	factories.push_back(factory);
}

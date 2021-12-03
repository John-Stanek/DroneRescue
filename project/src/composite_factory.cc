#include "composite_factory.h"
#include "factory.h"

static std::vector<Factory*> factories;

CompositeFactory::CompositeFactory(){
//Create vector of factories upon its own creation

	//std::vector<Factory*> factories;
	droneFactory = new DroneFactory();
	robotFactory = new RobotFactory();
	rechargeFactory = new ChargerFactory();
	hospitalFactory = new HospitalFactory();

	factories = std::vector<Factory*>();

	AddFactory(droneFactory);
	AddFactory(robotFactory);
	AddFactory(rechargeFactory);
	AddFactory(hospitalFactory);
}

CompositeFactory::~CompositeFactory(){
	delete droneFactory;
	delete robotFactory;
	delete rechargeFactory;
	delete hospitalFactory;
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

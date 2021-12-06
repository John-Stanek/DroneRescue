#include "composite_factory.h"
#include "factory.h"

static std::vector<Factory*> factories;

CompositeFactory::CompositeFactory(){
//Create vector of factories upon its own creation

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


Entity* CompositeFactory::CreateEntity(picojson::object &entityData, ICameraController& cameraController){

    //check every factory for successful return
	for(Factory* dfactory : factories){
		Entity* entity = dfactory->CreateEntity(entityData, cameraController);
		if(entity){
			return entity;
		}
		
	}
	return NULL;
}

Entity* CompositeFactory::CreateEntity(picojson::object &entityData){

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

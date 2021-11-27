#include "composite_factory.h"
#include "factory.h"

CompositeFactory(){

	Factory droneFactory;
	Factory robotFactory;
	Factory rechargeFactory;
	Factory hospitalFactory;

	AddFactory(droneFactory);
	AddFactory(robotFactory);
	AddFactory(rechargeFactory);
	AddFactory(hospitalFactory);
}


Factory::CreateEntity(picojson::object entityData){
	//parse json object aka entityData

    // Print out actual json:
    picojson::value val(entityData);
    std::cout << val.serialize() << std::endl;

    // Use your simulatin facade to create a new entity.
    // Below is an example on how to get data values from picojson.
    // The code should be in the factory, not here!

	for(Factory dfactory : factories){
		Entity* entity = dfactory->CreateEntity(entityData);
		if(entity){
			return entity;
		}
		return NULL;
	}
	
}

AddFactory(Factory factory){
	factories.push_back(factory);
}

#include "compositedronefactory.h"
#include "dronefactory.h"
#include "factory.h"


DroneFactory::Create(string type){
	foreach(dfactory : factories){
		Drone* drone = dfactory->Create(type);
		if(drone){
			return drone;
		}
		return NULL;
	}
	
}

AddFactory(DroneFactory factory){
	factories.push_back(factory);
}

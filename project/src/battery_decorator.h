#include "entity_decorator.h"


class BatteryEntity : public EntityDecorator {
	public:
		BatteryEntity(Entity* ent) : EntityDecorator(ent) {
			ent->hasBattery = true;
		}
		//virtual ~BatteryEntity() { delete ent; }//causes memory leak in test
		
		/*
		void Update(){
			EntityDecorator::Update();
			
			//Add battery stuff here
		}
		
		
		
		*/
		/*Entity* addBattery(Entity* ent) {
			if(!ent->hasBattery){
				ent->hasBattery = true;
				return ent;
			}*/
};

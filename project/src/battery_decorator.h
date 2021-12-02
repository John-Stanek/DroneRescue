#include "entity_decorator.h"


class BatteryEntity : public EntityDecorator {
	public:
		BatteryEntity(Entity* ent) : EntityDecorator(ent) {
			ent->hasBattery = true;
		}
		virtual ~BatteryEntity() { delete ent; }
		
		/*Entity* addBattery(Entity* ent) {
			if(!ent->hasBattery){
				ent->hasBattery = true;
				return ent;
			}*/
};

#include "entity_decorator.h"
#include "battery.h"


/**
 * @brief The BatteryEntity Class represents an entity object that has a battery and is created by the simulation.
 *   Uses the decorator pattern to add a battery to an exisiting entity object
 */

class BatteryEntity : public EntityDecorator {
	public:
	
		/**
		 * @brief A battery object to be applied to any given entity 
		 */
		Battery *battery;
		
		/**
	     * @brief Construct a new BatteryEntity object using an existing entity object
	     * @param ent - An Entity pointer of an existing object
	     * @return
	     *   Returns a new instance of a the BatteryEntity class.
	     */
		BatteryEntity(Entity* ent) : EntityDecorator(ent) {
			ent->hasBattery = true;
			battery = new Battery();
			
		}
		
		/**
	     * @brief Destruct a BatteryEntity object
	     */
		virtual ~BatteryEntity() { delete battery; }
		
		/**
	     * @brief Update the BatteryEntity object by calling the entity's update function if it fulfills battery requirements
	     */
		void Update(double dt, double arrows[4], bool moves[2]){
			if(battery->GetBatteryLife() <=0){
				ent->final = true;
			}
			
			if(battery->GetBatteryLife() > 0){
				EntityDecorator::Update(dt, arrows, moves);
			}
			
		}
		
		/**
	     * @brief Get the position of the BatteryEntity object
	     * @param index - The index of the pos array that is requested
	     * @return
	     *   A position value of a given index as type double
	     */
		double GetPosition(int index){
			return EntityDecorator::GetPosition(index);
		}
		
};

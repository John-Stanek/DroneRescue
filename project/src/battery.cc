#include "battery.h"

// Creates a battery with a battery life of 5000
Battery::Battery(){
    batteryLife = 5000;
}
// Creates a battery with a specific amount of battery
Battery::Battery(float batLife){
    batteryLife = batLife;
}
// Sets the battery life 
void Battery::SetBatteryLife(float batLife){
    batteryLife = batLife;
}
// Gets what the battery life is
float Battery::GetBatteryLife(){
    return batteryLife;
}
// Reduces the battery life by an input
void Battery::ReduceBatteryLife(float dt){
    batteryLife -= dt;
}
// Recharges the battery life by an input
void Battery::RechargeBatteryLife(float dt){
    batteryLife += dt;
}

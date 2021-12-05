#include "battery.h"


Battery::Battery(){
    batteryLife = 5000;
}
Battery::Battery(float batLife){
    batteryLife = batLife;
}
void Battery::SetBatteryLife(float batLife){
    batteryLife = batLife;
}
float Battery::GetBatteryLife(){
    return batteryLife;
}
void Battery::ReduceBatteryLife(float dt){
    batteryLife -= dt;
}
void Battery::RechargeBatteryLife(float dt){
    batteryLife += dt;
}

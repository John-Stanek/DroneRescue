#include "battery.h"


Battery::Battery(){
    batteryLife = 5000;
    maxCharge = 5000;
    empty = false;
}
Battery::Battery(float batLife){
    batteryLife = batLife;
    maxCharge = 5000;
    empty = false;
}
void Battery::SetBatteryLife(float batLife){
    batteryLife = batLife;
}
float Battery::GetMax(){
    return maxCharge;
}
float Battery::GetBatteryLife(){
    return batteryLife;
}
void Battery::ReduceBatteryLife(float rem){
    batteryLife -= rem;
}
void Battery::RechargeBatteryLife(){
    batteryLife = maxCharge;
}
bool Battery::IsEmpty(){
    return empty;
}
void Battery::SetEmpty(bool emp){
    empty = emp;
}
void Battery::CheckEmpty(){
    if(batteryLife <= 0){
        empty = true;
    }
}
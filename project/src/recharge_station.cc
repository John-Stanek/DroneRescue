#include "recharge_station.h"
#include "battery.h"

void RechargeStation::Recharge(Drone *drone){
    drone->battery.SetBatteryLife(5000);
}
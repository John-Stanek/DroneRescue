#include "recharge_station.h"
#include "battery.h"

RechargeStation::RechargeStation(BatteryEntity *drone){
    float dt = 1000;
    while(drone->battery->GetBatteryLife() < 5000){
        drone->battery->RechargeBatteryLife(dt);
    }
}
#ifndef RECHARGE_STATION_H_
#define RECHARGE_STATION_H_
#include "drone.h"
#include "battery_decorator.h"

class RechargeStation {

    public:
        RechargeStation(BatteryEntity *drone);
};
#endif

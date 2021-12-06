#ifndef RECHARGE_STATION_H_
#define RECHARGE_STATION_H_
#include "drone.h"

class RechargeStation {

    public:
    
    RechargeStation(){};
    /**
     * @brief Recharges the drone
     * 
     * @param drone 
     */
        void Recharge(Drone *drone);
    
};
#endif

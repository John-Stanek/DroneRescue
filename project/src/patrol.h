#ifndef PATROL_H
#define PATROL_H

#include "drone_movement.h"

/**
 * @brief - Handles the Patrol movement strategy
 * Inherits from DroneMovement
 * 
 */

class Patrol : public DroneMovement{
public:
    /**
     * @brief - performs the patrol movement strategy on the drone.
     * 
     * @param drone_pos - the drone's initial position
     * @param drone_dir - the drone's initial direction
     * @param drone_speed - the drone's speed
     * @return double* 
     */

    double* move(double* drone_pos, double* drone_dir, double drone_speed);
};

#endif
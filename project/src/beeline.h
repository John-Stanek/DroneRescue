#ifndef BEELINE_H
#define BEELINE_H

#include "drone_movement.h"

/**
 * @brief Handles the beeline movement strategy.
 * 
 */

class Beeline : public DroneMovement{
public:
    /**
     * @brief overrides DroneMovement move() and performs beeline move strategy on the drone.
     * 
     * @param drone_pos - drone's initial position.
     * @param drone_dir - drone's initial direction.
     * @param drone_speed - drone's speed.
     * @return double* - an array of representing the drone's now position.
     */
    double* move(double* drone_pos, double* drone_dir, double drone_speed);
};

#endif
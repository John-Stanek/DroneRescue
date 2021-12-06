#ifndef DRONE_MOVEMENT_H
#define DRONE_MOVEMENT_H

#include <iostream>
#include <vector>

/**
 * @brief - Handles the drone's movement logic.
 * Abstract class.
 * Subclasses include Patrol and Beeline.
 * 
 */

class DroneMovement {
public:
    virtual double* move(double* drone_pos, double* drone_dir, double drone_speed) = 0;
};

#endif
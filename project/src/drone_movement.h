#ifndef DRONE_MOVEMENT_H
#define DRONE_MOVEMENT_H

#include <iostream>
#include <vector>

class DroneMovement {
public:
    virtual double* move(double* drone_pos, double* drone_dir, double drone_speed) = 0;
};

#endif
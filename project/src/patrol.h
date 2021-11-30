#ifndef PATROL_H
#define PATROL_H

#include "drone_movement.h"

class Patrol : public DroneMovement{
public:
    double* move(double* drone_pos, double drone_speed);
};

#endif
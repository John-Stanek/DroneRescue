#ifndef BEELINE_H
#define BEELINE_H

#include "drone_movement.h"

class Beeline : public DroneMovement{
public:
    double* move(double* drone_pos, double* drone_dir, double drone_speed);
};

#endif
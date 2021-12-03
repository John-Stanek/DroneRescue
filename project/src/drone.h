#ifndef DRONE_H
#define DRONE_H

#include <iostream>
#include <vector>

#include "drone_movement.h"
#include "entity.h"


class Drone : public Entity{
public:
    double id; 
    double pos[3] = {0, 264, 0}; 
    double dir[3] = {0, 0, 0};
    double speed; 
    bool isSearching = true;
public:
    Drone();
    Drone(std::string name);
    Drone(double x, double y, double z);
    void SetSpeed(double speed);
    
    void Update(double dt);
    void SetJoystick(double x, double y, double z, double a, bool s);
    double GetPosition(int index);
    double GetSpeed();
    double GetDirection(int index);
    int GetId();

    DroneMovement* movement;
};

#endif

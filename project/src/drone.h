#ifndef DRONE_H
#define DRONE_H

#include <iostream>
#include <vector>

#include "drone_movement.h"
#include "battery.h"
#include "entity.h"


class Drone : public Entity{
public:
    double id; 
    double pos[3] = {0, 264, 0}; 
    double dir[3] = {0, 0, 0};
    double speed;
    float time = 0.0;
    float lastPictureTime = 0.0; 
    bool final = false;
    bool patrol = false;
    bool beeline = false;
    Battery battery;
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

#ifndef DRONE_H
#define DRONE_H

#include <iostream>
#include <vector>

#include "drone_movement.h"
#include "entity.h"
#include "camera.h"

class Drone : public Entity{
public:
    int id; 
    double pos[3];
    double dir[3];
    double speed; 
    bool patrol = false;
    bool beeline = false;
    float lastPictureTime;
    float time;
    Camera* camera;

    Drone();
    ~Drone();
    Drone(double x, double y, double z, char* name);
    void SetSpeed(double speed);
    
    void Update(double dt);
    void SetJoystick(double x, double y, double z, double a, bool p, bool b);
    double GetPosition(int index);
    double GetSpeed();
    double GetDirection(int index);
    int GetId();

    DroneMovement* movement;
};

#endif

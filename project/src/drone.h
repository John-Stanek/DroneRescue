#ifndef DRONE_H
#define DRONE_H

#include <iostream>
#include <vector>

#include "drone_movement.h"
#include "battery.h"
#include "entity.h"
#include "camera.h"

class Drone : public Entity{
public:
    int id; 
    double pos[3];
    double dir[3];
    double speed; 
    bool final = false;
    bool patrol = false;
    bool beeline = false;
    double time = 0.0;
    double lastPictureTime = 0.0; 
    Camera* camera;
    Battery battery;
    Drone();
    ~Drone();
    Drone(double x, double y, double z, char* name);
    void SetSpeed(double speed);
    
    void Update(double dt, double arrows[4], bool moves[2]);
    void SetJoystick(double arrows[4], bool moves[2]);
    double GetPosition(int index);
    double GetSpeed();
    double GetDirection(int index);
    int GetId();

    DroneMovement* movement;
};

#endif

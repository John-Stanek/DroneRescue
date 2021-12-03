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
<<<<<<< HEAD
    double id; 
    double pos[3] = {0, 264, 0}; 
    double dir[3] = {0, 0, 0};
    double speed;
    double time;
    double lastPictureTime;
=======
    int id; 
    double pos[3];
    double dir[3];
    double speed; 
>>>>>>> 9c7b48151f2cfcba0cfed5e1b02e76eeeb98aac2
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
    
    void Update(double dt);
    void SetJoystick(double x, double y, double z, double a, bool p, bool b);
    double GetPosition(int index);
    double GetSpeed();
    double GetDirection(int index);
    int GetId();

    DroneMovement* movement;
};

#endif

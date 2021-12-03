#include "drone.h"
#include "drone_movement.h"
#include "beeline.h"
#include "patrol.h"

Drone::Drone() {
    pos[0] = 0;
    pos[1] = 0;
    pos[2] = 0;

    for(int i=0; i<3; i++) {
        dir[i] = 0;
    }
    
    id = 0;
    speed = 0;
    name = NULL;
    lastPictureTime = 0.0;
    time = 0.0;
}

Drone::Drone(double x, double y, double z, char* name){
    pos[0] = x;
    pos[1] = y;
    pos[2] = z;

    for(int i=0; i<3; i++) {
        dir[i] = 0;
    }
    
    name = name;
    id = 0;
    speed =0;
}

Drone::~Drone() {
    delete camera;
}

double Drone::GetPosition(int index) {
    return pos[index];
}

double Drone::GetDirection(int index) {
    return pos[index];
}

double Drone::GetSpeed() {
    return speed;
}

void Drone::SetSpeed(double s){
        speed = s;
}
int Drone::GetId() {
    return id;
}

void Drone::Update(double dt) {
    double* new_position;

    if (patrol || beeline) {
        if (patrol) { this->movement = new Patrol(); }
        else if (beeline) { this->movement = new Beeline(); }
        new_position = this->movement->move(pos, dir, speed);

        for (int i=0; i < 3; i++) {
            pos[i] = new_position[i];
        }
        delete this->movement;
    }
    else {
        for (int i = 0; i < 3; i++) {
            pos[i] += speed*dir[i]*dt;
        }
    }

    // Take a picture every 5 seconds with front camera
    time += dt;
    if (time-lastPictureTime > 5.0) {
        camera->TakePicture();
        lastPictureTime = time;
    }
}
void Drone::SetJoystick(double x, double y, double z, double a, bool p, bool b) {
    patrol = p;
    beeline = b;
    dir[0] = x; dir[1] = y; dir[2] = z;
}

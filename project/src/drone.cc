#include "drone.h"
#include "drone_movement.h"
#include "beeline.h"
#include "patrol.h"
#include "recharge_station.h"

Drone::Drone(ICameraController& cameraController) {
    id = 0;
    speed = 0;
    x=0; y=0; z=0;
    name = "drone";
    camera = new Camera(id, &cameraController);
}

Drone::~Drone() {
    delete camera;
    delete movement;
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

void Drone::SetJoystick(double arrows[4], bool moves[2]) {
    patrol = moves[0];
    beeline = moves[1];
    for (int i=0; i<3; i++) {
        dir[i] = arrows[i];
    }
}

void Drone::Update(double dt, double arrows[4], bool moves[2]) {
    this->SetJoystick(arrows, moves);
    double* new_position;
    double rspos[3] = {1000, 1000, 0}; 
    if(camera->result.found) {
        this->movement = new Beeline();
        new_position = this->movement->move(pos, dir, speed);
        for (int i=0; i < 3; i++) {
            pos[i] = new_position[i];
        }
        delete this->movement;
        camera->result.found = false;
    }
    else if (patrol || beeline) {
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


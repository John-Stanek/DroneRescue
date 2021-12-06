#include "drone.h"
#include "drone_movement.h"
#include "beeline.h"
#include "patrol.h"


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
    // Hard coding the postion of the recharge station
    double rspos[3] = {0, 0, 0};
    // Reduces the battery life of the drone everytime update is called
    this->battery.ReduceBatteryLife(dt);
    // Check if the battery life is zero and sets a bool final to true and will stop moving the drone
    if(this->battery.GetBatteryLife() <= 0){
        final = true;
    }
    // Check if the battery is less that 20% and final is false
    if(this->battery.GetBatteryLife() < 1000 && !final){
        // Beelines to where the recharge station is
        this->movement = new Beeline();
        new_position = this->movement->move(pos, rspos, speed);
        for (int i=0; i < 3; i++) {
            pos[i] = new_position[i];
        }
        delete this->movement;
        // Checks if the drone position is the same as the recharge station position
        if((int)pos[0] == (int)rspos[0] && (int)pos[1] == (int)rspos[1] && (int)pos[2] == (int)rspos[2]){
            // Once drone is at the recharge station position it will recharge the drones battery
            this->battery.Recharge();}

    }
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
    // Check if the battery life is greater that 20% and final is false

    // Take a picture every 5 seconds with front camera
    time += dt;
    if (time-lastPictureTime > 5.0) {
        camera->TakePicture();
        lastPictureTime = time;
    }
}


#include "drone.h"
#include "drone_movement.h"
#include "beeline.h"
#include "patrol.h"
#include "recharge_station.h"

Drone::Drone() {
    id = 0;
    speed = 0;
    pos[0] = 0;
    pos[1] = 0;
    pos[2] = 0;

    dir[0] = 0;
    dir[1] = 0;
    dir[2] = 0;
    x=0;
    y=0;
    z=0;
    name = "drone";
}

Drone::Drone(std::string n){
    pos[0] = 0;
    pos[1] = 0;
    pos[2] = 0;

    dir[0] = 0;
    dir[1] = 0;
    dir[2] = 0;
    x=0;
    y=0;
    z=0;
    name = n;
    id = 0;
    speed = 0;
}

Drone::Drone(double x, double y, double z){
    pos[0] = x;
    pos[1] = y;
    pos[2] = z;

    dir[0] = 0;
    dir[1] = 0;
    dir[2] = 0;
    x=x;
    y=y;
    z=z;
    name = "";
    id = 0;
    speed =0;
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
    double rspos[3] = {1000, 1000, 0}; 
    if(this->battery.GetBatteryLife() <= 0){
        final = true;
    }
    if(this->battery.GetBatteryLife() < 1000){
        this->movement = new Beeline();
        new_position = this->movement->move(pos, rspos, speed);
        for (int i=0; i < 3; i++) {
            pos[i] = new_position[i];
        }
        delete this->movement;
        RechargeStation(this);
    }
    if ((patrol || beeline) && !final) {
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
    // double* new_position;
    // this->battery.ReduceBatteryLife(dt);
    // if (!isSearching) {
    //     this->movement = new Patrol();
    //     new_position = this->movement->move(pos, dir, speed);

    //     for (int i=0; i < 3; i++) {
    //         pos[i] = new_position[i];
    //     }
    //     if(this->battery.GetBatteryLife() < 1000){
    //         this->movement = new Beeline();
    //         RechargeStation(this);
    //     }

    //     delete this->movement;
    // }
    // // else if {
    // //     this->movement = new Patrol();
    // //     new_position = this->movement->move(pos, dir, speed);
    // // }
    // else {
    //     for (int i = 0; i < 3; i++) {
    //         pos[i] += speed*dir[i]*dt;
    //     }  
    // }

    // // // Take a picture every 5 seconds with front camera
    // // time += dt;
    // // if (time-lastPictureTime > 5.0) {
    // //     cameras[0]->TakePicture();
    // //     lastPictureTime = time;
    // // }
}
void Drone::SetJoystick(double x, double y, double z, double a, bool s) {
    //isSearching = !s;
    dir[0] = x; dir[1] = y; dir[2] = z;
}

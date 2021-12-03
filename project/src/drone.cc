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
    /*
    this->SetJoystick(
        IsKeyDown("ArrowRight") ? 1 : (IsKeyDown("ArrowLeft") ? -1 : 0),
        IsKeyDown("w") ? 1 : (IsKeyDown("s") ? -1 : 0),
        IsKeyDown("ArrowUp") ? -1 : (IsKeyDown("ArrowDown") ? 1 : 0),
        IsKeyDown("a") ? 1 : (IsKeyDown("d") ? -1 : 0),
        IsKeyDown("p") ? 1 : 0,
        IsKeyDown("b") ? 1 : 0 
    );
    */

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
}
void Drone::SetJoystick(double x, double y, double z, double a, bool p, bool b) {
    patrol = p;
    beeline = b;
    dir[0] = x; dir[1] = y; dir[2] = z;
}

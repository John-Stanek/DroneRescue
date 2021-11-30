#include "patrol.h"

double* Patrol::move(double* drone_pos, double drone_speed) {
    double beelineDir[3] = {5, 5, 5};
    
    
    double dt = 0.01;
    double beelineVel[3] = {0, 0, 0};
    double timestep[3] = {0, 0, 0};
    for(int i = 0; i < 3; i++){
        beelineDir[i] = beelineDir[i] - drone_pos[i];
        beelineVel[i] = beelineDir[i] * drone_speed;
        timestep[i] = beelineVel[i] * dt;
        drone_pos[i] += timestep[i];
    
     
    }
    // center (0, 264, 0)
    // minimum (-1450, 264, -900)
    // maximun (1550, 264, 900)
}
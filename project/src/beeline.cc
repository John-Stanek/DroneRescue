#include "beeline.h"

double* Beeline::move(double* drone_pos, double drone_speed) {
    double beelineDir[3] = {5, 5, 5};
    double arr[3];
    for(int i=0; i<3; i++) {
        arr[i] = drone_pos[i];
    }
    if (drone_pos[2] >= 20) {
        return drone_pos;
    }
    double dt = 0.01;
    double beelineVel[3] = {0, 0, 0};
    double timestep[3] = {0, 0, 0};
    for(int i = 0; i < 3; i++){
        beelineDir[i] = beelineDir[i] - drone_pos[i];
        beelineDir[i] = beelineDir[i];
        beelineVel[i] = beelineDir[i] * drone_speed;
        timestep[i] = beelineVel[i] * dt;
        drone_pos[i] += timestep[i];
    }

    if (drone_pos[2] >= 5) {
        return arr;
    }

    return drone_pos;
}
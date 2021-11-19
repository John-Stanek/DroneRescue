#include "beeline.h"

double* Beeline::move() {
    double beelineDir = {0, 0, 0};
    double dt = 0.1;
    double beelineVel = {0, 0, 0};
    double timestep = {0, 0, 0};
    for(int i = 0; i < 3; i++){
        beelineDir[i] = beelineDir[i] - this.pos[i];
        beelineDir[i] = beelineDir[i] / abs(beelineDir[i]);
        beelineVel[i] = beelineDir[i] * this.speed;
        timestep[i] = beelineVel[i] * dt;
    }


}
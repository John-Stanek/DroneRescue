#include "patrol.h"

double* Patrol::move(double* drone_pos, double* drone_dir, double drone_speed) {
    double dt = 0.1;
    double beelineVel[3] = {0, 0, 0};
    double timestep;

    if(drone_pos[2] >= 0 && drone_pos[0] <= 0) {
        beelineVel[0] = 0;
        beelineVel[2] = -1;
        timestep = beelineVel[2] * dt;
        drone_pos[2] += timestep;
        return drone_pos;
    }

    if(drone_pos[0] < 100 && drone_pos[2] < 100) {
        beelineVel[0] = 1;
        beelineVel[2] = 0;
        timestep = beelineVel[0] * dt;
        drone_pos[0] += timestep;
        return drone_pos;
    }

   if(drone_pos[2] < 100 && drone_pos[0] >= 100) {
        beelineVel[0] = 0;
        beelineVel[2] = 1;
        timestep = beelineVel[2] * dt;
        drone_pos[2] += timestep;
        return drone_pos;
   }

   if(drone_pos[2] >= 100 && drone_pos[0] >= 0) {
        beelineVel[0] = -1;
        beelineVel[2] = 0;
        timestep = beelineVel[0] * dt;
        drone_pos[0] += timestep;
        return drone_pos;
    }    
   
   return drone_pos; 
}

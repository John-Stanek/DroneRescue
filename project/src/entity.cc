#include "entity.h"

    Entity::Entity(){
        pos[0] = 0;
        pos[1] = 0;
        pos[2] = 0;

        dir[0] = 0;
        dir[1] = 0;
        dir[2] = 0;
        
        x=0;
        y=0;
        z=0;
        name = NULL;
        id = -1;

    }
    
    
    Entity::Entity(char *n){
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
        id = -1;
    }


    Entity::Entity(double x, double y, double z){
        pos[0] = x;
        pos[1] = y;
        pos[2] = z;

        dir[0] = 0;
        dir[1] = 0;
        dir[2] = 0;
        x=x;
        y=y;
        z=z;
        name = NULL;
        id = -1;
    }


    double Entity::GetX(){
        return x;
    }


    double Entity::GetY(){
        return y;
    }


    double Entity::GetZ(){
        return z;
    }


    void Entity::SetX(double x){
        x = x;
    }


    void Entity::SetY(double y){
        y = y;
    }


    void Entity::SetZ(double z){
        z = z;
    }

     
    double *Entity::GetDir(){
        return dir;
    }
     
    void Entity::SetDir(double d[3]){
        dir[0] = d[0];
        dir[1] = d[1];
        dir[2] = d[2];
    }
    
    double *Entity::GetPos(){
        return pos;
    }
     
    void Entity::SetPos(double d[3]){
        pos[0] = d[0];
        pos[1] = d[1];
        pos[2] = d[2];
    }
     
    void Entity::SetID(double i){
        id = i;
    }
    
    double Entity::GetID(){
        return id;
    }

    bool Entity::CheckForBattery(){
        if(hasBattery){
            return true;
        }
        return false;
    }


	Charger::Charger(){
        pos[0] = 0;
        pos[1] = 0;
        pos[2] = 0;

        dir[0] = 0;
        dir[1] = 0;
        dir[2] = 0;
        x=0;
        y=0;
        z=0;
        name = NULL;
        id = -1;

    }
	
	Charger::Charger(char *n){
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
        id = -1;

    }
	
	Charger::Charger(double x, double y, double z){
        pos[0] = x;
        pos[1] = y;
        pos[2] = z;

        dir[0] = 0;
        dir[1] = 0;
        dir[2] = 0;
        x=x;
        y=y;
        z=z;
        name = NULL;
        id = -1;

    }



	// Drone::Drone(){
 //        pos[0] = 0;
 //        pos[1] = 0;
 //        pos[2] = 0;

 //        dir[0] = 0;
 //        dir[1] = 0;
 //        dir[2] = 0;
 //        x=0;
 //        y=0;
 //        z=0;
 //        name = NULL;
 //        id = -1;
 //    }
	
	// Drone::Drone(char *n){
 //        pos[0] = 0;
 //        pos[1] = 0;
 //        pos[2] = 0;

 //        dir[0] = 0;
 //        dir[1] = 0;
 //        dir[2] = 0;
 //        x=0;
 //        y=0;
 //        z=0;
 //        name = n;
 //        id = -1;
 //    }
	
	// Drone::Drone(double x, double y, double z){
 //        pos[0] = x;
 //        pos[1] = y;
 //        pos[2] = z;

 //        dir[0] = 0;
 //        dir[1] = 0;
 //        dir[2] = 0;
 //        x=x;
 //        y=y;
 //        z=z;
 //        name = NULL;
 //        id = -1;
 //    }
	
	// void Drone::SetSpeed(double s){
 //        speed = s;
 //    }
	

    Robot::Robot(){
        pos[0] = 0;
        pos[1] = 0;
        pos[2] = 0;

        dir[0] = 0;
        dir[1] = 0;
        dir[2] = 0;
        x=0;
        y=0;
        z=0;
        name = NULL;
        id = -1;
    }
    
    Robot::Robot(char *n){
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
        id = -1;
    }
    
    Robot::Robot(double x, double y, double z){
        pos[0] = x;
        pos[1] = y;
        pos[2] = z;

        dir[0] = 0;
        dir[1] = 0;
        dir[2] = 0;
        x=x;
        y=y;
        z=z;
        name = NULL;
        id = -1;
    }


    Hospital::Hospital(){
        pos[0] = 0;
        pos[1] = 0;
        pos[2] = 0;

        dir[0] = 0;
        dir[1] = 0;
        dir[2] = 0;
        x=0;
        y=0;
        z=0;
        name = NULL;
        id = -1;
    }
    
    Hospital::Hospital(char *n){
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
        id = -1;
    }
    
    Hospital::Hospital(double x, double y, double z){
        pos[0] = x;
        pos[1] = y;
        pos[2] = z;

        dir[0] = 0;
        dir[1] = 0;
        dir[2] = 0;
        x=x;
        y=y;
        z=z;
        name = NULL;
        id = -1;
    }

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
        name = "";
        id = -1;

    }
    
    
    Entity::Entity(std::string n){
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
        name = "";
        id = -1;
    }


    double Entity::GetX(){
        return pos[0];
    }


    double Entity::GetY(){
        return pos[1];
    }


    double Entity::GetZ(){
        return pos[2];
    }


    void Entity::SetX(double x){
        x = x;
        pos[0] = x;
    }


    void Entity::SetY(double y){
        y = y;
        pos[1]=y;
    }


    void Entity::SetZ(double z){
        z = z;
        pos[2] =z;
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
    
    void Entity::SetName(std::string n) {
		name = n;
	}

    std::string Entity::GetName(){
        return name;
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
        name = "";
        id = -1;

    }
	
	Charger::Charger(std::string n){
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
        name = "";
        id = -1;

    }

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
        name = "";
        id = -1;
    }
    
    Robot::Robot(std::string n){
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
        name = "";
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
        name = "";
        id = -1;
    }
    
    Hospital::Hospital(std::string n){
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
        name = "";
        id = -1;
    }

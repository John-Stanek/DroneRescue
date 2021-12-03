#ifndef DEC_H
#define DEC_H

#include <iostream>
#include <vector>
#include "entity.h"


class EntityDecorator : public Entity{
protected:
/*
    double pos[3];
    double dir[3];
    double x,y,z;
    char *name;
    double id;
    */
    Entity *ent;
public:
/*
    Entity();
    
    Entity(char *name);

    Entity(double x, double y, double z);

    double GetX();

    double GetY();

    double GetZ();

    void SetX(double x);

    void SetY(double y);

    void SetZ(double z);

    double *GetDir();
     
    void SetDir(double dir[3]);
     
    void SetID(double id);
*/
	EntityDecorator(Entity *ent) : ent(ent) {}
	
};

#endif

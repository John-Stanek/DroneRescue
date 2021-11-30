#ifndef FACTORY
#define FACTORY

#include <iostream>
#include <vector>
#include "entity.h"
#include "picojson.h"


class Factory {
public:

    virtual ~Factory(){};
    
    virtual Entity* CreateEntity(picojson::object &entityData){return NULL;};
    
    
};

#endif

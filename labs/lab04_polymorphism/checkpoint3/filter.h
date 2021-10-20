#ifndef FILTER_H_
#define FILTER_H_

#include <iostream>
#include <vector>
#include "image.h"

class Filter {
public:
    virtual void Apply(std::vector<Image*> original, std::vector<Image*> filtered);
};

#endif
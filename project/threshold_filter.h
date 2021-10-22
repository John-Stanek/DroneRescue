#ifndef THRESHOLD_FILTER_H
#define THRESHOLD_FILTER_H

#include <iostream>
#include "filter.h"

class ThresholdFilter : public Filter {
private:
    float threshold;
public:
    ThresholdFilter(float threshold);
    void Apply(std::vector<Image*> original, std::vector<Image*> filtered);
};

#endif
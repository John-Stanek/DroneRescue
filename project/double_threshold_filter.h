#ifndef DOUBLE_THRESHOLD_H
#define DOUBLE_THRESHOLD_H

#include "filter.h"


class DoubleThresholdFilter : public Filter{
private:
    float strong_threshold_ratio;
    float weak_threshold_ratio;
public:
    DoubleThresholdFilter(float sThresh, float wThresh);
    void Apply(std::vector<Image*> original, std::vector<Image*> filtered);
};

#endif
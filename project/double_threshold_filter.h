#ifndef DOUBLE_THRESHOLD_FILTER_H
#define DOUBLE_THRESHOLD_FILTER_H

#include "filter.h"

class DoubleThresholdFilter : public Filter {
private:
    float strong_threshold_ratio;
    float weak_threshold_ratio;
public:
    DoubleThresholdFilter(float strong, float weak);
    void Apply(std::vector<Image*> original, std::vector<Image*> filtered);
};

#endif

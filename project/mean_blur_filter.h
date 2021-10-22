#ifndef MEAN_BLUR_FILTER_H
#define MEAN_BLUR_FILTER_H

#include <iostream>
#include "filter.h"

class MeanBlurFilter : public Filter {
public:
    void Apply(std::vector<Image*> original, std::vector<Image*> filtered);
};

#endif
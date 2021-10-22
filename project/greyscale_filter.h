#ifndef GREY_SCALE_FILTER_H_
#define GREY_SCALE_FILTER_H_

#include "filter.h"

class GreyScaleFilter : public Filter {
public:
    void Apply(std::vector<Image*> original, std::vector<Image*> filtered);
};

#endif
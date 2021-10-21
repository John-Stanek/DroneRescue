#ifndef SHARPEN_FILTER_H
#define SHARPEN_FILTER_H

#include "filter.h"

class SharpenFilter : public Filter {
public:
    void Apply(std::vector<Image*> original, std::vector<Image*> filtered);
};


#endif

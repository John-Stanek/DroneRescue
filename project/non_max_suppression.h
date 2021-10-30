#ifndef NMS_Filter
#define NMS_Filter

#include <iostream>
#include "filter.h"

class NonMaxSuppression : public Filter {
public:
    void Apply(std::vector<Image*> original, std::vector<Image*> filtered);
};

#endif //NMS_Filter

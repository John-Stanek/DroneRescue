#ifndef HYSTERESIS_H
#define HYSTERESIS_H

#include "filter.h"

class HysteresisFilter : public Filter {
public:
	void Apply(std::vector<Image*> original, std::vector<Image*> filtered);
};

#endif

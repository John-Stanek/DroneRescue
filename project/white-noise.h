#ifndef NMS
#define NMS

#include "filter.h"

class WhiteNoise : public Filter {
	public:
		WhiteNoise();
		void Apply(std::vector<Image*> original, std::vector<Image*> filtered);
};

#endif //NMS

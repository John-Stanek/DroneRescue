#include "canny_edge_detect_filter.h"

void CannyEdgeDetectFilter::Apply(std::vector<Image*> original, std::vector<Image*> filtered){
	GreyScaleFilter::Apply(original, filtered);
	
	std::vector<Image*> filtered_copy = filtered;
	GaussianBlurFilter::Apply(filtered_copy, filtered);
	
	filtered_copy = filtered;
	SobelFilter::Apply(filtered_copy, filtered);
	
	filtered_copy = filtered;
	NonMaxSuppression::Apply(filtered_copy, filtered);
	
	filtered_copy = filtered;
	DoubleThresholdFilter::Apply(filtered_copy, filtered);
	
	filtered_copy = filtered;
	HysteresisFilter::Apply(filtered_copy, filtered);
}

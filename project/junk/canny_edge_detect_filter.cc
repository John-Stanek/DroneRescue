#include "canny_edge_detect_filter.h"
#include <algorithm>
#include <iterator>

void CannyEdgeDetectFilter::Apply(std::vector<Image*> original, std::vector<Image*> filtered){
	GreyScaleFilter greyscale = GreyScaleFilter();
	GaussianBlurFilter gaussian = GaussianBlurFilter(2,5);
	SobelFilter sobel = SobelFilter();
	NonMaxSuppression non_max_suppression = NonMaxSuppression();
	DoubleThresholdFilter double_threshold = DoubleThresholdFilter(0.09 , 0.4);
	HysteresisFilter hysteresis = HysteresisFilter();
	std::vector<Image*> filtered_copy;
	
	filtered_copy.push_back(original[0]);
	filtered.push_back(original[0]);
	
	greyscale.GreyScaleFilter::Apply(original, filtered);
	
	copy(filtered.begin(), filtered.end(), back_inserter(filtered_copy));
	//filtered_copy = std::vector<Image*>(filtered);

	
	gaussian.GaussianBlurFilter::Apply(filtered_copy, filtered);
	
	filtered_copy = filtered;
	sobel.SobelFilter::Apply(filtered_copy, filtered);
	
	filtered_copy = filtered;
	
	
	non_max_suppression.NonMaxSuppression::Apply(filtered_copy, filtered);
	
	filtered_copy = filtered;
	double_threshold.DoubleThresholdFilter::Apply(filtered_copy, filtered);
	
	
	filtered_copy = filtered;
	hysteresis.HysteresisFilter::Apply(filtered_copy, filtered);
	
	
}

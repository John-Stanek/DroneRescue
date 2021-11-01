#include "canny_edge_detect_filter.h"

void CannyEdgeDetectFilter::Apply(std::vector<Image*> original, std::vector<Image*> filtered){GreyScaleFilter greyscale = GreyScaleFilter();
	GaussianBlurFilter gaussian = GaussianBlurFilter(1,5);
	SobelFilter sobel = SobelFilter();
	NonMaxSuppression non_max_suppression = NonMaxSuppression();
	DoubleThresholdFilter double_threshold = DoubleThresholdFilter(0.05 , 0.09);
	HysteresisFilter hysteresis = HysteresisFilter();
	
	
	greyscale.GreyScaleFilter::Apply(original, filtered);
	
	std::vector<Image*> filtered_copy = filtered;
	gaussian.GaussianBlurFilter::Apply(filtered_copy, filtered);
	
	filtered_copy = filtered;
	filtered.push_back(filtered[0]);
	sobel.SobelFilter::Apply(filtered_copy, filtered);
	
	filtered_copy = filtered;
	non_max_suppression.NonMaxSuppression::Apply(filtered_copy, filtered);
	
	filtered_copy = filtered;
	double_threshold.DoubleThresholdFilter::Apply(filtered_copy, filtered);
	
	filtered_copy = filtered;
	hysteresis.HysteresisFilter::Apply(filtered_copy, filtered);
}


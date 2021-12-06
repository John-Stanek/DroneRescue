#ifndef IMAGE_PROCESSOR_H
#define IMAGE_PROCESSOR_H

#include <chrono>
#include <iostream>
#include <memory>
#include <string>
#include <thread>
#include <utility>
#include <vector>

#include "imageio/canny_edge_detect.h"
#include "imageio/composite_filter.h"
#include "imageio/iimage.h"
#include "imageio/image_helper.h"
#include "imageio/image_processor.h"
#include "blob_detection.h"

#include "camera.h"
#include "camera_controller.h"
#include <fstream>

class ImageProcessorFacade {
	public:
		ImageProcessorFacade(){};
		~ImageProcessorFacade(){};
		ICameraResult* ProcessImages(int cameraId, double xPos, double yPos, double zPos, const std::vector<RawCameraImage>& images, picojson::object& details) const;
		void ImageProcessingComplete(ICameraResult* result);
	public:
		struct CameraResult : public ICameraResult {
			bool found;
			double pos[3];
		};
};

#endif

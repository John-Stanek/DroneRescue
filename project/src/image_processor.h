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

#include "camera_controller.h"
#include <fstream>

/**
 * @brief The ImageProcessorFacade Class serves as the facade for the image processor.
 *   All access to the image processer from the web app is made through this facade.
 */

class ImageProcessorFacade {
	public:
		ImageProcessorFacade(){};
		~ImageProcessorFacade(){};
		/**
		 * @brief Processes an image to determine whether a Robot is present in
		 * the image.
		 * @return
		 * 	Returns a struct that tells whether the drone has been found in the image.
		 */
		ICameraResult* ProcessImages(int cameraId, double xPos, double yPos, double zPos, const std::vector<RawCameraImage>& images, picojson::object& details) const;
	public:
		/**
		 * @brief A struct that stores the result from ProcessImages. 
		 */
		struct CameraResult : public ICameraResult {
			bool found;
			double pos[3];
		};
};

#endif

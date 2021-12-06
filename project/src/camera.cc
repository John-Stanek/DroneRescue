#include <chrono>
#include <iostream>
#include <memory>
#include <string>
#include <thread>
#include <utility>
#include <vector>

#include "camera.h"
#include "imageio/canny_edge_detect.h"
#include "imageio/composite_filter.h"
#include "imageio/iimage.h"
#include "imageio/image_helper.h"
#include "imageio/image_processor.h"
#include "blob_detection.h"

Camera::~Camera() {
    delete controller;
    delete image_processor;
}

void Camera::TakePicture() {
    controller->TakePicture(id);
}

ICameraResult* Camera::ProcessImages(int cameraId, double xPos, double yPos, double zPos, const std::vector<RawCameraImage>& images, picojson::object& details) const {
    if (cameraId == id || cameraId < 0) {
		return image_processor->ProcessImages(cameraId, xPos, yPos, zPos, images, details);
	}
    else {
        return NULL;
    }
}

// After the asynchronous image processing, this method will be synchronized with the update loop.
void Camera::ImageProcessingComplete(ICameraResult* result) {
    CameraResult& res = *static_cast<CameraResult*>(result);
    this->result = res;
    if (res.found) {
        std::cout << "The robot was found here: " << res.pos[0] << ", " << res.pos[1] << ", " << res.pos[2] << std::endl;
    }
    delete result;
}

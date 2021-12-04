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
}

void Camera::TakePicture() {
    controller->TakePicture(id);
}

ICameraResult* Camera::ProcessImages(int cameraId, double xPos, double yPos, double zPos, const std::vector<RawCameraImage>& images, picojson::object& details) const {
    if (cameraId == id || cameraId < 0) {
        // These will output the image to files.  Ultimately this is just for debugging:
        std::ofstream colorFile ("color.png", std::ios::out | std::ios::binary);
        colorFile.write (reinterpret_cast<const char*>(images[0].data), images[0].length);
        std::ofstream depthFile ("depth.png", std::ios::out | std::ios::binary);
        depthFile.write (reinterpret_cast<const char*>(images[1].data), images[1].length);

        std::unique_ptr<imageio::IImage> statue;
        
        //TODO: Get color.png image to load into variable.

        // Load statue.png into static variable
        statue.reset(imageio::ImageHelper::FromFile("./1.png"));

        // How to use composite filter
        imageio::CompositeFilter composite;
        imageio::Image output;
        composite.AddFilter(new BlobDetection());
        composite.Apply( { statue.get() }, { &output } );

        // Count blob pixels.
        int blobCount = 0;
        for (int x=0; y < output.GetWidth(); x++) {
            for (int y=0; y < output.GetHeight(); y++) {
                Color pixel = output.GetPixel(x, y);
                if (pixel.Red() == 0 && pixel.Green() == 0; && pixel.Blue() == 0) {
                    blobCount++;        
                }
            }
        }
        
        composite.AddFilter(new imageio::CannyEdgeDetect(0.1, 0.3));
        composite.Apply( { statue.get() }, { &output } );

        // Count edge pixels.
        int edgeCount = 0;
        for (int x=0; y < output.GetWidth(); x++) {
            for (int y=0; y < output.GetHeight(); y++) {
                Color pixel = output.GetPixel(x, y);
                if () {
                    edgeCount++;        
                }
            }
        }
        
        //Get ratio of blob to edge pixels.

        output.SaveAs("./robot.png");
        std::cout << "Image filtered" << std::endl;

        //TODO: count blob pixels and edge pixels and get ratio
        // to check if robot is found.

        //TODO: do depth calulation and get robot's position.

        // Use the following to convert color and depth images to RGBA image from memory (inside your image class / perhaps with a new constructor):
        // int width, height, components;
        // unsigned char* buffer = stbi_load_from_memory((const unsigned char*)images[0].data, images[0].length(), &width, &height, &components, 4);
        // components = 4;

        // Generate the result of image processing.  This could include images using the Result class.
        CameraResult* result = new CameraResult();
        result->found = false;
        result->pos[0] = xPos;
        result->pos[1] = yPos;
        result->pos[2] = zPos;
        return result;
    }
    else {
        return NULL;
    }
}

// After the asynchronous image processing, this method will be synchronized with the update loop.
void Camera::ImageProcessingComplete(ICameraResult* result) {
    CameraResult& res = *static_cast<CameraResult*>(result);
    if (res.found) {
        std::cout << "The robot was found here: " << res.pos[0] << ", " << res.pos[1] << ", " << res.pos[2] << std::endl;
    }
    delete result;
}
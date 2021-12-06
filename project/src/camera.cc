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

        CameraResult* result = new CameraResult();
        result->found = false;
        result->pos[0] = xPos;
        result->pos[1] = yPos;
        result->pos[2] = zPos;

        std::unique_ptr<imageio::IImage> statue;
        
        imageio::Image input;
        imageio::Image output;
        //input.Load("./1.png");
        input.LoadFromString(images[0].data, images[0].length);

        // How to use composite filter
        // imageio::CompositeFilter composite;
        // composite.AddFilter(new BlobDetection());
        // composite.Apply( { &input }, { &output } );
        imageio::Filter* blob = new BlobDetection();
        blob->Apply({ &input }, { &output });

        // Count blob pixels.
        int blobCount = 0;
        for (int x=0; x < input.GetWidth(); x++) {
            for (int y=0; y < input.GetHeight(); y++) {
                Color pixel = input.GetPixel(x, y);
                if (pixel.Red() == 255 && pixel.Green() == 255 && pixel.Blue() == 255) {
                    blobCount++;        
                }
            }
        }
        
        output.SaveAs("./blob.png");
        imageio::Filter* canny = new CannyEdgeDetect(0.1, 0.3);
        canny->Apply({&input}, {&output});
        // composite.AddFilter(new imageio::CannyEdgeDetect(0.1, 0.3));
        // composite.Apply( { &input }, { &output } );
        output.SaveAs("./edge.png");

        // Count edge pixels.
        int edgeCount = 0;
        for (int x=0; x < output.GetWidth(); x++) {
            for (int y=0; y < output.GetHeight(); y++) {
                Color pixel = output.GetPixel(x, y);
                if (pixel.Red() == 255 && pixel.Green() == 255 && pixel.Blue() == 255) {
                    edgeCount++;        
                }
            }
        }
        //Get ratio of blob to edge pixels.
        double ratio = blobCount / edgeCount;
    
        // Depth calculation
        // Couldn't get this to work so not going to send positon to update function.
        if (ratio > 0.3) {
            result->found = true;
        
            imageio::Image depth;
            depth.LoadFromString(images[1].data, images[1].length);
            for (int x=0; x < depth.GetWidth(); x++) {
                for (int y=0; y < depth.GetHeight(); y++) {
                    Color pixel = depth.GetPixel(x, y);
                    double r=0,g=0,b=0;

                    r = ((pixel[0]/255.0)-0.5)*2.0;
                    g = ((pixel[1]/255.0)-0.5)*2.0;
                    b = ((pixel[2]/255.0)-0.5)*2.0;
        
                    double ColorVec[3]={r,g,b};
                    double AbsDirVec = sqrt(pow(ColorVec[0],2)+pow(ColorVec[1],2)+pow(ColorVec[2],2));
                }
            }

    //Direction
    for (int i=0; i<3;i++){
        Direction[i]=DirVec[i]/AbsDirVec;
    }
    //Distance 
    Distance = ((1.0 - AbsDirVec)*50.0);
                }
            }
        } else {
            result->found = false;
        }
        
        std::cout << "Image filtered" << std::endl;

        return result;
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
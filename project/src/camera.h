#ifndef CAMERA_H_
#define CAMERA_H_ 
#include "camera_controller.h"
#include <fstream>

class Camera : public ICameraObserver {
private:
    ICameraController* controller;
    int id;

public:
    struct CameraResult : public ICameraResult {
        bool found;
        double pos[3];
    };

    Camera(int cameraId, ICameraController* controller) : id(id), controller(controller) {
        controller->AddObserver(*this);
    }
    ~Camera();
    void TakePicture();
    ICameraResult* ProcessImages(int cameraId, double xPos, double yPos, double zPos, const std::vector<RawCameraImage>& images, picojson::object& details) const;
    void ImageProcessingComplete(ICameraResult* result);
};

#endif
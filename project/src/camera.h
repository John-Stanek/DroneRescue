#ifndef CAMERA_H_
#define CAMERA_H_ 
#include "camera_controller.h"
#include <fstream>

/**
 * @brief Handles the logic for the drone's camera.
 * 
 */

class Camera : public ICameraObserver {
private:
    ICameraController* controller;
    int id;

public:
    struct CameraResult : public ICameraResult {
        bool found;
        double pos[3];
    };

    /**
     * @brief Construct a new Camera object
     * 
     * @param cameraId - the id of the camera. Should be the same as the drone's id.
     * @param controller - handles camera controls and observes.
     */

    Camera(int cameraId, ICameraController* controller) : id(id), controller(controller) {
        controller->AddObserver(*this);
    }

    /**
     * @brief Destroy the Camera object
     * 
     */

    ~Camera();

    /**
     * @brief Takes a picture and sends to ProcessImages function
     * 
     */

    void TakePicture();

    /**
     * @brief 
     * 
     * @param cameraId - camera Id.
     * @param xPos - x position of target object in image
     * @param yPos - y position of target object in image
     * @param zPos - z position of target object in image
     * @param images - images to be processed i.e. applied blob/edge detection to see if robot is present in the image.
     * @param details
     * @return ICameraResult* - If robot is found, robot position will be stored here.
     */

    ICameraResult* ProcessImages(int cameraId, double xPos, double yPos, double zPos, const std::vector<RawCameraImage>& images, picojson::object& details) const;
    void ImageProcessingComplete(ICameraResult* result);
};

#endif
#include "web_app.h"
#include <fstream>
#include "util/base64.h"
    
// ============================== TODO: DELETE! ==============================

// A simple camera class that can take pictures and process images assynchronously.
// This class should be deleted at the end of the day and moved behind the facade.
class WriteYourOwnCameraClass : public ICameraObserver {
public:
    // Structure the result however you like
    struct CameraResult : public ICameraResult {
        bool found;
        double pos[3];
    };

    // Constructor
    WriteYourOwnCameraClass(int cameraId, ICameraController* controller) : id(id), controller(controller) {
        controller->AddObserver(*this);
    }

    // Takes a picture using the specified camera id
    void TakePicture() {
        controller->TakePicture(id);
    }

    // Processes images asynchonously.  The returned camera result will be passed into the ImageProcessingComplete(...) method
    ICameraResult* ProcessImages(int cameraId, double xPos, double yPos, double zPos, const std::vector<RawCameraImage>& images, picojson::object& details) const {
        if (cameraId == id || cameraId < 0) {
            // These will output the image to files.  Ultimately this is just for debugging:
            std::ofstream colorFile ("color.jpg", std::ios::out | std::ios::binary);
            colorFile.write (reinterpret_cast<const char*>(images[0].data), images[0].length);
            std::ofstream depthFile ("depth.jpg", std::ios::out | std::ios::binary);
            depthFile.write (reinterpret_cast<const char*>(images[1].data), images[1].length);

            // Use the following to convert color and depth images to RGBA image from memory (inside your image class / perhaps with a new constructor):
            // int width, height, components;
            // unsigned char* buffer = stbi_load_from_memory((const unsigned char*)images[0].data, images[0].length(), &width, &height, &components, 4);
            // components = 4;

            // Generate the result of image processing.  This could include images using the Result class.
            CameraResult* result = new CameraResult();
            result->found = true;
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
    void ImageProcessingComplete(ICameraResult* result) {
        CameraResult& res = *static_cast<CameraResult*>(result);
        if (res.found) {
            std::cout << "The robot was found here: " << res.pos[0] << ", " << res.pos[1] << ", " << res.pos[1] << std::endl;
        }
        delete result;
    }

private:
    ICameraController* controller;
    int id;
};

// A simple example entity to get your started in the examples below.
// Move the functionality into your simulation facade and delete this class!
class DeleteThisDroneClass {
public:
    int id; double pos[3]; double dir[3]; double speed;
    void Update(double dt) {
       for (int i = 0; i < 3; i++) {
           pos[i] += speed*dir[i]*dt;
       }

       // Take a picture every 5 seconds with front camera
       time += dt;
       if (time-lastPictureTime > 5.0) {
           cameras[0]->TakePicture();
           lastPictureTime = time;
       }
    }
    void SetJoystick(double x, double y, double z, double a) {
        dir[0] = x; dir[1] = y; dir[2] = z;
    }

    std::vector<WriteYourOwnCameraClass*> cameras;
    float lastPictureTime = 0.0;
    float time = 0.0;

} deleteThisDrone;

// ============================== TODO: DELETE! ==============================



//*****************************************************************************************
// Edit the following functions to suit your needs.  Do most of the work inside the
// simulation facade and not here.  The primary purpose of these functions are to
// communicate with the UI.
//*****************************************************************************************



void WebApp::CreateEntity(picojson::object& entityData, ICameraController& cameraController) {
    // Creates an entity based on JSON data stored as an object.

    // Print out actual json:
    picojson::value val(entityData);
    std::cout << val.serialize() << std::endl;

    // Use your simulatin facade to create a new entity.
    // Below is an example on how to get data values from picojson.
    // The code should be in the factory, not here!
    if (entityData["name"].get<std::string>() == "drone") {
        deleteThisDrone.id = entityData["entityId"].get<double>();
        deleteThisDrone.speed = entityData["speed"].get<double>();

        // Get the position as an array
        picojson::array position = entityData["position"].get<picojson::array>();
        deleteThisDrone.pos[0] = position[0].get<double>();
        deleteThisDrone.pos[1] = position[1].get<double>();
        deleteThisDrone.pos[2] = position[1].get<double>();

        // Get the direction as an array
        picojson::array dir = entityData["direction"].get<picojson::array>();
        deleteThisDrone.dir[0] = dir[0].get<double>();
        deleteThisDrone.dir[1] = dir[1].get<double>();
        deleteThisDrone.dir[2] = dir[1].get<double>();

        // Create cameras for the entity.
        picojson::array cameras = entityData["cameras"].get<picojson::array>();
        for (int i = 0; i < cameras.size(); i++) {
            WriteYourOwnCameraClass* camera = new WriteYourOwnCameraClass(cameras[i].get<double>(), &cameraController);
            deleteThisDrone.cameras.push_back(camera);
        }
    }
}


void WebApp::Update(double dt) {
    // Updates the simulation.  This may be called multiple times per frame.

    // Below is an example of how to use keyboard commands:
    deleteThisDrone.SetJoystick(
        IsKeyDown("ArrowRight") ? 1 : (IsKeyDown("ArrowLeft") ? -1 : 0),
        IsKeyDown("w") ? 1 : (IsKeyDown("s") ? -1 : 0),
        IsKeyDown("ArrowUp") ? -1 : (IsKeyDown("ArrowDown") ? 1 : 0),
        IsKeyDown("a") ? 1 : (IsKeyDown("d") ? -1 : 0)
    );
    
    // Below is an example of how to update an entity.  
    // This code should be in the simulation facade, not here!
    deleteThisDrone.Update(dt);
}

void WebApp::FinishUpdate(picojson::object& returnValue) {
    // Called after all updating is done.

    // Below is an example of how to send the position and direction to the UI.  
    // In general you will want to loop through entities that have changed to update
    // their position and direction:
    picojson::object entity;
    entity["entityId"] = picojson::value((double)0);
    
    // Save the position as an array
    picojson::array pos;
    pos.push_back(picojson::value(deleteThisDrone.pos[0]));
    pos.push_back(picojson::value(deleteThisDrone.pos[1]));
    pos.push_back(picojson::value(deleteThisDrone.pos[2]));
    entity["pos"] = picojson::value(pos);

    // Save the direction as an array
    picojson::array dir;
    dir.push_back(picojson::value(deleteThisDrone.dir[0]));
    dir.push_back(picojson::value(deleteThisDrone.dir[1]));
    dir.push_back(picojson::value(deleteThisDrone.dir[2]));
    entity["dir"] = picojson::value(dir);

    // Send the compile picojson data to the UI in the returnValue variable
    returnValue["entity"+std::to_string(deleteThisDrone.id)] = picojson::value(entity);
}







//*****************************************************************************************
// The code below you probably will not need to touch.  These are the functions 
// that will talk to the UI over web sockets.
//*****************************************************************************************

WebApp::WebApp() : start(std::chrono::system_clock::now()), time(0.0), running(true) {
    imageProcessThread = new std::thread(&WebApp::ProcessImageQueue, this);
}

WebApp::~WebApp() {
    running = false;
    imageProcessCond.notify_all();
    imageProcessThread->join();
}

void WebApp::receiveJSON(picojson::value& val) {
    picojson::object data = val.get<picojson::object>();
    std::string cmd = data["command"].get<std::string>();
    picojson::object returnValue;
    returnValue["id"] = data["id"];
    ReceiveCommand(cmd, data, returnValue);
    picojson::value retVal(returnValue);
    sendJSON(retVal);
}

void WebApp::ReceiveCommand(const std::string& cmd, picojson::object& data, picojson::object& returnValue) {
    if (cmd == "image") {
        std::unique_lock<std::mutex> lock(imageProcessMutex);
        data["time"].set<double>(time);
        imageQueue.push(data);
        imageProcessCond.notify_all();
        return;
    }


    std::unique_lock<std::mutex> updateLock(updateMutex);
    if (cmd == "createEntity") {
        CreateEntity(data, *this);
    } 
    else if (cmd == "update") {
        std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
        std::chrono::duration<double> diff = end - start;
        double delta = diff.count() - time;
        time += delta;

        double simSpeed = data["simSpeed"].get<double>();
        delta *= simSpeed;

        if (delta > 0.1) {
            for (float f = 0.0; f < delta; f+=0.01) {
                Update(0.01);
            }
        }
        else {
            Update(delta);
        }
        FinishUpdate(returnValue);
    }
    else if (cmd == "keyup") {
        KeyUp(data["key"].get<std::string>(), data["keyCode"].get<double>());
    }
    else if (cmd == "keydown") {
        KeyDown(data["key"].get<std::string>(), data["keyCode"].get<double>());
    }
    else {
        std::cout << "Unknown command: " << cmd << " - " << picojson::value(data).serialize() << std::endl;
    }
}

void WebApp::KeyUp(const std::string& key, int keyCode) {
    keyValue[key] = 0;
}

void WebApp::KeyDown(const std::string& key, int keyCode) {
    keyValue[key] = 1;
}

bool WebApp::IsKeyDown(const std::string& key) {
    std::map<std::string,int>::iterator it = keyValue.find(key);
    if (it != keyValue.end()) {
        return it->second;
    } 

    return false;
}

void WebApp::TakePicture(int cameraId) {
    picojson::object obj;
    picojson::value val;
    obj["takePicture"] = picojson::value((double)cameraId);
    picojson::value v(obj);
    sendJSON(v);
}

void WebApp::ProcessImageQueue() {
    while (running) {
        std::unique_lock<std::mutex> lock(imageProcessMutex);
        if (imageQueue.size() > 0) {
            picojson::object data = imageQueue.front();
            imageQueue.pop();
            lock.unlock();
            
            std::vector<std::string> decodedImages;
            std::vector<RawCameraImage> imageData;
            
            const picojson::array& images = data["images"].get<picojson::array>();

            for (int i = 0; i < images.size(); i++) {
                std::string decoded = base64_decode(images[i].get<std::string>().substr(23));
                decodedImages.push_back(decoded);
                RawCameraImage rawImage;
                rawImage.data = reinterpret_cast<const unsigned char*>(decodedImages[i].c_str());
                rawImage.length = decoded.length();
                imageData.push_back(rawImage);
            }

            int cameraId = data["cameraId"].get<double>();
            const picojson::array& pos = data["position"].get<picojson::array>();

            for (int i = 0; i < cameraObservers.size(); i++) {
                ICameraResult* result = cameraObservers[i]->ProcessImages(
                    cameraId,
                    pos[0].get<double>(),
                    pos[1].get<double>(),
                    pos[2].get<double>(),
                    imageData,
                    data
                );
                if (result) {
                    std::unique_lock<std::mutex> updateLock(updateMutex);
                    cameraObservers[i]->ImageProcessingComplete(result);
                }
            }
        }
        else {
          imageProcessCond.wait(lock);
        }
    }
}

void WebApp::AddObserver(ICameraObserver& observer) {
    cameraObservers.push_back(&observer);
}

void WebApp::RemoveObserver(ICameraObserver& observer) {
    cameraObservers.erase(std::remove(cameraObservers.begin(), cameraObservers.end(), &observer), cameraObservers.end()); 
}
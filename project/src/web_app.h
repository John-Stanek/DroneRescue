#ifndef WEB_APP_H_
#define WEB_APP_H_

#include <map>
#include "WebServer.h"
#include "camera_controller.h"
#include <chrono>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>

#include "simulation.h"

/**
 * @brief Web App class. Logic for communication with a webpage.
 * 
 */

/// A Web Application Sever that communicates with a web page through web sockets.
class WebApp : public JSONSession, public ICameraController {
public:
    /**
     * @brief Construct a new Web App object. Initializes server
     * 
     */

    WebApp();
    
    /**
     * @brief Destroy the Web App object
     * 
     */

    virtual ~WebApp();

    // *******************************************
    // Methods used for simulation 
    // *******************************************

    /**
     * @brief Create a Entity based on JSON data stored as an object.
     * 
     * @param entityData 
     * @param cameraController 
     */

    void CreateEntity(picojson::object& entityData, ICameraController& cameraController);
    
    /**
     * @brief Updates the simulation.  This may be called multiple times per frame.
     * 
     * @param dt - Change in time.
     */
    
    void Update(double dt);

    /**
     * @brief Called after all updating is done.  Entity should be returned to the UI.
     * 
     * @param returnValue - pico json data being return to the front end.
     */
    
    void FinishUpdate(picojson::object& returnValue);

    /**
     * @brief Receives JSON from the web server
     * 
     * @param val 
     */

    void receiveJSON(picojson::value& val);

    /**
     * @brief Handles specific commands from the web server
     * 
     * @param cmd 
     * @param data 
     * @param returnValue 
     */
    
    void ReceiveCommand(const std::string& cmd, picojson::object& data, picojson::object& returnValue);
    /**
     * @brief Handles the key up command
     * 
     * @param key 
     * @param keyCode 
     */
    
    void KeyUp(const std::string& key, int keyCode);
    
    /**
     * @brief Handles the key down command
     * 
     * @param key 
     * @param keyCode 
     */


    void KeyDown(const std::string& key, int keyCode);

    /**
     * @brief Returns whether or not a key is pressed at any time
     * 
     * @param key 
     * @return true 
     * @return false 
     */

    bool IsKeyDown(const std::string& key);

    /**
     * @brief Takes picture for a specific camera
     * 
     * @param cameraId 
     */
    
    void TakePicture(int cameraId);

    /**
     * @brief Adds camera observers to the application
     * 
     * @param observer 
     */
    
    void AddObserver(ICameraObserver& observer);
    /**
     * @brief Removes camera observers from the application
     * 
     * @param observer 
     */

    void RemoveObserver(ICameraObserver& observer);

    /**
     * @brief Method that handles asynchronous image processing that runs on a separate thread
     * 
     */

    void ProcessImageQueue();
    

private:
	
	Simulation* simulation;
	
    // Used for tracking time since last update
    std::chrono::time_point<std::chrono::system_clock> start;
    // Stores current state of key presses
    std::map<std::string,int> keyValue;
    // The total time the server has been running.
    double time;
    // Camera observers
    std::vector<ICameraObserver*> cameraObservers;
    // Image processing queue used for processing pictures that were taken
    std::queue<picojson::object> imageQueue;
    // Thread that handles asynchronous processing
    std::thread *imageProcessThread;
    // For synchronizing with the image queue
    std::mutex imageProcessMutex;
    // For synchronizing with the commands and update
    std::mutex updateMutex;
    // Condition variable that is used to notify thread of new images
    std::condition_variable imageProcessCond;
    // Stores whether the application is running or not.
    bool running;
};


#endif

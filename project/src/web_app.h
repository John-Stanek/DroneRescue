#ifndef DRONE_APP_H_
#define DRONE_APP_H_

#include <map>
#include "WebServer.h"
#include <chrono>

/// A Web Application Sever that communicates with a web page through web sockets.
class WebApp : public JSONSession {
public:
    /// Initializes server
    WebApp() : start(std::chrono::system_clock::now()), time(0.0) {}
    /// Destructor
    virtual ~WebApp() {}
    

    // *******************************************
    // Methods used for simulation (edit these):
    // *******************************************

    /// Creates an entity based on JSON data stored as an object.
    void CreateEntity(picojson::object& entityData);
    /// Updates the simulation.  This may be called multiple times per frame.
    void Update(double dt);
    /// Called after all updating is done.  Entity should be returned to the UI.
    void FinishUpdate(picojson::object& returnValue);


    // *******************************************
    // Methods for processing images (edit these):
    // *******************************************

    // To be added soon....


    // *******************************************
    // Methods used for web page communication:
    // (You shouldn't need to touch these)
    // *******************************************

    /// Receives JSON from the web server
    void receiveJSON(picojson::value& val);
    /// Handles specific commands from the web server
    void ReceiveCommand(const std::string& cmd, picojson::object& data, picojson::object& returnValue);
    /// Handles the key up command
    void KeyUp(const std::string& key, int keyCode);
    /// Handles the key down command
    void KeyDown(const std::string& key, int keyCode);
    // Returns whether or not a key is pressed at any time
    bool IsKeyDown(const std::string& key);

private:
    // Used for tracking time since last update
    std::chrono::time_point<std::chrono::system_clock> start;
    // Stores current state of key presses
    std::map<std::string,int> keyValue;
    // The total time the server has been running.
    double time;
};


#endif

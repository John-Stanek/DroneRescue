#include "web_app.h"

// ============================== TODO: DELETE! ==============================

// A simple example entity to get your started in the examples below.
// Move the functionality into your simulation facade and delete this class!
class DeleteThisDroneClass {
public:
    int id; double pos[3]; double dir[3]; double speed;
    void Update(double dt) {
       for (int i = 0; i < 3; i++) {
           pos[i] += speed*dir[i]*dt;
       } 
    }
    void SetJoystick(double x, double y, double z, double a) {
        dir[0] = x; dir[1] = y; dir[2] = z;
    }

} deleteThisDrone;

// ============================== TODO: DELETE! ==============================



//*****************************************************************************************
// Edit the following functions to suit your needs.  Do most of the work inside the
// simulation facade and not here.  The primary purpose of these functions are to
// communicate with the UI.
//*****************************************************************************************



void WebApp::CreateEntity(picojson::object& entityData) {
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
    if (cmd == "createEntity") {
        CreateEntity(data);
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


#ifndef DRONE_H
#define DRONE_H

#include <iostream>
#include <vector>

#include "drone_movement.h"
#include "battery.h"
#include "entity.h"
#include "camera.h"

/**
 * @brief handles the drone logic
 * 
 */

class Drone : public Entity{
public:
    int id; 
    double speed; 
    bool final = false;
    bool patrol = false;
    bool beeline = false;
    double time = 0.0;
    double lastPictureTime = 0.0; 
    Camera* camera;
    DroneMovement* movement;
    Battery battery;

    /**
     * @brief Construct a new Drone object
     * 
     */

    Drone(ICameraController& cameraController);

    /**
     * @brief Destroy the Drone object
     * 
     */

    ~Drone();

    /**
     * @brief Construct a new Drone object
     * 
     * @param x - x position of drone.
     * @param y - y position of drone.
     * @param z - z position of drone.
     * @param name - name of drone.
     */

    Drone(double x, double y, double z, char* name);

    /**
     * @brief Set the drone speed
     * 
     * @param speed 
     */

    void SetSpeed(double speed);

    /**
     * @brief Update the drones position
     * 
     * @param dt - timestep
     * @param arrows - direction array that sets drone direction on arrow key press.
     * @param moves - boolean array that storing true/false for patrol/beeline movement patterns.
     *                
     */

    void Update(double dt, double arrows[4], bool moves[2]);

    /**
     * @brief Set the Joystick object
     * 
     * @param arrows - same as Update()
     * @param moves - same as Update()
     */

    void SetJoystick(double arrows[4], bool moves[2]);

    /**
     * @brief Get the position of the drone
     * 
     * @param index - x, y, or z coordinate 
     * @return double 
     */
    
    double GetPosition(int index);

    /**
     * @brief Get the speed of the drone.
     * 
     * @return double 
     */

    double GetSpeed();

    /**
     * @brief Get the Direction of the drone.
     * 
     * @param index - x, y, or z direction
     * @return double 
     */

    double GetDirection(int index);

    /**
     * @brief Get the Id of the drone
     * 
     * @return int 
     */

    int GetId();
};

#endif

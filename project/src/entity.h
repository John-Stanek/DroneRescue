#ifndef ENTITY_H_
#define ENTITY_H_

#include <iostream>
/**
 * @brief The Entity Class represents an entity object that is created by the simulation.
 *   All types of entities inherit from Entity, including: drones,robots,recharge stations, and hospitals.
 */

class Entity {
protected:

/**
* @brief Protected member variable values consisting of: 
* A double[3] array called pos for storing position values
* A double[3] array called dir for storing direction values
* Three double variables called x,y,z for storing position values
* An std::string value called name, for storing the name of the entity
* A double value called id for storing the ID of the entity
*
*/
    double pos[3];
    double dir[3];
    double x,y,z;
    std::string name;
    double id;
    

public:

	/**
     * @brief Two values with type boolean for enhancement purposes.
     * These are not used for the Entity Class but must exist because inherited 
     * classes use them
     * 
     */
	bool hasBattery = false;
	bool final = false;
    /**
     * @brief Construct a new Entity object
     * @return
     *   Returns a new instance of a the Entity class.
     */

    Entity();
    
    /**
     * @brief Construct a new Entity object
     * @return
     *   Returns a new instance of a the Entity class.
     * @param name - name for new entity to be called of type std::string
     */
    
    Entity(std::string name);

    /**
     * @brief Construct a new Entity object
     * @return Returns a new instance of the Entity class with given pos values.
     * @param x - represents entity's x/pos[0] attribute.
     * @param y - rerpesents entity's y/pos[1] attribute.
     * @param z - represents entity's z/pos[2] attribute.
     */

    Entity(double x, double y, double z);

    /**
     * @brief Gets the position value at index index.
     * 
     * @return A double value indicating one of x,y,z positions.
     */
     
	virtual double GetPosition(int index) {
	    return pos[index];
	};
	
	/**
     * @brief Gets the X position value.
     * 
     * @return Value of X with type double.
     */
    double GetX();

    /**
     * @brief Gets the Y position value.
     * 
     * @return Value of Y with type double.
     */
    double GetY();

    /**
     * @brief Gets the Z position value.
     * 
     * @return Value of Z with type double.
     */
     

    double GetZ();

    /**
     * @brief Set the X position value.
     * 
     * @param x - a double value for X to be set to
     */
    void SetX(double x);

    /**
     * @brief Set the Y position value.
     * 
     * @param y - a double value for Y to be set to
     */

    void SetY(double y);

    /**
     * @brief Set the Z position value.
     * 
     * @param z - a double value for Z to be set to
     */

    void SetZ(double z);

    
     /**
     * @brief Gets the Direction array.
     * 
     * @return Direction array with type double[].
     */
     
     double *GetDir();
     
     /**
     * @brief Sets the Direction array.
     * 
     * @param dir[3] - dir array with type double[3] for dir to be set to.
     */
     
     void SetDir(double dir[3]);
     
     /**
     * @brief Gets the Position array.
     * 
     * @return Position array with type double[].
     */
     
     double *GetPos();
     
     /**
     * @brief Sets the Position array.
     * 
     * @param pos[3] - pos array with type double[3] for pos to be set to.
     */
     
     void SetPos(double dir[3]);
     
     /**
     * @brief Sets the ID.
     * 
     * @param id - i  with type double for id to be set to.
     */
     
     void SetID(double id);
     
     /**
     * @brief Gets the id value.
     * 
     * @return ID value with type double.
     */
     
     double GetID();
     
     /**
     * @brief Sets the name.
     * 
     * @param n - n  with type std::string for name to be set to.
     */
     
     void SetName(std::string n);
     
     /**
     * @brief Gets the name value.
     * 
     * @return Name value with type std::string.
     */
     
     std::string GetName();
     
     /**
     * @brief Update the entity in the simulation. Virtual to be overridden by inherited entity types
     * @param dt - dt of time difference of type double to be used for calculations of how much to do each update period
     * 
     */
     
     virtual void Update(double dt){};
     
     /**
     * @brief Checks to see if the object has a battery
     * 
     * @return hasBattery with type bool.
     */

     bool CheckForBattery();
     
     
};

/**
 * @brief The Charger Class represents an charger object that is created by the simulation, inheriting from entity.
 *   Nothing inherits from Charger.
 */
class Charger: public Entity{
	public: 
	
	/**
     * @brief Construct a new Charger object
     * @return
     *   Returns a new instance of a the Charger class.
     */
	Charger();
	
	/**
     * @brief Construct a new Charger object
     * @return
     *   Returns a new instance of a the Charger class.
     * @param name - name for new charger to be called of type std::string
     */
	
	Charger(std::string name);
	
	/**
     * @brief Construct a new Charger object
     * @return Returns a new instance of the Charger class with given pos values.
     * @param x - represents entity's x/pos[0] attribute.
     * @param y - rerpesents entity's y/pos[1] attribute.
     * @param z - represents entity's z/pos[2] attribute.
     */
	
	Charger(double x, double y, double z);
};

/**
 * @brief The Robot Class represents an robot object that is created by the simulation, inheriting from entity.
 *   Nothing inherits from Robot.
 */
class Robot: public Entity{
	public:
	
	/**
     * @brief Construct a new Robpt object
     * @return
     *   Returns a new instance of a the Robot class.
     */
	Robot();
	
	/**
     * @brief Construct a new Robot object
     * @return
     *   Returns a new instance of a the Robot class.
     * @param name - name for new robot to be called of type std::string
     */
	
	Robot(std::string name);
	
	/**
     * @brief Construct a new Robot object
     * @return Returns a new instance of the Robot class with given pos values.
     * @param x - represents entity's x/pos[0] attribute.
     * @param y - rerpesents entity's y/pos[1] attribute.
     * @param z - represents entity's z/pos[2] attribute.
     */
	
	Robot(double x, double y, double z);
};

/**
 * @brief The Hospital Class represents an hospital object that is created by the simulation, inheriting from entity.
 *   Nothing inherits from hospital.
 */
class Hospital: public Entity{
	public: 
	
	/**
     * @brief Construct a new Hospital object
     * @return
     *   Returns a new instance of a the Hospital class.
     */
	Hospital();
	
	/**
     * @brief Construct a new Hospital object
     * @return
     *   Returns a new instance of a the Hospital class.
     * @param name - name for new hospital to be called of type std::string
     */
	
	Hospital(std::string name);
	
	/**
     * @brief Construct a new Hospital object
     * @return Returns a new instance of the Hospital class with given pos values.
     * @param x - represents entity's x/pos[0] attribute.
     * @param y - rerpesents entity's y/pos[1] attribute.
     * @param z - represents entity's z/pos[2] attribute.
     */
	
	Hospital(double x, double y, double z);
};
#endif

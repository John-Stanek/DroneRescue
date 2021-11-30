#ifndef ENTITY_H_
#define ENTITY_H_

#include <iostream>
/**
 * @brief The Color Class represents the RGBA values of a pixel.
 *   Has no parent or child classes.
 */

class Entity{
protected:
    double pos[3];
    double dir[3];
    double x,y,z;
    char *name;
    double id;

public:
    /**
     * @brief Construct a new Color object
     * @return
     *   Returns a new instance of a the Color class.
     */

    Entity();
    
    
    Entity(char *name);

    /**
     * @brief Construct a new Color object
     * @return Returns a new isntance of the Color class with given RGB values.
     * @param red - represents pixel's Red attribute.
     * @param green - rerpesents the pixel's Green attribute.
     * @param blue - represents the pixel's Blue attribute.
     * @param alpha - represents the pixel's alpha attribute.
     */

    Entity(double x, double y, double z);

    /**
     * @brief Gets the red pixel value.
     * 
     * @return value of red with type float.
     */

    double GetX();

    /**
     * @brief Gets the red pixel value.
     * 
     * @return Value of red with type float.
     */
    double GetY();

    /**
     * @brief Gets blue pixel value.
     * 
     * @return Value of blue with type float.
     */


    double GetZ();

    /**
     * @brief Gets blue alpha value.
     * 
     * @return Value of alpha with type float.
     */

    void SetX(double x);

    /**
     * @brief Set the green pixel value.
     * 
     * @param green - a float value for green to be set to
     */

    void SetY(double y);

    /**
     * @brief Set the blue pixel value.
     * 
     * @param blue - a float value for blue to be set to
     */

    void SetZ(double z);

    /**
     * @brief Set the alpha pixel value.
     * 
     * @param red - a float value for alpha to be set to
     */
     
     double *GetDir();
     
     void SetDir(double dir[3]);
     
     void SetID(double id);

	
};

class Charger: public Entity{
	public: 
	Charger();
	
	Charger(char *name);
	
	Charger(double x, double y, double z);
};

class Drone: public Entity{
	private: 
	    double speed;
	public: 
	Drone();
	
	Drone(char *name);
	
	Drone(double x, double y, double z);
	
	void SetSpeed(double speed);
	
	double GetSpeed();
};

class Robot: public Entity{
	public:
	Robot();
	
	Robot(char *name);
	
	Robot(double x, double y, double z);
};

class Hospital: public Entity{
	public: 
	Hospital();
	
	Hospital(char *name);
	
	Hospital(double x, double y, double z);
};
#endif
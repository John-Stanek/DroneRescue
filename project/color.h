#include <iostream>

#ifndef COLOR_H_
#define COLOR_H_

<<<<<<< HEAD
<<<<<<< HEAD
=======
=======
>>>>>>> 1c0c69de7258b9db6898dcb004439a8386cb3917
/**
 * @brief The Color Class represents the RGBA values of a pixel.
 *   Has no parent or child classes.
 */

<<<<<<< HEAD
>>>>>>> 7e2e8d21cf6e8d747e5349630cdd94e55e4699aa
=======
>>>>>>> 1c0c69de7258b9db6898dcb004439a8386cb3917
class Color{
private:
    float red;
    float green;
    float blue;
    float alpha;

public:
<<<<<<< HEAD
<<<<<<< HEAD
    Color();
    Color(float red, float green, float blue, float alpha);
    float Red();
    float Green();
    float Blue();
    float Alpha();
    void SetRed(float red);
    void SetGreen(float green);
    void SetBlue(float blue);
    void SetAlpha(float alpha);
    Color operator=(float scalar);
    Color operator=(const Color& color);
    Color operator+(float scalar);
    Color operator+(const Color& color);
    Color operator-(float scalar);
    Color operator-(const Color& color);
=======
=======
>>>>>>> 1c0c69de7258b9db6898dcb004439a8386cb3917
    /**
     * @brief Construct a new Color object
     * @return
     *   Returns a new instance of a the Color class.
     */

    Color();

    /**
     * @brief Construct a new Color object
     * @return Returns a new isntance of the Color class with given RGB values.
     * @param red - represents pixel's Red attribute.
     * @param green - rerpesents the pixel's Green attribute.
     * @param blue - represents the pixel's Blue attribute.
     * @param alpha - represents the pixel's alpha attribute.
     */

    Color(float red, float green, float blue, float alpha);

    /**
     * @brief Gets the red pixel value.
     * 
     * @return value of red with type float.
     */

    float Red();

    /**
     * @brief Gets the red pixel value.
     * 
     * @return Value of red with type float.
     */
    float Green();

    /**
     * @brief Gets blue pixel value.
     * 
     * @return Value of blue with type float.
     */


    float Blue();

    /**
     * @brief Gets blue alpha value.
     * 
     * @return Value of alpha with type float.
     */

    float Alpha();

    /**
     * @brief Set the red pixel value.
     * 
     * @param red - a float value for red to be set to
     */

    void SetRed(float red);

    /**
     * @brief Set the green pixel value.
     * 
     * @param green - a float value for green to be set to
     */

    void SetGreen(float green);

    /**
     * @brief Set the blue pixel value.
     * 
     * @param blue - a float value for blue to be set to
     */

    void SetBlue(float blue);

    /**
     * @brief Set the alpha pixel value.
     * 
     * @param red - a float value for alpha to be set to
     */

    void SetAlpha(float alpha);

    /**
     * @brief Overloads the = operator.
     * 
     * @param scalar - a float value all rgba will be set to. 
     * @return The modified instance of the Color object.
     */

    Color operator=(float scalar);

    /**
     * @brief Overloads the = operator.
     * 
     * @param color - an instance of the Color object to be set to.
     */

    Color operator=(const Color& color);

    /**
     * @brief Overloads the + operator.
     * 
     * @param scalar - the float value to be add to each of RGBA. 
     * @return Modified instance of the Color object afte RGBA addition.
     */

    Color operator+(float scalar);

    /**
     * @brief Overloads the + operator.
     * 
     * @param color - A Color object whos RGBA will be added to this.
     * @return Modified instance of the Color object after RGBA addition.
     */

    Color operator+(const Color& color);

    /**
     * @brief Overlaods the - operator.
     * 
     * @param scalar - A float value to be added to this rgba values;
     * @return Color - The modified Color object, this.
     */

    Color operator-(float scalar);

    /**
     * @brief Overloads the - operator.
     * 
     * @param color - A constant reference to a Color object to be subtracted from this.
     * @return Color - The modified Color object, this.
     */

    Color operator-(const Color& color);

    /**
     * @brief Overloads the * operator
     * 
     * @param scalar - A float value to be multiplied to each RGBA value in this.
     * @return Color - The modified Color object, this.
     */

<<<<<<< HEAD
>>>>>>> 7e2e8d21cf6e8d747e5349630cdd94e55e4699aa
=======
>>>>>>> 1c0c69de7258b9db6898dcb004439a8386cb3917
    Color operator*(float scalar);
};

#endif

#include<iostream>
#include<string>
#include "color.h"
#ifndef IMAGE_H_
#define IMAGE_H_

<<<<<<< HEAD
<<<<<<< HEAD
=======
=======
>>>>>>> 1c0c69de7258b9db6898dcb004439a8386cb3917
/**
 * @brief The class for loading and saving images.
 *   
 */

<<<<<<< HEAD
>>>>>>> 7e2e8d21cf6e8d747e5349630cdd94e55e4699aa
=======
>>>>>>> 1c0c69de7258b9db6898dcb004439a8386cb3917
class Image {
private:
    int width;
    int height;
    int components;
    unsigned char* image;

public:
<<<<<<< HEAD
<<<<<<< HEAD
    Image();
    Image(int width, int height);
    Image(const char* filename);
    Image(const Image& img);
    Image operator=(const Image& img);
    ~Image();
    int GetHeight();
    int GetWidth();
    int GetComponentNum();
    unsigned char* testpixel(int x, int y);
    Color GetPixel(int x, int y);
    void SetPixel(int x, int y, Color& rgba);
    void SaveAs(const char* filename);
    void swap(Image& first, Image& second);
=======
=======
>>>>>>> 1c0c69de7258b9db6898dcb004439a8386cb3917
    /**
     * @brief Construct a new Image object
     *   Initializes height and width to 0 and components to 4.
     *   Allocates a byte array of size width*height*components, in this case of size 0;
     * 
     */

    Image();

    /**
     * @brief Construct a new Image object
     *      Initializes width, height, and components. Components automatically set to 4.
     *      Allocates byte array of size width*height*components. 
     * @param width - an integer value for the width of the image to be set to.
     * @param height - an integer value for the height of the image to be set to.
     */

    Image(int width, int height);

    /**
     * @brief Construct a new Image object
     *      Loads an image using the stbi library based on the given file.
     * @param filename - a file path, of an image, to be loaded.
     */

    Image(const char* filename);

    /**
     * @brief Copy Constructor. Construct a new Image object
     * 
     * @param img - A constant reference to an Image object to be copied.
     */

    Image(const Image& img);

    /**
     * @brief Overloads the = operator.
     * 
     * @param img - A constant reference to an Image object for "this" to be set to.
     * @return Image - The modified instance - "this" - of the Color object.
     */

    Image operator=(const Image& img);

    /**
     * @brief Destroy the Image object
     *      More specifically deletes the memory allocated for the image byte array.
     * 
     */

    ~Image();

    /**
     * @brief Get the height of the object
     * 
     * @return int value representing the height of the image.
     */

    int GetHeight();

    /**
     * @brief Get the width object
     * 
     * @return int value representing the width of the image.
     */

    int GetWidth();

    /**
     * @brief Get the number of components in the object.
     * 
     * @return int value representing how many components the Image object has.
     */

    int GetComponentNum();

    /**
     * @brief Get a specific pixel from the image object
     * 
     * @param x - the x coordinate value of the pixel.
     * @param y - the y coordinate value of the pixel.
     * @return Color - A Color object representing the RGBA values of the pixel.
     *      Unsigned char values are converted to float values for pixel manipulation.
     */

    Color GetPixel(int x, int y);

    /**
     * @brief Sets the RGBA values of a pixel.
     * 
     * @param x - the x coordinate of the pixel value.
     * @param y - the y coordinate of the pixel value.
     * @param rgba - A color object for the pixel RGBA values to be set to.
     */

    void SetPixel(int x, int y, Color& rgba);

    /**
     * @brief Uses the stbi library to save an Image object to a file. The saved file will be the filtered image.
     * 
     * @param filename - a file path to which the image will be saved.
     */

    void SaveAs(const char* filename);

<<<<<<< HEAD
>>>>>>> 7e2e8d21cf6e8d747e5349630cdd94e55e4699aa
=======
>>>>>>> 1c0c69de7258b9db6898dcb004439a8386cb3917
};

#endif
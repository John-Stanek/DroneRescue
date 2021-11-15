/*! \mainpage Search And Rescue Drone 
 *
 * \section intro_sec Introduction
 *
 * This is the API for the Search and Rescue Drone system.
 *\n
 * \section Canny Edge Detection Filter
 *
 * This is a colllaborative project between four students to create a canny edge detect filter.
 * It utilizes the use of many different filters to create an outlined picture. When given an image as an input, it will output a black image with white outlines of important figures and/or shapes found in the original image.
 * 
 * \n\n 
 * This project can be made by running "make" in the terminal with the given make file. This will successfully compile the code, which can then be run with the following: \n
 * "./image_processor <input image> canny-edge-detect <output image>"\n
 * \n
 * This project contains one of each of the following different filter types: Canny Edge Filter, Double Threshold Filter, Non-Max Suppression Filter, Hysteresis Filter, White Noise Filter, Sharpen Filter, Gaussian Blur Filter, And Sobel Filter.\n
 *
 * A new filter can be easily added by inheriting from the base Filter class described in filter.h, and creating an appropriate Apply() Method.
 */

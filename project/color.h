#include <iostream>

#ifndef COLOR_H_
#define COLOR_H_

class Color{
private:
    float red;
    float green;
    float blue;
    float alpha;

public:
    Color();
    Color(float red, float green, float blue, float alpha);
    float Red();
    float Green();
    float Blue();
    float Alpha();
    Color operator=(float scalar);
    Color operator=(const Color& color);
    Color operator+(float scalar);
    Color operator+(const Color& color);
    Color operator*(float scalar);
};

#endif
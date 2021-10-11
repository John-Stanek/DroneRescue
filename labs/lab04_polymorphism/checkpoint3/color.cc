# include "color.h"

Color::Color() {
    red = blue = green = alpha = 0;
}

Color::Color(float red, float green, float blue, float alpha) {
    this->red = red;
    this->green = green; 
    this->blue = blue;
    this->alpha = alpha;
}

float Color::Red() {
    return red;
}

float Color::Green() {
    return green;
}

float Color::Blue() {
    return blue;
}

float Color::Alpha() {
    return alpha;
}

Color Color::operator=(float scalar) {
    this->red = scalar;
    this->green = scalar;
    this->blue = scalar;
    return *this;
}

Color Color::operator=(const Color& color) {
    this->red = color.red;
    this->green = color.green;
    this->blue = color.blue;
    this->alpha = color.alpha;
    return *this;
}

Color Color::operator+(const Color& color) {
    this->red += color.red;
    this->green += color.green;
    this->blue += color.blue;
    return *this;
}

Color Color::operator+(float scalar) {
    this->red += scalar;
    this->green += scalar;
    this->blue += scalar;
    return *this;
}

Color Color::operator*(float scalar) {
    this->red *= scalar;
    this->green *= scalar;
    this->blue *= scalar;
    return *this;
}


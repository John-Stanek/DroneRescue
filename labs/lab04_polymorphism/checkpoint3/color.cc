# include "color.h"

Color::Color() {
    red = blue = green = alpha = 0;
}

Color::Color(float red, float green, float blue, float alpha) {
    red = red, green = green, blue = blue, alpha = alpha;
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

Color Color::operator=(const Color& color) {
    this->red = color.red;
    this->green = color.green;
    this->blue = color.blue;
    this->alpha = color.alpha;
    return *this;
}

Color Color::operator+(float scalar) {
    this->red += scalar;
    this->green += scalar;
    this->blue += scalar;
    this->alpha += scalar;
    return *this;
}

Color Color::operator*(float scalar) {
    this->red *= scalar;
    this->green *= scalar;
    this->blue *= scalar;
    this->alpha *= scalar;
    return *this;
}

Color Color::operator-(float scalar) {
    this->red -= scalar;
    this->green -= scalar;
    this->blue -= scalar;
    this->alpha -= scalar;
    return *this;
}

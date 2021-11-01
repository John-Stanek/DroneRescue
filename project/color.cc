# include "color.h"

Color::Color() {
    red = 0;
    green = 0;
    blue = 0;
    alpha = 0;
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

void Color::SetRed(float red) {
	this->red = red;
}

void Color::SetGreen(float green) {
	this->green = green;
}

void Color::SetBlue(float blue) {
	this->blue = blue;
}

void Color::SetAlpha(float alpha) {
	this->alpha = alpha;
}

Color Color::operator=(float scalar) {
    this->red = scalar;
    this->green = scalar;
    this->blue = scalar;
    this->alpha = scalar;
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
    this->alpha += color.alpha;
    return *this;
}

Color Color::operator+(float scalar) {
    this->red += scalar;
    this->green += scalar;
    this->blue += scalar;
    this->alpha += scalar;
    return *this;
}

Color Color::operator-(const Color& color) {
    this->red -= color.red;
    this->green -= color.green;
    this->blue -= color.blue;
    this->alpha -= color.alpha;
    return *this;
}

Color Color::operator-(float scalar) {
    this->red -= scalar;
    this->green -= scalar;
    this->blue -= scalar;
    this->alpha -= scalar;
    return *this;
}

Color Color::operator*(float scalar) {
    this->red *= scalar;
    this->green *= scalar;
    this->blue *= scalar;
    this->alpha *= scalar;
    return *this;
}


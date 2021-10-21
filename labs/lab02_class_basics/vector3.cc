#include "vector3.h"

#include <iostream>
using namespace std;

Vector3::Vector3() {
    x = 0, y = 0, z = 0;
}

Vector3::Vector3(float xVal, float yVal, float zVal) {
    x = xVal, y = yVal; z = zVal;
}

Vector3 Vector3::operator+(Vector3 vec) {
    return Vector3(x + vec.x, y + vec.y, z + vec.z); 
}

Vector3 Vector3::operator-(Vector3 vec) {
    return Vector3(x - vec.x, y - vec.y, z - vec.z);
}

Vector3 Vector3::operator*(float num) {
    return Vector3(num * x, num * y, num * z);    
}

Vector3 Vector3::operator/(float num) {
    return Vector3(x / num, y / num, z / num);
}

void Vector3::Print() {
    cout << "[" << x << ", " << y << ", " << z << "]" << endl;
}

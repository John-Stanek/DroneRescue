#ifndef VECTOR3_H_
#define VECTOR3_H_

class Vector3 {
private:
    float x;
    float y;
    float z;

public:
    Vector3();
    Vector3(float x, float y, float z);
    Vector3 operator+(const Vector3 &vec);
    Vector3 operator-(const Vector3 &vec);
    Vector3 operator*(float num);
    Vector3 operator/(float num);
    void Print();
};

#endif

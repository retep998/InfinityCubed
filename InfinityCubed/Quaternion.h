#pragma once
#include "Vector.h"
class Quaternion {
public:
    Quaternion();
    Quaternion(double x, double y, double z, double w);
    Quaternion(Vector3, double angle);
    void Normalize();
    Quaternion Conjugate() const;
    Quaternion operator*(Quaternion) const;
    Vector3 operator*(Vector3) const;
    void LoadMatrix(GLint) const;
    double x, y, z, w;
};
#pragma once
class Vector3 {
public:
    Vector3();
    Vector3(double x, double y, double z);
    void Normalize();
    double x, y, z;
};
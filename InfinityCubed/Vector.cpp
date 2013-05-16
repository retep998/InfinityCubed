#include "Main.h"
#include "Vector.h"
Vector3::Vector3() : x(0), y(0), z(0) {}
Vector3::Vector3(double x, double y, double z) : x(x), y(y), z(z) {}
void Vector3::Normalize() {
    double m = 1 / sqrt(x * x + y * y + z * z);
    x *= m;
    y *= m;
    z *= m;
}
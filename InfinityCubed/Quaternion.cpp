//#include "Main.h"
//#include "Quaternion.h"
//#include "Vector.h"
//Quaternion::Quaternion() : x(0), y(0), z(0), w(1) {}
//Quaternion::Quaternion(double x, double y, double z, double w) : x(x), y(y), z(z), w(w) {}
//Quaternion::Quaternion(Vector3 v, double angle) {
//    angle *= 0.5;
//    v.Normalize();
//    double s = sin(angle);
//    x = v.x * s;
//    y = v.y * s;
//    z = v.z * s;
//    w = cos(angle);
//}
//void Quaternion::Normalize() {
//    double m = 1 / sqrt(x * x + y * y + z * z + w * w);
//    x *= m;
//    y *= m;
//    z *= m;
//    w *= m;
//}
//Quaternion Quaternion::Conjugate() const {
//    return Quaternion(-x, -y, -z, w);
//}
//Quaternion Quaternion::operator*(Quaternion q) const {
//    return Quaternion(w * q.x + x * q.w + y * q.z - z * q.y,
//                      w * q.y + y * q.w + z * q.x - x * q.z,
//                      w * q.z + z * q.w + x * q.y - y * q.x,
//                      w * q.w - x * q.x - y * q.y - z * q.z);
//}
//Vector3 Quaternion::operator*(Vector3 v) const {
//    v.Normalize();
//    Quaternion q(v.x, v.y, v.z, 0);
//    Quaternion r = *this * (q * Conjugate());
//    return Vector3(r.x, r.y, r.z);
//}
//void Quaternion::LoadMatrix(GLint loc) const {
//    float v[16] = {1 - 2 * (y * y + z * z), 2 * (x * y - w * z), 2 * (x * z + w * y), 0,
//                   2 * (x * y + w * z), 1 - 2 * (x * x + z * z), 2 * (y * z - w * x), 0,
//                   2 * (x * z - w * y), 2 * (y * z + w * x), 1 - 2 * (x * x + y * y), 0,
//                   0, 0, 0, 1};
//    glUniformMatrix4fv(loc, 1, GL_FALSE, v);
//}
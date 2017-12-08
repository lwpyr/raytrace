//
// Created by liwen on 17-12-7.
//

#include "Vector3.h"

Vector3::Vector3(const Vector3& v){
    x = v.x;
    y = v.y;
    z = v.z;
}

Vector3::Vector3(float X, float Y, float Z):x(X),y(Y),z(Z){

}

Vector3 Vector3::operator+(const Vector3& v) const {
    return Vector3(x + v.x, v.y + y, v.z + z);
}

Vector3 Vector3::operator-(const Vector3& v) const {
    return Vector3(x - v.x, y - v.y, z - v.z);
}

Vector3 Vector3::operator*(const float& n) const {
    return Vector3(x*n, y*n, z*n);
}

Vector3 operator*(const float& n, const Vector3& v){
    return Vector3(v.x*n, v.y*n, v.z*n);
}

Vector3 Vector3::operator/(const float& n) const{
    return Vector3(x/n, y/n, z/n);
}

Vector3 operator/(const float& n, const Vector3& v){
    return Vector3(n/v.x, n/v.y, n/v.z);
}

Vector3 Vector3::abs() const{
    float _x = x, _y = y, _z = z;
    if(x<0) _x*=-x;
    if(y<0) _y*=-1;
    if(z<0) _z*=-1;
    return Vector3(_x, _y, _z);
}

float Vector3::operator*(const Vector3& v2) const{
    return (x*v2.x + y*v2.y + z*v2.z);
}

Vector3 Vector3::operator^(const Vector3& v2) const{
    return Vector3(((y * v2.z) - (z * v2.y)),
                   ((z * v2.x) - (x * v2.z)),
                   ((x * v2.y) - (y * v2.x)));
}

float Vector3::getLength() const{
    return (float)sqrt(x*x+y*y+z*z);
}

Vector3 Vector3::normalize() const {
    float length=getLength();
    return Vector3(x/length,y/length,z/length);
}

Vector3 Vector3::operator-() const {
    return Vector3(-x,-y,-z);
}

float Vector3::max() const {
    float tmp=MAX(y,z);
    return MAX(x,tmp);
}

float Vector3::min() const {
    float tmp=MIN(y,z);
    return MIN(x,tmp);
}

float Vector3::getDist(Vector3& v) const {
    float tmp=(x - v.x)*(x - v.x) +
            (y - v.y)*(y - v.y) +
            (z - v.z)*(z - v.z);
    return (float)sqrt(tmp);
}

Vector3 Vector3::project(Vector3 &v) const {
    return Vector3(x*v.x,y*v.y,z*v.z);
}
//
// Created by liwen on 17-12-7.
//

#include "Vector3.h"

Vector3::Vector3(double X, double Y, double Z):x(X),y(Y),z(Z){

}

Vector3 Vector3::operator+(const Vector3& v) const {
    return Vector3(x + v.x, v.y + y, v.z + z);
}

Vector3 Vector3::operator-(const Vector3& v) const {
    return Vector3(x - v.x, y - v.y, z - v.z);
}

Vector3 Vector3::operator*(const double& n) const {
    return Vector3(x*n, y*n, z*n);
}

Vector3 operator*(const double& n, const Vector3& v){
    return Vector3(v.x*n, v.y*n, v.z*n);
}

Vector3 Vector3::operator/(const double& n) const{
    return Vector3(x/n, y/n, z/n);
}

Vector3 operator/(const double& n, const Vector3& v){
    return Vector3(n/v.x, n/v.y, n/v.z);
}

Vector3 Vector3::abs() const{
    double _x = x, _y = y, _z = z;
    if(x<0) _x*=-x;
    if(y<0) _y*=-1;
    if(z<0) _z*=-1;
    return Vector3(_x, _y, _z);
}

double Vector3::operator*(const Vector3& v2) const{
    return (x*v2.x + y*v2.y + z*v2.z);
}

Vector3 Vector3::operator^(const Vector3& v2) const{
    return Vector3(((y * v2.z) - (z * v2.y)),
                   ((z * v2.x) - (x * v2.z)),
                   ((x * v2.y) - (y * v2.x)));
}

double Vector3::getLength() const{
    return (double)sqrt(x*x+y*y+z*z);
}

Vector3 Vector3::normalize() const {
    double length=getLength();
    return Vector3(x/length,y/length,z/length);
}

Vector3 Vector3::operator-() const {
    return Vector3(-x,-y,-z);
}

double Vector3::max() const {
    double tmp=MAX(y,z);
    return MAX(x,tmp);
}

double Vector3::min() const {
    double tmp=MIN(y,z);
    return MIN(x,tmp);
}

double Vector3::getDist(Vector3& v) const {
    double tmp=(x - v.x)*(x - v.x) +
            (y - v.y)*(y - v.y) +
            (z - v.z)*(z - v.z);
    return (double)sqrt(tmp);
}

Vector3 Vector3::project(Vector3 &v) const {
    return (*this*v) *v.normalize();
}

std::ostream& operator<<(std::ostream &out, Vector3 &v) {
    out<<'('<<v.x<<' '<<v.y<<' '<<v.z<<')';
    return out;
}
//
// Created by liwen on 17-12-7.
//

//
// Created by liwen on 17-12-5.
//

#include "Ray3.h"

Ray3::Ray3(const Vector3& o,const Vector3& d){
    origin=o;
    direction=d.normalize();
}

Ray3::Ray3(const Ray3& r){
    origin = r.origin;
    direction = r.direction;
}

void Ray3::setOrigin(const Vector3& o){
    origin = o;
}

void Ray3::setDirection(const Vector3& d){
    direction = d.normalize();
}

Vector3 Ray3::getDirection() const
{
    return direction;
}
Vector3 Ray3::getOrigin() const
{
    return origin;
}
Vector3 Ray3::getPoint(const double& t) const
{
    return origin+direction*t;
}

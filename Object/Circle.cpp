//
// Created by liwen on 6/25/18.
//

#include "Circle.h"

Vector3 Circle::getNormal(Vector3 point) {
    return normal;
}

Intersection Circle::isIntersected(const Ray3 &ray) {
    Intersection result;
    Vector3 o = ray.getOrigin();
    Vector3 d = ray.getDirection();
    double t = ((center-o)*normal) / (d*normal);
    if(t>0){
        double dist = (ray.getPoint(t)-center).getLength();
        if( dist<= radius){
            result.isHit=1;
            result.object = this;
            result.distance = t;
            result.position = ray.getPoint(t);
            result.normal = normal;
        }
    }
    return result;
}

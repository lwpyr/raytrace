//
// Created by liwen on 6/27/18.
//

#include "Square.h"

Square::Square(const Vector3 &_refPoint, const Vector3 & _normal, const Vector3 &_side1, const Vector3 &_side2, double _side1L, double _side2L) {
    refPoint = _refPoint;
    side1 = _side1.normalize();
    side2 = _side2.normalize();
    side1L = _side1L;
    side2L = _side2L;
    normal = _normal.normalize();
}

Vector3 Square::getNormal(Vector3 point) {
    return normal;
}

Intersection Square::isIntersected(const Ray3 &ray) {
    Intersection result;
    Vector3 v = ray.getOrigin() - refPoint;
    Vector3 d = ray.getDirection();
    double vn = v*normal;
    double dn = d*normal;
    if(dn!=0){
        Vector3 temp_normal = normal;
        if(dn>0)
            temp_normal = -normal;
        double distance = - vn/dn;
        Vector3 pos_ref = ray.getPoint(distance)-refPoint;
        if(distance>1e-4&&distance<ray.max_distance&&fabs(pos_ref*side1)<=side1L&&fabs(pos_ref*side2)<=side2L){
            result.isHit=1;
            result.object = this;
            result.distance = distance;
            result.position = ray.getPoint(distance);
            result.normal = temp_normal;
            return result;
        }
    }
    return result;
}
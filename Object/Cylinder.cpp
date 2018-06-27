//
// Created by liwen on 6/26/18.
//

#include "Cylinder.h"

Cylinder::Cylinder(Vector3 _center, Vector3 _axis, double _radius, double _height) {
    center = _center;
    axis = _axis.normalize();
    radius = _radius;
    height = _height;
}

Vector3 Cylinder::getNormal(Vector3 point) {
    Vector3 cp = point-center;
    Vector3 proj = cp.project(axis);
    return (cp - proj).normalize();
}

Intersection Cylinder::isIntersected(const Ray3 &ray) {
    Intersection result;

    double a = ray.direction*ray.direction - pow(axis*ray.direction, 2);
    double b = (2*ray.origin - 2*center)*ray.direction - ((2*ray.origin - 2*center)*axis) * (ray.direction*axis);
    double c = (ray.origin - center)*(ray.origin - center) - pow((ray.origin - center)*axis, 2) - radius*radius;

    double delta = b*b - 4*a*c;
    if(delta>0){
        delta = sqrtf(delta);
        double distance1 = (-b - delta)/2/a;
        double distance2 = (-b + delta)/2/a;
        result.isHit = 1;
        result.object = this;
        if(distance1>1e-3&&distance1<ray.max_distance&&getCenterDist(ray.getPoint(distance1))<=height/2){
            result.distance = distance1;
            result.position= ray.getPoint(distance1);
            result.normal = getNormal(result.position);
        }
        else if(distance2>1e-3&&distance2<ray.max_distance&&getCenterDist(ray.getPoint(distance2))<=height/2){
            result.distance = distance2;
            result.position=ray.getPoint(distance2);
            result.normal = - getNormal(result.position);
        }
    }
    return result;
}

double Cylinder::getCenterDist(const Vector3 & p) {
    return fabs((p - center)*axis);
}

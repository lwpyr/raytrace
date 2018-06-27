//
// Created by liwen on 12/20/17.
//

#include "Sphere.h"

Sphere::Sphere(Vector3 c,double r)
{
    center=c;
    radius=r;
}
Vector3 Sphere::getNormal(Vector3 p)
{
    return (p-center).normalize();
}
Intersection Sphere::isIntersected(const Ray3& ray)
{
    Intersection result;
    Vector3 v = ray.getOrigin() - center;
    Vector3 d = ray.getDirection();
    double _dv = d*v;
    double _vv = v*v;

    double delta = _dv*_dv-(_vv-radius*radius);

    if(delta>0){
        double distance1 = (-_dv-sqrt(delta));
        double distance2 = (-_dv+sqrt(delta));
        result.isHit = 1;
        result.object = this;
        if(distance1>1e-3&&distance1<ray.max_distance){
            result.distance = distance1;
            result.position=ray.getPoint(distance1);
            result.normal = (result.position - center).normalize();
        }
        else if(distance2>1e-3&&distance2<ray.max_distance){
            result.distance = distance2;
            result.position=ray.getPoint(distance2);
            result.normal = (result.position - center).normalize();
        }
    }
    return result;
}
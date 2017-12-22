//
// Created by liwen on 12/20/17.
//

#include "Triangle.h"

Triangle::Triangle(Vector3 v1, Vector3 v2, Vector3 v3) {
    p1 = v1;
    p2 = v2;
    p3 = v3;
    normal = ((p1-p2)^(p1-p3)).normalize();
}

Vector3 Triangle::getNormal(Vector3 point) {
    return normal;
}

Intersection Triangle::isIntersected(const Ray3 &ray) {
    Intersection result;
    Vector3 o = ray.getOrigin();
    Vector3 d = ray.getDirection();
    float dn = d*normal;
    if(dn!=0){
        Vector3 temp_normal = normal;
        if(dn>0)
            temp_normal = -normal;
        float A = (p1.x-p2.x)*(p1.y-p3.y)*d.z
                  +(p1.x-p3.x)*d.y*(p1.z-p2.z)
                  +d.x*(p1.y-p2.y)*(p1.z-p3.z)
                  -d.x*(p1.y-p3.y)*(p1.z-p2.z)
                  -(p1.x-p3.x)*(p1.y-p2.y)*d.z
                  -(p1.x-p2.x)*d.y*(p1.z-p3.z);

        float t = ((p1.x-p2.x)*(p1.y-p3.y)*(p1.z-o.z)
                  +(p1.x-p3.x)*(p1.y-o.y)*(p1.z-p2.z)
                  +(p1.x-o.x)*(p1.y-p2.y)*(p1.z-p3.z)
                  -(p1.x-o.x)*(p1.y-p3.y)*(p1.z-p2.z)
                  -(p1.x-p3.x)*(p1.y-p2.y)*(p1.z-o.z)
                  -(p1.x-p2.x)*(p1.y-o.y)*(p1.z-p3.z))/A;
        if(t>1e-3){
            float beta = ((p1.x-o.x)*(p1.y-p3.y)*d.z
                         +(p1.x-p3.x)*d.y*(p1.z-o.z)
                         +d.x*(p1.y-o.y)*(p1.z-p3.z)
                         -d.x*(p1.y-p3.y)*(p1.z-o.z)
                         -(p1.x-p3.x)*(p1.y-o.y)*d.z
                         -(p1.x-o.x)*d.y*(p1.z-p3.z))/A;

            float gamma = ((p1.x-p2.x)*(p1.y-o.y)*d.z
                          +(p1.x-o.x)*d.y*(p1.z-p2.z)
                          +d.x*(p1.y-p2.y)*(p1.z-o.z)
                          -d.x*(p1.y-o.y)*(p1.z-p2.z)
                          -(p1.x-o.x)*(p1.y-p2.y)*d.z
                          -(p1.x-p2.x)*d.y*(p1.z-o.z))/A;
            if(beta>0&&gamma>0&&beta+gamma<1){
                result.isHit=1;
                result.object = this;
                result.distance = t;
                result.position = ray.getPoint(t);
                result.normal = temp_normal;
            }
        }
        return result;
    }
}
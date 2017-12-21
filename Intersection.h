//
// Created by liwen on 17-12-7.
//

#ifndef RAY_TRACER_INTERSECTION_H
#define RAY_TRACER_INTERSECTION_H

#include "Core/Vector3.h"

class Object;

class Intersection {
public:
    Intersection(){}
    ~Intersection(){}
    float distance = 100000000;
    bool isHit = 0;
    Vector3 position;
    Vector3 normal;
    Object* object = nullptr;
};


#endif //RAY_TRACER_INTERSECTION_H

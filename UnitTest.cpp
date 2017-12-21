//
// Created by liwen on 12/21/17.
//
#include <iostream>
#include "Object/Triangle.h"


int main(){
    Triangle* triangle1 = new Triangle(Vector3(0,0,1),Vector3(0,1,0),Vector3(1,0,0));
    Triangle* triangle2 = new Triangle(Vector3(0,0,-1),Vector3(0,1,0),Vector3(1,0,0));
    Ray3* ray = new Ray3(Vector3(0,0,0),Vector3(1,1,1));

    Intersection res1 = triangle1->isIntersected(*ray);
    Intersection res2 = triangle2->isIntersected(*ray);
    std::cout<<res1.isHit<<std::endl;
    std::cout<<res1.distance<<std::endl;
    std::cout<<res1.position<<std::endl;
    std::cout<<res2.isHit<<std::endl;
    return 0;
}
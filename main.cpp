//
// Created by liwen on 17-12-7.
//
#include <iostream>
#include "Tracer.h"
#include "Object/InfinitePlane.h"
#include "Object/Sphere.h"
#include "Object/LightSource/SunLight.h"
#include "Object/LightSource/PointLightSource.h"
#include "Object/Material/DefaultMaterial.h"
#include "Object/Material/Phong.h"
#include "Object/Triangle.h"

int main(){

    Camera *cam = new Camera(Vector3(0,0,40),Vector3(0,0,-1),Vector3(0,1,0),28,28);
    cam->setCanvas(800,800);

    InfinitePlane *plane1 = new InfinitePlane(Vector3(0,-10,0),Vector3(0,1,0));
    InfinitePlane *plane2 = new InfinitePlane(Vector3(-10,0,0),Vector3(1,0,0));
    InfinitePlane *plane3 = new InfinitePlane(Vector3(0,0,-40),Vector3(0,0,1));
    Sphere *sphere1 = new Sphere(Vector3(0,-5,-5),5);

//    Triangle *t1 = new Triangle(Vector3(0,0,-5),Vector3(-5,-5,0),Vector3(5,-5,0));
//    Triangle *t2 = new Triangle(Vector3(0,0,-5),Vector3(-5,-5,0),Vector3(-5,-5,-10));
//    Triangle *t3 = new Triangle(Vector3(0,0,-5),Vector3(-5,-5,-10),Vector3(5,-5,-10));
//    Triangle *t4 = new Triangle(Vector3(0,0,-5),Vector3(5,-5,0),Vector3(5,-5,-10));
//
//    Triangle *t5 = new Triangle(Vector3(0,-10,-5),Vector3(-5,-5,0),Vector3(5,-5,0));
//    Triangle *t6 = new Triangle(Vector3(0,-10,-5),Vector3(-5,-5,0),Vector3(-5,-5,-10));
//    Triangle *t7 = new Triangle(Vector3(0,-10,-5),Vector3(-5,-5,-10),Vector3(5,-5,-10));
//    Triangle *t8 = new Triangle(Vector3(0,-10,-5),Vector3(5,-5,0),Vector3(5,-5,-10));

    Triangle *t1 = new Triangle(Vector3(0,0,-5),Vector3(0,-5,0),Vector3(5,-5,-5));
    Triangle *t2 = new Triangle(Vector3(0,0,-5),Vector3(5,-5,-5),Vector3(0,-5,-10));
    Triangle *t3 = new Triangle(Vector3(0,0,-5),Vector3(0,-5,-10),Vector3(-5,-5,-5));
    Triangle *t4 = new Triangle(Vector3(0,0,-5),Vector3(-5,-5,-5),Vector3(0,-5,0));

    Triangle *t5 = new Triangle(Vector3(0,-10,-5),Vector3(0,-5,0),Vector3(5,-5,-5));
    Triangle *t6 = new Triangle(Vector3(0,-10,-5),Vector3(5,-5,-5),Vector3(0,-5,-10));
    Triangle *t7 = new Triangle(Vector3(0,-10,-5),Vector3(0,-5,-10),Vector3(-5,-5,-5));
    Triangle *t8 = new Triangle(Vector3(0,-10,-5),Vector3(-5,-5,-5),Vector3(0,-5,0));



    SunLight *light1 = new SunLight(Vector3(-2,-1.5,-1),Color3(200,200,200));
    PointLightSource *light2 = new PointLightSource(Vector3(30,20,10),Color3(255,255,255));
    PointLightSource *light3 = new PointLightSource(Vector3(-10,20,10),Color3(125,125,125));

    DefaultMaterial *material1 = new DefaultMaterial();
    Phong *material2 = new Phong(Color3(255/255,255/255,1), Color3(1,1,1), 16);

    //******************* material
    plane1->material = material1;
    plane2->material = material1;
    plane3->material = material1;
    sphere1->material = material2;

    t1->material = material2;
    t2->material = material2;
    t3->material = material2;
    t4->material = material2;
    t5->material = material2;
    t6->material = material2;
    t7->material = material2;
    t8->material = material2;
    //******************* material

    vector<Object*> v_obj;
    vector<LightSource*> v_light;

    v_obj.push_back(plane1);
    //v_obj.push_back(plane2);
    v_obj.push_back(plane3);
    //v_obj.push_back(sphere1);
    v_obj.push_back(t1);
    v_obj.push_back(t2);
    v_obj.push_back(t3);
    v_obj.push_back(t4);
    v_obj.push_back(t5);
    v_obj.push_back(t6);
    v_obj.push_back(t7);
    v_obj.push_back(t8);




    //v_light.push_back(light1);
    v_light.push_back(light2);
    //v_light.push_back(light3);

    Tracer *tracer = new Tracer(v_light,v_obj,cam);

    tracer->Scan(3); // just once
    tracer->render();


    return 0;
}

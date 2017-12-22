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

    Camera *cam = new Camera(Vector3(0,5,40),Vector3(0,-0.1,-1),Vector3(0,1,0),50,50);
    cam->setCanvas(600,600);

    InfinitePlane *plane1 = new InfinitePlane(Vector3(0,-10,0),Vector3(0,1,0));
    InfinitePlane *plane2 = new InfinitePlane(Vector3(-15,0,0),Vector3(1,0,0));
    InfinitePlane *plane3 = new InfinitePlane(Vector3(0,0,-30),Vector3(0,0,1));
    InfinitePlane *plane4 = new InfinitePlane(Vector3(15,0,0),Vector3(-1,0,0));
    InfinitePlane *plane5 = new InfinitePlane(Vector3(0,20,0),Vector3(0,-1,0));
    Sphere *sphere1 = new Sphere(Vector3(-5,-5,0),5);

//    Triangle *t1 = new Triangle(Vector3(0,0,-5),Vector3(-5,-5,0),Vector3(5,-5,0));
//    Triangle *t2 = new Triangle(Vector3(0,0,-5),Vector3(-5,-5,0),Vector3(-5,-5,-10));
//    Triangle *t3 = new Triangle(Vector3(0,0,-5),Vector3(-5,-5,-10),Vector3(5,-5,-10));
//    Triangle *t4 = new Triangle(Vector3(0,0,-5),Vector3(5,-5,0),Vector3(5,-5,-10));
//
//    Triangle *t5 = new Triangle(Vector3(0,-10,-5),Vector3(-5,-5,0),Vector3(5,-5,0));
//    Triangle *t6 = new Triangle(Vector3(0,-10,-5),Vector3(-5,-5,0),Vector3(-5,-5,-10));
//    Triangle *t7 = new Triangle(Vector3(0,-10,-5),Vector3(-5,-5,-10),Vector3(5,-5,-10));
//    Triangle *t8 = new Triangle(Vector3(0,-10,-5),Vector3(5,-5,0),Vector3(5,-5,-10));

    Triangle *t1 = new Triangle(Vector3(8,0,0),Vector3(8,-5,5),Vector3(13,-5,0));
    Triangle *t2 = new Triangle(Vector3(8,0,0),Vector3(13,-5,0),Vector3(8,-5,-5));
    Triangle *t3 = new Triangle(Vector3(8,0,0),Vector3(8,-5,-5),Vector3(3,-5,0));
    Triangle *t4 = new Triangle(Vector3(8,0,0),Vector3(3,-5,0),Vector3(8,-5,5));

    Triangle *t5 = new Triangle(Vector3(8,-10,0),Vector3(8,-5,5),Vector3(13,-5,0));
    Triangle *t6 = new Triangle(Vector3(8,-10,0),Vector3(13,-5,0),Vector3(8,-5,-5));
    Triangle *t7 = new Triangle(Vector3(8,-10,0),Vector3(8,-5,-5),Vector3(3,-5,0));
    Triangle *t8 = new Triangle(Vector3(8,-10,0),Vector3(3,-5,0),Vector3(8,-5,5));



    SunLight *light1 = new SunLight(Vector3(-2,-1.5,-1),Color3(200,200,200));
    PointLightSource *light2 = new PointLightSource(Vector3(5,19.8,10),Color3(255,255,255));
    PointLightSource *light3 = new PointLightSource(Vector3(-10,20,10),Color3(125,125,125));

    DefaultMaterial *material1 = new DefaultMaterial();

    Phong *material2 = new Phong(Color3(135.0/125,206.0/125, 250.0/80), Color3(1,1,1), 24);
    material2->trace_reflectivity = 0.35;
    material2->ambient = Color3(10,10,10);

    Phong *material3 = new Phong(Color3(255.0/120, 192.0/120, 203.0/120), Color3(1,1,1), 16);
    material3->trace_reflectivity =1;
    material3->ambient = Color3(20,20,20);

    Phong *material4 = new Phong(Color3(152.0/250 ,251.0/250, 152.0/250), Color3(1,1,1), 16, 0.2);
    material4->trace_reflectivity =0;
    material4->ambient = Color3(10,10,10);

    Phong *material5 = new Phong(Color3(238.0/100, 220.0/100, 130.0/100), Color3(1,1,1), 16, 0.2);
    material5->trace_reflectivity =0;
    material5->ambient = Color3(40,40,40);

    Phong *material6 = new Phong(Color3(255.0/100, 255.0/100, 255.0/100), Color3(1,1,1), 16, 0.2);
    material6->trace_reflectivity =0;
    material6->ambient = Color3(50.0,50.0,50.0);


    Phong *material7 = new Phong(Color3(255.0/255, 10.0/255, 0), Color3(1,1,1), 24);
    material7->trace_reflectivity = 0.4;
    material7->ambient = Color3(10,10,10);
    //******************* material
    plane1->material = material7;
    plane2->material = material5;
    plane3->material = material4;
    plane4->material = material6;
    plane5->material = material3;
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
    v_obj.push_back(plane2);
    v_obj.push_back(plane3);
    v_obj.push_back(plane4);
    v_obj.push_back(plane5);
    v_obj.push_back(sphere1);
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

    tracer->Scan(3);
    tracer->render("opencv");


    return 0;
}

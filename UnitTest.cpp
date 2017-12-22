//
// Created by liwen on 12/21/17.
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
using namespace std;
int main(){
    Camera *cam = new Camera(Vector3(0,0,50),Vector3(0,0,-1),Vector3(0,1,0),40,40);
    cam->setCanvas(600,600);

    InfinitePlane *plane1 = new InfinitePlane(Vector3(0,-10,0),Vector3(0,1,0));
    InfinitePlane *plane2 = new InfinitePlane(Vector3(-15,0,0),Vector3(1,0,0));
    InfinitePlane *plane3 = new InfinitePlane(Vector3(0,0,-60),Vector3(0,0,1));
    Sphere *sphere1 = new Sphere(Vector3(0,-5,0),5);

    SunLight *light1 = new SunLight(Vector3(-2,-1.5,-1),Color3(200,200,200));
    PointLightSource *light2 = new PointLightSource(Vector3(0,0,60),Color3(255,255,255));

    //*********************material init
    DefaultMaterial *material1 = new DefaultMaterial();
    Phong *material2 = new Phong(Color3(135.0/125,206.0/125, 250.0/80), Color3(1,1,1), 24);
    material2->trace_reflectivity = 0.3;
    material2->ambient = Color3(10,10,10);

    Phong *material3 = new Phong(Color3(255.0/120, 192.0/120, 203.0/120), Color3(1,1,1), 16);
    material3->trace_reflectivity =0;
    material3->ambient = Color3(20,20,20);

    Phong *material4 = new Phong(Color3(152.0/250 ,251.0/250, 152.0/250), Color3(1,1,1), 16, 0.2);
    material4->trace_reflectivity =0;
    material4->ambient = Color3(20,20,20);

    Phong *material5 = new Phong(Color3(238.0/100, 220.0/100, 130.0/100), Color3(1,1,1), 16, 0.2);
    material5->trace_reflectivity =0;
    material5->ambient = Color3(40,40,40);
    //******************* material
    plane1->material = material3;
    plane2->material = material5;
    plane3->material = material4;
    sphere1->material = material2;

    //******************* material

    vector<Object*> v_obj;
    vector<LightSource*> v_light;

    v_obj.push_back(plane1);
    //v_obj.push_back(plane2);
    //v_obj.push_back(plane3);
    v_obj.push_back(sphere1);

    v_light.push_back(light1);
    //v_light.push_back(light2);
    //v_light.push_back(light3);

    Tracer *tracer = new Tracer(v_light,v_obj,cam);

    tracer->Scan(2);
    tracer->render("opencv");


    return 0;
}
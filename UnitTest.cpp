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
int main(int argc, char* argv[]){
    Camera *cam = new Camera(Vector3(0,0,50),Vector3(0,0,-1),Vector3(0,1,0),40,40);
    cam->setCanvas(1000,1000);

    InfinitePlane *plane1 = new InfinitePlane(Vector3(0,-10,0),Vector3(0,1,0));
    InfinitePlane *plane2 = new InfinitePlane(Vector3(-15,0,0),Vector3(1,0,0));
    InfinitePlane *plane3 = new InfinitePlane(Vector3(0,0,-60),Vector3(0,0,1));
    Sphere *sphere1 = new Sphere(Vector3(0,-5,0),5);

    SunLight *light1 = new SunLight(Vector3(-2,-1.5,-1),Color3(200,200,200));
    PointLightSource *light2 = new PointLightSource(Vector3(0,0,60),Color3(255,255,255));

    //*********************material init
    Phong *material2 = new Phong(Color3(0), Color3(1), 256, 1, 1);
    material2->trace_reflectivity = 0.4;
    material2->n = 1.6;
    material2->ambient = Color3(0,0,0);

    Phong *material3 = new Phong(Color3(1), Color3(1,1,1), 16, 0.4);
    material3->trace_reflectivity =0.4;
    material3->ambient = Color3(20,20,20);

    Phong *material4 = new Phong(Color3(1), Color3(1,1,1), 16, 0.4);
    material4->trace_reflectivity =0.4;
    material4->ambient = Color3(20,20,20);

    Phong *material5 = new Phong(Color3(1), Color3(1,1,1), 16, 0.4);
    material5->trace_reflectivity =0.4;
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
    v_obj.push_back(plane2);
    v_obj.push_back(plane3);
    v_obj.push_back(sphere1);

    v_light.push_back(light1);

    Tracer *tracer = new Tracer(v_light,v_obj,cam);

    tracer->Scan(2);

    if(argc>1)
        tracer->render(argv[1]);
    else
        tracer->render("opencv");

    return 0;
}

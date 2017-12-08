//
// Created by liwen on 17-12-7.
//
#include <iostream>
#include "Tracer.h"
#include "Object/InfinitePlane.h"
#include "Object/LightSource/SunLight.h"
#include "Object/Material/DefaultMaterial.h"
#include "Object/Material/Phong.h"

int main(){
    Camera *cam = new Camera(Vector3(0,0,10),Vector3(0,0,-1),Vector3(0,1,0),90,90);
    cam->setCanvas(400,400);

    InfinitePlane *plane1 = new InfinitePlane(Vector3(0,-10,0),Vector3(0,1,0));
    InfinitePlane *plane2 = new InfinitePlane(Vector3(-10,0,0),Vector3(1,0,0));
    InfinitePlane *plane3 = new InfinitePlane(Vector3(0,0,-10),Vector3(0,0,1));

    SunLight *light1 = new SunLight(Vector3(-2,-1.5,-1),Color3(200,200,200));

    DefaultMaterial *material1 = new DefaultMaterial();
    Phong *material2 = new Phong(Color3(30/255,144/255,1), Color3(1,1,1), 30);

    plane1->material = material2;
    plane2->material = material2;
    plane3->material = material2;

    vector<Object*> v_obj;
    vector<LightSource*> v_light;

    v_obj.push_back(plane1);
    v_obj.push_back(plane2);
    v_obj.push_back(plane3);

    v_light.push_back(light1);

    Tracer *tracer = new Tracer(v_light,v_obj,cam);

    tracer->Scan(1); // just once
    tracer->render();


    return 0;
}

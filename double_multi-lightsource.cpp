//
// Created by liwen on 6/27/18.
//

#include <iostream>
#include "Tracer.h"
#include "Object/InfinitePlane.h"
#include "Object/Sphere.h"
#include "Object/Circle.h"
#include "Object/LightSource/SunLight.h"
#include "Object/LightSource/PointLightSource.h"
#include "Object/Material/DefaultMaterial.h"
#include "Object/Material/Phong.h"
#include "Object/Triangle.h"
#include "Object/Cylinder.h"
#include "Object/Square.h"

#define N 1

int main(int argc, char* argv[]){

    Camera *cam = new Camera(Vector3(0,5,50),Vector3(0,0,-1),Vector3(0,1,0),50,50);
    cam->setCanvas(1000,1000);

    // ================================== object
    Square *plane1 = new Square(Vector3(0,-10,0),Vector3(0,1,0), Vector3(1,0,0), Vector3(0,1,0), 14.99, 20);
    InfinitePlane *plane2 = new InfinitePlane(Vector3(-15,0,0),Vector3(1,0,0));
    InfinitePlane *plane3 = new InfinitePlane(Vector3(0,0,-40),Vector3(0,0,1));
    InfinitePlane *plane4 = new InfinitePlane(Vector3(15,0,0),Vector3(-1,0,0));
    InfinitePlane *plane5 = new InfinitePlane(Vector3(0,20,0),Vector3(0,-1,0));
    Sphere *sphere1 = new Sphere(Vector3(-6,-5,-1),5);
    Sphere *sphere2 = new Sphere(Vector3(2,-4,10),2);
    Circle *circle1 = new Circle(Vector3(-8,19.99,5), 1, Vector3(0,-1,0));
    Circle *circle2 = new Circle(Vector3(8,19.99,5), 1, Vector3(0,-1,0));
    Cylinder *cylinder1 = new Cylinder(Vector3(3,0,-15), Vector3(0,1,0), 5, 20);

    Triangle *t1 = new Triangle(Vector3(8,0,0),Vector3(8,-5,5),Vector3(13,-5,0));
    Triangle *t2 = new Triangle(Vector3(8,0,0),Vector3(13,-5,0),Vector3(8,-5,-5));
    Triangle *t3 = new Triangle(Vector3(8,0,0),Vector3(8,-5,-5),Vector3(3,-5,0));
    Triangle *t4 = new Triangle(Vector3(8,0,0),Vector3(3,-5,0),Vector3(8,-5,5));

    Triangle *t5 = new Triangle(Vector3(8,-10,0),Vector3(8,-5,5),Vector3(13,-5,0));
    Triangle *t6 = new Triangle(Vector3(8,-10,0),Vector3(13,-5,0),Vector3(8,-5,-5));
    Triangle *t7 = new Triangle(Vector3(8,-10,0),Vector3(8,-5,-5),Vector3(3,-5,0));
    Triangle *t8 = new Triangle(Vector3(8,-10,0),Vector3(3,-5,0),Vector3(8,-5,5));

    PointLightSource *light2 = new PointLightSource(Vector3(-8,19.999,5),Color3(6));
    light2->setHost(circle1);
    PointLightSource *light4 = new PointLightSource(Vector3(-8,19.999,5.3),Color3(6));
    light4->setHost(circle1);
    PointLightSource *light5 = new PointLightSource(Vector3(-8,19.999,4.7),Color3(6));
    light5->setHost(circle1);
    PointLightSource *light6 = new PointLightSource(Vector3(-8.3,19.999,5),Color3(6));
    light6->setHost(circle1);
    PointLightSource *light7 = new PointLightSource(Vector3(-7.7,19.999,5),Color3(6));
    light7->setHost(circle1);
    PointLightSource *light8 = new PointLightSource(Vector3(-8.3,19.999,5.3),Color3(6));
    light8->setHost(circle1);
    PointLightSource *light9 = new PointLightSource(Vector3(-8.3,19.999,4.7),Color3(6));
    light9->setHost(circle1);
    PointLightSource *light10 = new PointLightSource(Vector3(-7.7,19.999,5.3),Color3(6));
    light10->setHost(circle1);
    PointLightSource *light11 = new PointLightSource(Vector3(-7.7,19.999,4.7),Color3(6));
    light11->setHost(circle1);

    PointLightSource *light22 = new PointLightSource(Vector3(8,19.999,5),Color3(6));
    light22->setHost(circle2);
    PointLightSource *light24 = new PointLightSource(Vector3(8,19.999,5.3),Color3(6));
    light24->setHost(circle2);
    PointLightSource *light25 = new PointLightSource(Vector3(8,19.999,4.7),Color3(6));
    light25->setHost(circle2);
    PointLightSource *light26 = new PointLightSource(Vector3(8.3,19.999,5),Color3(6));
    light26->setHost(circle2);
    PointLightSource *light27 = new PointLightSource(Vector3(7.7,19.999,5),Color3(6));
    light27->setHost(circle2);
    PointLightSource *light28 = new PointLightSource(Vector3(8.3,19.999,5.3),Color3(6));
    light28->setHost(circle2);
    PointLightSource *light29 = new PointLightSource(Vector3(8.3,19.999,4.7),Color3(6));
    light29->setHost(circle2);
    PointLightSource *light210 = new PointLightSource(Vector3(7.7,19.999,5.3),Color3(6));
    light210->setHost(circle2);
    PointLightSource *light211 = new PointLightSource(Vector3(7.7,19.999,4.7),Color3(6));
    light211->setHost(circle2);

    //===========================================================
    // light host
    DefaultMaterial *material1 = new DefaultMaterial();
    material1->ambient = Color3(255,255,255);

    // poly
    Phong *material2 = new Phong(Color3(1), Color3(1), 24);
    material2->trace_reflectivity = 0.5;
    material2->ambient = Color3(80,40,130);

    // top plane
    Phong *material3 = new Phong(Color3(1), Color3(1), 32, 0.1);
    material3->trace_reflectivity = 0.2;
    material3->ambient = Color3(25, 45, 70);

    // back plane
    Phong *material4 = new Phong(Color3(1, 1, 1), Color3(1), 16, 0.4);
    material4->trace_reflectivity =0;
    material4->ambient = Color3(40,120,40);

    // left plane
    Phong *material5 = new Phong(Color3(1, 1, 0.7), Color3(0.5), 16, 1);
    material5->trace_reflectivity =0;
    material5->ambient = Color3(250, 245, 143)/1.3;

    // right plane
    Phong *material6 = new Phong(Color3(0.8, 1, 0.8), Color3(1), 8, 1);
    material6->trace_reflectivity =0;
    material6->ambient = Color3(150,54,54);

    // bottom plane
    Phong *material7 = new Phong(Color3(1), Color3(1), 16, 0.1);
    material7->trace_reflectivity = 1.2;
    material7->ambient = Color3(5,5,5);

    // transparent
    Phong *material8 = new Phong(Color3(0.15), Color3(1), 256, 3, 1);
    material8->trace_reflectivity = 0.3;
    material8->n = 1.6;
    material8->ambient = Color3(0,0,0);

    // left sphere
    Phong *material9 = new Phong(Color3(1, 1, 1), Color3(1, 1, 1), 128, 1);
    material9->trace_reflectivity = 0.3;
    material9->ambient = Color3(120,60,10)*1.2;

    // cylinder
    Phong *material10 = new Phong(Color3(1), Color3(1), 64, 1);
    material10->trace_reflectivity = 0.3;
    material10->ambient = Color3(30, 144, 255)/1.7;
    //******************* material
    plane1->material = material7;
    plane2->material = material5;
    plane3->material = material4;
    plane4->material = material6;
    plane5->material = material3;
    sphere1->material = material9;
    sphere2->material = material8;
    cylinder1->material = material10;

    t1->material = material2;
    t2->material = material2;
    t3->material = material2;
    t4->material = material2;
    t5->material = material2;
    t6->material = material2;
    t7->material = material2;
    t8->material = material2;

    circle1->material = material1;
    circle2->material = material1;
    //******************* material

    vector<Object*> v_obj;
    vector<LightSource*> v_light;

    v_obj.push_back(plane1);
    v_obj.push_back(plane2);
    v_obj.push_back(plane3);
    v_obj.push_back(plane4);
    v_obj.push_back(plane5);
    v_obj.push_back(sphere1);
    v_obj.push_back(sphere2);
    v_obj.push_back(t1);
    v_obj.push_back(t2);
    v_obj.push_back(t3);
    v_obj.push_back(t4);
    v_obj.push_back(t5);
    v_obj.push_back(t6);
    v_obj.push_back(t7);
    v_obj.push_back(t8);
    v_obj.push_back(light2);
    v_obj.push_back(light22);
    v_obj.push_back(cylinder1);


    v_light.push_back(light2);
    v_light.push_back(light4);
    v_light.push_back(light5);
    v_light.push_back(light6);
    v_light.push_back(light7);
    v_light.push_back(light8);
    v_light.push_back(light9);
    v_light.push_back(light10);
    v_light.push_back(light11);

    v_light.push_back(light22);
    v_light.push_back(light24);
    v_light.push_back(light25);
    v_light.push_back(light26);
    v_light.push_back(light27);
    v_light.push_back(light28);
    v_light.push_back(light29);
    v_light.push_back(light210);
    v_light.push_back(light211);

    Tracer *tracer = new Tracer(v_light,v_obj,cam);

    tracer->Scan(3);
    if(argc>1)
        tracer->render(argv[1]);
    else
        tracer->render("opencv");

    return 0;
}

//
// Created by liwen on 12/22/17.
//
#include <iostream>
#include <fstream>
#include <sstream>
#include "Tracer.h"
#include "Object/InfinitePlane.h"
#include "Object/Sphere.h"
#include "Object/LightSource/SunLight.h"
#include "Object/LightSource/PointLightSource.h"
#include "Object/Material/DefaultMaterial.h"
#include "Object/Material/Phong.h"
#include "Object/Triangle.h"

int main() {
    // phong
    Phong *material1 = new Phong(Color3(255/255,255/255,1), Color3(1,1,1), 16);
    material1->ambient = Color3(100,100,100);
    Phong *material2 = new Phong(Color3(255/255,255/255,1), Color3(1,1,1), 16);
    material2->ambient = Color3(50,50,50);

    // read bunny model
    ifstream bunny("/home/liwen/Codes/ray_trace_reconstruct/bunny_easy.txt");
    string s;
    vector<Object*> bunny_triangles;
    vector<Vector3> ver;
    float temp;
    float x,y,z;
    int p1,p2,p3;
    while(getline(bunny,s)) {
        stringstream ss(s);
        ss>>temp;
        if(temp>=3) {
            ss>>p1>>p2>>p3;
            bunny_triangles.push_back(new Triangle(ver[p1],ver[p2],ver[p3]));
            bunny_triangles[0]->material=material1;
            break;
        }
        ss>>x>>y>>z;
        ver.push_back(Vector3(x*100,y*100,-z*100));
    }
    while(getline(bunny,s)) {
        stringstream ss(s);
        temp = ss.peek();
        ss>>temp>>p1>>p2>>p3;
        Triangle* te = new Triangle(ver[p1],ver[p2],ver[p3]);
        te->material=material1; // set material
        bunny_triangles.push_back(te);
    }

    // set camera
    Camera *cam = new Camera(Vector3(13,0,40),Vector3(0,0,-1),Vector3(0,1,0),28,28);
    cam->setCanvas(400,400);

    // light
    PointLightSource *light = new PointLightSource(Vector3(13,0,40),Color3(255,255,255));

    // object list
    vector<Object*> v_obj = bunny_triangles;
    InfinitePlane *plane1 = new InfinitePlane(Vector3(0,-10,0),Vector3(0,1,0));
    plane1->material = material2;
    v_obj.push_back(plane1);

    // light source list
    vector<LightSource*> v_light;
    v_light.push_back(light);

    // ray tracer
    Tracer *tracer = new Tracer(v_light,v_obj,cam);

    // ray tracing

    tracer->Scan(1); // times of recursion
    tracer->render("opencv"); // draw

    // clean
    for(Object* t:bunny_triangles){
        delete(t);
    }

    return 0;
}
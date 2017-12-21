//
// Created by liwen on 17-12-7.
//

#include "Tracer.h"
#include "Render.h"
#include "Object/Light/PointLightRay3.h"

Tracer::Tracer(vector<LightSource *>& _light, vector<Object*>& _obj, Camera *_cam): light_src_list(_light), obj_list(_obj), camera(_cam) {}

Intersection Tracer::ray_with_objs(Ray3& ray, vector<Object*>& objs){
    Intersection res;
    for(Object * temp_obj:objs){
        Intersection temp = temp_obj->isIntersected(ray);
        if(temp.distance<res.distance){
            res = temp;
        }
    }
    return res;
}

Color3 Tracer::recursive(Ray3& ray, int times, float decay, float& distance) {
    times--;
    Color3 res = Color3(0,0,0);
    Intersection sight_hit = ray_with_objs(ray,obj_list);
    if(sight_hit.isHit){
        for(LightSource* temp_light:light_src_list) {
            LightRay3* temp_light_ray = temp_light->traceLight(sight_hit.position+1e-3*sight_hit.normal);
            Intersection light_hit = ray_with_objs(*temp_light_ray, obj_list);
            if (!light_hit.isHit || light_hit.object == temp_light) {
                Color3 color = sight_hit.object->material->sample(ray, temp_light_ray, sight_hit.distance, sight_hit.normal);
                res += color*sight_hit.object->material->reflectivity;
            }
            delete temp_light_ray;
        }
        if(times>0){
            if(sight_hit.object->material->reflectivity>0) {
                Ray3 reflect(sight_hit.position, ray.direction - 2 * ray.direction.project(sight_hit.normal));
                Color3 ref = recursive(reflect, times, sight_hit.object->material->reflectivity,distance);
                PointLightRay3 light_reflect(reflect,ref);
                //LightRay3 light_reflect(reflect,ref);
                Color3 color = sight_hit.object->material->sample(ray, &light_reflect, distance, sight_hit.normal);
                res += color*sight_hit.object->material->reflectivity;
            }
            if(sight_hit.object->material->refractivity>0){// to be done, transparent material
//                Vector3 proj = ray.direction.project(sight_hit.normal);
//                Vector3 parallel = ray.direction + proj;
//                float sin_theta1 = parallel.getLength();
//                float sin_theta2 = sin_theta1/sight_hit.object->material->n;
//                float tan_theta2 = sin_theta2/sqrt(1-sin_theta2*sin_theta2);
//                Ray3 refract(sight_hit.position,sight_hit.normal+parallel.normalize()*tan_theta2);
//                recursive(refract, times, sight_hit.object->material->reflectivity);
            }
        }
    }
    distance = sight_hit.distance;
    return res;
}

void Tracer::Scan(int times) {
    bool working = true;
    int x=0,y=0;
    while(working){
        Ray3 temp_sight_ray = camera->generateRay(working,x,y); // emit
        float distance = 0;
        Color3 result = recursive(temp_sight_ray,times,1,distance);
        camera->recieveColor(result); // receive
    }
}

void Tracer::render() {
    Render::openglRender(camera->canvas);
}
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
        if(temp.distance < res.distance){
            res = temp;
        }
    }
    return res;
}


Ray3 Tracer::trace_in_object_light(Ray3 *ray, Intersection& sight_hit, double& dist) {
    double n = sight_hit.object->material->n;
    Vector3 proj = ray->direction.project(sight_hit.normal);
    Vector3 parallel = ray->direction - proj;
    double sin_theta1 = parallel.getLength();
    double sin_theta2 = sin_theta1/n;
    double tan_theta2 = sin_theta2/sqrt(1-sin_theta2*sin_theta2);
    Ray3 refract(sight_hit.position - 1e-3*sight_hit.normal,-sight_hit.normal+parallel.normalize()*tan_theta2);
    Intersection out_hit = sight_hit.object->isIntersected(refract);
    dist += out_hit.distance;
    n = 1 / out_hit.object->material->n;
    proj = refract.direction.project(out_hit.normal);
    parallel = refract.direction - proj;
    double sin_theta12 = parallel.getLength();
    double sin_theta22 = sin_theta12/n;
    if(sin_theta2 > 1){
        // total reflection
        return Ray3(true);
    }
    else {
        double tan_theta22 = sin_theta22 / sqrt(1 - sin_theta22 * sin_theta22);
        Ray3 out(out_hit.position + 1e-3*out_hit.normal, out_hit.normal + parallel.normalize() * tan_theta22);
        out.through = sqrtf(1-sin_theta12);
        return out;
    }
}

Color3 Tracer::recursive(Ray3* ray, int times, double& distance) {
    times--;
    Color3 res = Color3(0,0,0);
    Intersection sight_hit = ray_with_objs(*ray,obj_list);
    if(sight_hit.isHit){
        distance += sight_hit.distance;
        res += sight_hit.object->material->ambient;
        for(LightSource* temp_light:light_src_list) {
            LightRay3* temp_light_ray = temp_light->traceLight(sight_hit.position);//+1e-3*sight_hit.normal);
            Intersection light_hit = ray_with_objs(*temp_light_ray, obj_list);
            if (!light_hit.isHit || light_hit.object == temp_light) {
                Color3 color = sight_hit.object->material->sample(*ray, temp_light_ray, sight_hit.distance, sight_hit.normal);
                res += color*sight_hit.object->material->reflectivity;
            }
            delete temp_light_ray;
        }
        if(times>0){
            if(sight_hit.object->material->trace_reflectivity>0) {
                Ray3 reflect(sight_hit.position+sight_hit.normal*1e-3, ray->direction - 2 * ray->direction.project(sight_hit.normal));
                Color3 ref = recursive(&reflect, times,distance);
                PointLightRay3 light_reflect(reflect,ref);
                //LightRay3 light_reflect(reflect,ref);
                Color3 color = sight_hit.object->material->sample(*ray, &light_reflect, distance, sight_hit.normal);
                res += color*sight_hit.object->material->trace_reflectivity;
            }
            if(sight_hit.object->material->refractivity>0){
                double refract_distance = distance;
                Ray3 refract = trace_in_object_light(ray, sight_hit, refract_distance);
                if(!refract.inobject) {
                    Color3 ref = recursive(&refract, times, refract_distance);
                    res += ref * sight_hit.object->material->refractivity * refract.through;
                }
            }
        }
    }

    return res;
}



void Tracer::Scan(int times) {
    bool working = true;
    int x=0,y=0;
    while(working){
        Ray3 temp_sight_ray = camera->generateRay(working,x,y); // emit
        double distance = 0;
        Color3 result = recursive(&temp_sight_ray,times,distance);
        camera->recieveColor(result); // receive
    }
}

void Tracer::render(string type) {
    if (type=="opencv")
        Render::opencvRender(camera->canvas);
    else
        Render::openglRender(camera->canvas);;
}


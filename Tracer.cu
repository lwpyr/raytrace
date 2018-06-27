#include <host_defines.h>
#include "Tracer.h"
#include "Render.h"
#include "Object/Light/PointLightRay3.h"

__global__ void recursive_cuda(Ray3 * d_ray, int * d_times, double * d_distance){
    int h = blockIdx.x;
    int w = threadIdx.x;
}

void Tracer::Scan_cuda(int times) {

}

Color3 Tracer::recursive_cuda(Ray3* ray, int times, double decay, double& distance) {
    times--;
    Color3 res = Color3(0,0,0);
//    Intersection sight_hit = ray_with_objs(ray,obj_list);
//    if(sight_hit.isHit){
//        res = sight_hit.object->material->ambient;
//        for(LightSource* temp_light:light_src_list) {
//            LightRay3* temp_light_ray = temp_light->traceLight(sight_hit.position);//+1e-3*sight_hit.normal);
//            Intersection light_hit = ray_with_objs(*temp_light_ray, obj_list);
//            if (!light_hit.isHit || light_hit.object == temp_light) {
//                Color3 color = sight_hit.object->material->sample(ray, temp_light_ray, sight_hit.distance, sight_hit.normal);
//                res += color*sight_hit.object->material->reflectivity;
//            }
//            delete temp_light_ray;
//        }
//        if(times>0){
//            if(sight_hit.object->material->trace_reflectivity>0) {
//                Ray3 reflect(sight_hit.position+sight_hit.normal*1e-3, ray.direction - 2 * ray.direction.project(sight_hit.normal));
//                Color3 ref = recursive(reflect, times, sight_hit.object->material->reflectivity,distance);
//                PointLightRay3 light_reflect(reflect,ref);
//                //LightRay3 light_reflect(reflect,ref);
//                Color3 color = sight_hit.object->material->sample(ray, &light_reflect, distance, sight_hit.normal);
//                res += color*sight_hit.object->material->trace_reflectivity;
//            }
////            if(sight_hit.object->material->refractivity>0){// to be done, transparent material
////                Vector3 proj = ray.direction.project(sight_hit.normal);
////                Vector3 parallel = ray.direction + proj;
////                double sin_theta1 = parallel.getLength();
////                double sin_theta2 = sin_theta1/sight_hit.object->material->n;
////                double tan_theta2 = sin_theta2/sqrt(1-sin_theta2*sin_theta2);
////                Ray3 refract(sight_hit.position,sight_hit.normal+parallel.normalize()*tan_theta2);
////                recursive(refract, times, sight_hit.object->material->reflectivity);
////            }
//        }
//    }
//    distance = sight_hit.distance;
    return res;
}
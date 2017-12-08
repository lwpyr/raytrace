//
// Created by liwen on 17-12-7.
//

#ifndef RAY_TRACER_TRACER_H
#define RAY_TRACER_TRACER_H

#include "Object/LightSource/LightSource.h"
#include "Camera.h"
#include "Canvas.h"
#include <vector>

using namespace std;

class Tracer {
private:
    vector<LightSource*> light_src_list;
    vector<Object*> obj_list;
    Camera* camera;
public:
    Tracer() = default;
    Tracer(vector<LightSource*>& _light, vector<Object*>& _obj, Camera* _cam);
    ~Tracer() = default;

    static Intersection ray_with_objs(Ray3& ray, vector<Object*>& objs);
    void Scan(int times);
    Color3 recusive(Ray3& ray, int times, Color3& result, float decay);
    const static float epsilon;
};


#endif //RAY_TRACER_TRACER_H

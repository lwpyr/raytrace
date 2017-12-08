//
// Created by liwen on 17-12-7.
//

#include "LightRay3.h"

LightRay3::LightRay3(Vector3 _origin, Vector3 _dir, Color3 _color) {
    origin = _origin;
    direction = _dir.normalize();
    color = _color;
}

LightRay3::LightRay3(Ray3 ray, Color3 _color):Ray3(ray) {
    color = _color;
}
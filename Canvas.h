//
// Created by liwen on 17-12-7.
//

#ifndef RAY_TRACER_CANVAS_H
#define RAY_TRACER_CANVAS_H

#include "Core/Pixel2.h"
#include "Core/Vector2.h"
#include <vector>
using namespace std;

class Canvas {
private:
    vector<vector<Pixel2>> _canvas;

public:
    int H;
    int W;
    Canvas() = default;
    Canvas(int width, int height);
    ~Canvas() = default;

    void light_hit(float x, float y, const Color3& color);
    void light_hit(Vector2& v, const Color3& color);
    void finish();
};


#endif //RAY_TRACER_CANVAS_H

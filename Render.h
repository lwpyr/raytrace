//
// Created by liwen on 17-12-7.
//

#ifndef RAY_TRACER_RENDER_H
#define RAY_TRACER_RENDER_H

#include "Canvas.h"

class Render {
public:
    static void openglRender(const Canvas& c);
    static void opencvRender(const Canvas& c);
};


#endif //RAY_TRACER_RENDER_H

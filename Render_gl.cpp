//
// Created by liwen on 6/27/18.
//

#include "Render.h"
#include "Render_gl.h"
#include <GLFW/glfw3.h>
#include <iostream>

void Render::openglRender(const Canvas &c) {

    GLFWwindow* window;

    if (!glfwInit())
        return;

    window = glfwCreateWindow(c.W, c.H, "Ray tracing demo", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return;
    }

    glfwMakeContextCurrent(window);

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glLoadIdentity();
        int window_width = c.W;
        int window_height = c.H;
        glPointSize(1.0);
        double dx = 2.0f / window_width;
        double dy = 2.0f / window_height;
        glBegin(GL_POINTS);
        for (long y = 0; y < window_height; ++y) {
            double sy = -1 + dy * y;
            for (long x = 0; x < window_width; ++x) {
                double sx = -1 + dx * x;
                Color3 temp_c = c.sample(x, y);
                glColor3ub(temp_c.r, temp_c.g, temp_c.b);
                glVertex3f(sx, sy, 0);
            }
        }
        glEnd();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwTerminate();
}

#ifdef GL_ONLY
void Render::opencvRender(const Canvas &c) {
    std::cout << "only support openGL rendering\n";
    return;
}
#endif
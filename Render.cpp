//
// Created by liwen on 17-12-7.
//

#include "Render.h"
#include <GLFW/glfw3.h>
#include <opencv2/opencv.hpp>
using namespace cv;

void Render::openglRender(const Canvas &c) {

    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(c.W, c.H, "Ray tracing demo", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glLoadIdentity();
        int window_width = c.W;
        int window_height = c.H;
        glPointSize(1.0);
        float dx = 2.0f / window_width;
        float dy = 2.0f / window_height;
        glBegin(GL_POINTS);
        for (long y = 0; y < window_height; ++y) {
            float sy = -1 + dy * y;
            for (long x = 0; x < window_width; ++x) {
                float sx = -1 + dx * x;
                Color3 temp_c = c.sample(x, y);
                glColor3ub(temp_c.r, temp_c.g, temp_c.b);
                //glColor3ub(255, 255, 255);
                glVertex3f(sx, sy, 0);
            }
        }
        glEnd();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwTerminate();
}

void Render::opencvRender(const Canvas &c) {
    string window = "Ray tracing demo";
    Mat image(c.H, c.W, CV_8UC3);

    for (int row = 0; row < image.rows; row++){
        for (int col = 0; col < image.cols; col++)
        {
            Color3 temp_c = c.sample(col,c.H-row-1);
            image.at<Vec3b>(row,col) = Vec3b(temp_c.b, temp_c.g, temp_c.r);
        }
    }
    imshow(window,image);
    cvWaitKey();
}

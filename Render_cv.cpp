//
// Created by liwen on 17-12-7.
//
#include <iostream>
#include "Render.h"
#include "Render_cv.h"
#include <opencv2/opencv.hpp>
using namespace cv;

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
    imwrite("./result.png", image);
    imshow(window,image);
    cvWaitKey();
}

#ifdef CV_ONLY
void Render::openglRender(const Canvas &c) {
    std::cout << "only support openCV rendering\n";
    return;
}
#endif
//
// Created by liwen on 17-12-7.
//

#include "Camera.h"

Camera::Camera(const Vector3& _eye,const Vector3& _front,const Vector3& _up,float angle_x,float angle_y) {
    eye=_eye;
    frontDirection=_front.normalize();
    upDirection = _up.normalize();
    rightDirection = frontDirection^upDirection;
    angleX = angle_x;
    angleY = angle_y;
    v_ref_len = tan(angle_x*PI/360);
    h_ref_len = tan(angle_y*PI/360);
}

const Vector2 Camera::OUT = Vector2(-10,-10);

void Camera::setCanvas(int width, int height) {
    canvas = Canvas(width, height);
    dx = 1.0/width;
    dy = 1.0/height;
}

Ray3 Camera::generateRay(bool &working) {

    last_x = scan_x;
    last_y = scan_y;

    float rate_x = (scan_x+0.5)*dx - 0.5;
    float rate_y = (scan_y+0.5)*dy - 0.5;

    Vector3 direction = (rate_x*rightDirection+rate_y*upDirection+frontDirection);


    scan_x++;
    if(scan_x>=canvas.W){
        scan_x = 0;
        scan_y++;
    }
    if(scan_y>=canvas.H){
        working = false;
        canvas.finish();
    }

    return Ray3(eye, direction);
}

void Camera::resetScan() {
    scan_x = 0;
    scan_y = 0;
}

void Camera::recieveColor(Color3 &color) {
    canvas.light_hit(last_x,last_y,color);
}
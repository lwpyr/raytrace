//
// Created by liwen on 17-12-7.
//

#include "Camera.h"

Camera::Camera(const Vector3& _eye,const Vector3& _front,const Vector3& _up,double angle_x,double angle_y) {
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

Ray3 Camera::generateRay(bool &working, int& x, int& y) {
    last_x = scan_x;
    last_y = scan_y;

    x = last_x;
    y = last_y;

    double rate_x = 2*(scan_x+0.5)*dx - 1;
    double rate_y = 2*(scan_y+0.5)*dy - 1;

    Vector3 direction = (rate_x*v_ref_len*rightDirection+rate_y*h_ref_len*upDirection+frontDirection);


    scan_x++;
    if(scan_x>=canvas.W){
        scan_x = 0;
        scan_y++;
    }
    if(scan_y>=canvas.H){
        working = false;
        canvas.finish();
    }

    return Ray3(eye, direction, true);
}

Ray3 Camera::generateRay(int i) {
    int x = i % canvas.W;
    int y = i / canvas.H;

    double rate_x = 2*(x+0.5)*dx - 1;
    double rate_y = 2*(y+0.5)*dy - 1;

    Vector3 direction = (rate_x*v_ref_len*rightDirection+rate_y*h_ref_len*upDirection+frontDirection);
    return Ray3(eye, direction, true);
}

Ray3 Camera::generateRay(int x, int y) {
    double rate_x = 2*(x+0.5)*dx - 1;
    double rate_y = 2*(y+0.5)*dy - 1;

    Vector3 direction = (rate_x*v_ref_len*rightDirection+rate_y*h_ref_len*upDirection+frontDirection);
    return Ray3(eye, direction, true);
}

int Camera::rayNum() {
    return canvas.W * canvas.H;
}

void Camera::resetScan() {
    scan_x = 0;
    scan_y = 0;
}

void Camera::recieveColor(Color3 &color) {
    canvas.light_hit(last_x,last_y,color);
}
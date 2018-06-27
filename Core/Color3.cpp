//
// Created by liwen on 17-12-7.
//

#include "Color3.h"

Color3::Color3(double R,double G,double B){
    r = R;
    g = G;
    b = B;
}

Color3::Color3(double f) {
    r = f;
    g = f;
    b = f;
}

Color3 Color3::operator+(const Color3 &c){
    return Color3(r + c.r, g + c.g, b + c.b);
}

void Color3::operator+=(const Color3 &c){
    r += c.r; g += c.g; b += c.b;
}

Color3 Color3::operator*(double s) const {
    return Color3(r*s, g*s, b*s);
}
Color3 Color3::operator*(const Color3&c) const {
    return Color3(r*c.r, g*c.g, b*c.b);
}
Color3 Color3::operator/(double c) const {
    return Color3(r/c, g/c, b/c);
}
void Color3::saturate()
{
    r = r>255.0?255.0:r;
    g = g>255.0?255.0:g;
    b = b>255.0?255.0:b;
}

void Color3::operator/=(double s) {
    r /= s;
    g /= s;
    b /= s;
}

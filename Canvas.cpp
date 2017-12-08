//
// Created by liwen on 17-12-7.
//

#include "Canvas.h"
#include <cmath>

Canvas::Canvas(int width, int height) {
    _canvas = vector<vector<Pixel2>>(height, vector<Pixel2>(width));
    W = width;
    H = height;
}

void Canvas::light_hit(float x, float y, const Color3 &color) {
    _canvas[y][x].operator+(color);
}

void Canvas::light_hit(Vector2& v, const Color3 &color){
    _canvas[v.y][v.x].operator+(color);
}

void Canvas::finish() {
    for( auto& row:_canvas){
        for( auto& pixel: row){
            pixel.average();
        }
    }
}

Color3 Canvas::sample(int x, int y) const{
    return _canvas[y][x].color;
}
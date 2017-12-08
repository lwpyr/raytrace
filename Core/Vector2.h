//
// Created by liwen on 17-12-7.
//

#ifndef RAY_TRACER_VECTOR2_H
#define RAY_TRACER_VECTOR2_H

// used in pixel formulation
class Vector2 {
public:
    // constructor and destructor
    Vector2() = default;
    Vector2(float X, float Y):x(X),y(Y){}
    ~Vector2() = default;
    int x;
    int y;
    inline bool operator==(const Vector2& v){
        if(x==v.x&&y==v.y) {
           return true;
        }
        return false;
    }
};
#endif //RAY_TRACER_VECTOR2_H

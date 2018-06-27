//
// Created by liwen on 17-12-7.
//

#ifndef RAY_TRACER_COLOR3_H
#define RAY_TRACER_COLOR3_H


class Color3
{
public:
    // R,G,B value
    double r;
    double g;
    double b;

    // constructor and destructor
    Color3() = default;
    Color3(double _r,double _g,double _b);
    Color3(double f);
    virtual ~Color3() = default;

    // common operations
    Color3 operator+(const Color3& c);
    void operator+=(const Color3& c);
    Color3 operator*(double s) const;
    Color3 operator*(const Color3& c) const;
    Color3 operator/(double c) const;
    void operator/=(double s);

    // max value 255
    void saturate();

    static inline Color3 black(){ return Color3(0,0,0); }
    static inline Color3 white(){ return Color3(255,255,255); }
    static inline Color3 red()  { return Color3(255,0,0); }
    static inline Color3 green(){ return Color3(0,255,0); }
    static inline Color3 blue() { return Color3(0,0,255); }
};

#endif //RAY_TRACER_COLOR3_H

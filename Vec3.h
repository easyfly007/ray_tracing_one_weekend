#ifndef __VEC3__
#define __VEC3__

#include <math.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

class Vec3{
    public:
        Vec3(){}
        Vec3(float e0, float e1, float e2){
            e[0] = e0;
            e[1] = e1;
            e[2] = e2;
        }
        inline float x() const {return e[0];}
        inline float y() const {return e[1];}
        inline float z() const {return e[2];}
        inline float r() const {return e[0];}
        inline float g() const {return e[1];}
        inline float b() const {return e[2];}

        inline const Vec3& operator+() const {return *this;}
        inline Vec3 operator-() const {return Vec3(-e[0], -e[1], -e[2]);}
        inline float operator[](int i) const { return e[i];}
        inline float & operator[](int i) {return e[i];}

        inline float length() const {
            return sqrt(e[0] * e[0] + e[1] * e[1] + e[2] * e[2]);
        }
        inline float add(Vec3 & v, float i){
            return v.e[0] + i;
        }
        inline float squared_length() const {
            return e[0] * e[0] + e[1] * e[1] + e[2] * e[2];
        }
        inline void make_unit_vector(){
            float k = 1.0 / sqrt(e[0] * e[0] + e[1] * e[1] + e[2] * e[2]);
            e[0] *= k; e[1] *= k; e[2] *= k;
        }
        inline Vec3& operator += (const Vec3 &v){
            e[0] += v.e[0];
            e[1] += v.e[1];
            e[2] += v.e[2];
            return *this;
        }
        inline Vec3& operator -= (const Vec3 &v){
            e[0] -= v.e[0];
            e[1] -= v.e[1];
            e[2] -= v.e[2];
            return *this;
        }
        inline Vec3& operator *= (const Vec3 &v){
            e[0] *= v.e[0];
            e[1] *= v.e[1];
            e[2] *= v.e[2];
            return *this;
        }
        inline Vec3& operator /= (const Vec3 &v){
            e[0] /= v.e[0];
            e[1] /= v.e[1];
            e[2] /= v.e[2];
            return *this;
        }

        inline Vec3& operator *= (const float t){
            e[0] *= t;
            e[1] *= t;
            e[2] *= t;
            return *this;
        }
        inline Vec3& operator /= (const float t){
            e[0] /= t;
            e[1] /= t;
            e[2] /= t;
            return *this;
        }
        float e[3];
};

inline Vec3 unit_vector(const Vec3& v){
    float length = v.length();
    return Vec3(v.e[0] / length, v.e[1] / length, v.e[2]/length);
}

inline std::istream & operator>> (std::istream &is, Vec3 &t){
    is >> t.e[0] >> t.e[1] >> t.e[2];
    return is;
}
inline std::ostream & operator<< (std::ostream &os, Vec3 &t){
    os << t.e[0] << t.e[1] << t.e[2];
    return os;
}
inline Vec3 operator+(const Vec3 &v1, const Vec3 &v2){
    return Vec3(v1.e[0] + v2.e[0], v1.e[1] + v2.e[1], v1.e[2] + v2.e[2]);
}
inline Vec3 operator-(const Vec3 &v1, const Vec3 &v2){
    return Vec3(v1.e[0] - v2.e[0], v1.e[1] - v2.e[1], v1.e[2] - v2.e[2]);
}
inline Vec3 operator*(float t, const Vec3 &v){
    return Vec3(v.e[0] * t, v.e[1] * t, v.e[2] * t);
}
inline Vec3 operator*(const Vec3 &v, float t){
    return Vec3(v.e[0] * t, v.e[1] * t, v.e[2] * t);
}
inline Vec3 operator/(const Vec3 &v, float t){
    return Vec3(v.e[0] / t, v.e[1] / t, v.e[2] / t);
}
inline Vec3 operator /(const Vec3 &v1, const Vec3 &v2){
    return Vec3(v1.e[0] / v2.e[0], v1.e[1] / v2.e[1], v1.e[2] / v2.e[2]);
}
inline float dot(const Vec3 &v1, const Vec3 &v2){
    return v1.e[0] * v2.e[0] + v1.e[1] * v2.e[1] + v1.e[2] * v2.e[2];
}
inline Vec3 corss (const Vec3 &v1, const Vec3 &v2){
    return Vec3((v1.e[1] * v2.e[2] - v1.e[2] * v2.e[1]),
            (-(v1.e[0] * v2.e[2] - v1.e[2] * v2.e[0])),
            (v1.e[0] * v2.e[1] - v1.e[1] * v2.e[0]));
}

#endif

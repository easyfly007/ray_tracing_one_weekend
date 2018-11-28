#ifndef __RAY__
#define __RAY__

#include "Vec3.h"
class Ray
{
public:
	Ray(Vec3 & va, Vec3 & vb){
            A = va;
            B = vb;
        }
	Vec3 origin() const {return A;}
	Vec3 direction() const {return B;}
	Vec3 point_at_parameter(float t) const{return  A + t * B;}
	Vec3 A;
	Vec3 B;
};

#endif

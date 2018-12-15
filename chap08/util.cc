#include "Vec3.h"
#include "stdlib.h"

Vec3 random_in_unit_sphere()
{
    Vec3 p;
    do {
        p = 2.0 * Vec3(drand48(), drand48(), drand48()) - Vec3(1,1,1);
    } while (p.squared_length() >= 1.0);
    return p;
}

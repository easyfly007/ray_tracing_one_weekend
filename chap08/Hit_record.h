#include "Vec3.h"
class Material;

struct Hit_record{
    float t;
    Vec3 p;
    Vec3 normal;
    Material *mat_ptr;
};

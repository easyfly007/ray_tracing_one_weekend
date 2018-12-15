#ifndef __HITABLE_H__
#define __HITABLE_H__

#include "Hit_record.h"
#include "Ray.h"

class Hitable{
public:
	virtual bool hit(const Ray &r, float t_min, float t_max, Hit_record &rec) const = 0;
};
#endif

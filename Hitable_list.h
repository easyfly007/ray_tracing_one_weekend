#ifndef _HITABLELIST_H__
#define _HITABLELIST_H__

#include "Hitable.h"

class Hitable_list: public Hitable{
public:
	Hitable_list(){}
	Hitable_list(Hitable **l, int n){
		list = l;
		list_size = n;
	}
	virtual bool hit(const Ray& r, float tmin, float tmax, hit_record &rec) const;
	Hitable **list;
	int list_size;
};

bool Hitable_list::hit(const Ray &r, float tmin, float tmax, hit_record &rec) const
{
	hit_record temp_rec;
	bool hist_anything = false;
	double closest_so_far = tmax;
	for (int i = 0; i < list_size; i ++)
	{
		if (list[i]->hit(r, tmin, closest_so_far, temp_rec))
		{
			hist_anything = true;
			closest_so_far = temp_rec.t;
			rec = temp_rec;
		}
	}
	return hist_anything;

}
#endif

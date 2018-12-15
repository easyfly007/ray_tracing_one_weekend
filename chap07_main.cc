#include <iostream>
#include <stdlib.h>

#include "Sphere.h"
#include "Hitable_list.h"
#include "float.h"
#include "Camera.h"

using namespace std;
Vec3 random_in_unit_sphere()
{
    Vec3 p;
    do {
        p = 2.0 * Vec3(drand48(), drand48(), drand48()) - Vec3(1,1,1);
    }while (p.squared_length() >= 1.0);
    return p;
}

Vec3 color(const Ray & r, Hitable *world)
{
    hit_record rec;

    if (world->hit(r, 0.0, MAXFLOAT, rec))
    {
        Vec3 target = rec.p + rec.normal + random_in_unit_sphere();
        return 0.5 * color (Ray(rec.p, target- rec.p), world);
    }
    else
    {
        Vec3 unit_direction = unit_vector(r.direction());
        float t = 0.5 * (unit_direction.y() + 1.0);
        return (1.0 - t) * Vec3(1.0, 1.0, 1.0) + t * Vec3(0.5, 0.7, 1.0);
    }
}


int main()
{
    int nx = 200;
    int ny = 100;
    int ns = 100;
    cout << "P3\n" << nx << " " << ny << "\n255\n";
    Vec3 lower_left_corner(-2.0, -1.0, -1.0);
    Vec3 horizontal(4.0, 0.0, 0.0);
    Vec3 vertical(0.0, 2.0, 0.0);
    Vec3 origin(0.0, 0.0, 0.0);
    Hitable *list[2];
    list[0] = new Sphere(Vec3(0,0,-1), 0.5);
    list[1] = new Sphere(Vec3(0, -100.5, -1), 100);
    Hitable *world = new Hitable_list(list, 2);
    Camera cam;
    for (int j = ny -1; j >= 0; j--)
    {
        for (int i = 0; i < nx; i ++)
        {
            Vec3 col(0, 0, 0);
            for (int s = 0; s < ns; s ++){
                float u = float(i + drand48()) / float(nx);
                float v = float(j + drand48()) / float(ny);
                Ray r = cam.get_ray(u, v);
                Vec3 p = r.point_at_parameter(2.0);
                col += color(r, world);				
            }
            col /= float(ns);
            col = Vec3(sqrt(col[0]), sqrt(col[1]), sqrt(col[2]));
            int ir = int(255.99 * col[0]);
            int ig = int(255.99 * col[1]);
            int ib = int(255.99 * col[2]);

            std::cout << ir << " " << ig << " " << ib <<"\n";
        }
    }
    return 0;
}

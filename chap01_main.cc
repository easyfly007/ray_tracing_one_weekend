#include <iostream>
using namespace std;
int main(){
	int mx = 200;
	int my = 100;
	std::cout << "P3" << endl << nx << " " << ny << endl << "255" << endl;
	for (int j = ny -1; j >= 0; j --){
		for (int i = 0; i < nx; i ++){
			float r = float(i) / float(nx);
			float g = float(j) / float(ny);
			float b = 0.2;
			int ir = int(255.99 * r);
			int ig = int(255.99 * g);
			int ib = int(255.99 * b);
			std::cout << ir << " " << ig << " " << ib << endl;
		}
	}
}
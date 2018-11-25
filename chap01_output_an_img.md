图片的 PPM 格式表示：
我们可以用 RGB 来表示一个像素的颜色，每个颜色通道（R 或者 G 或者 B）的取值范围是 0到255，包含0 和255。
<img src="img01">

PPM 的表示，就是用 连续相邻的三个颜色通道的数值表示一个像素点的颜色，换行表示一个新的像素行。
如图，我们可以用 

P3
# the P3 means colors are in ASCII, then 3 columns and 2 rows,
# then 255 for max color, then RGB triplets
3 2
255
255 0	0	0	255	0	0	0	255
255	255	0	255	255	255	0	0	0	

<pre>
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
</pre>
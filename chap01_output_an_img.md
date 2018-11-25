图片的 PPM 格式表示：
我们可以用 RGB 来表示一个像素的颜色，每个颜色通道（R 或者 G 或者 B）的取值范围是 0到255，包含0 和255。
<img src="img01">

PPM 的表示，就是用 连续相邻的三个颜色通道的数值表示一个像素点的颜色，换行表示一个新的像素行。


<pre>
P3
# the P3 means colors are in ASCII, then 3 columns and 2 rows,
# then 255 for max color, then RGB triplets
3 2
255
255 0	0	0	255	0	0	0	255
255	255	0	255	255	255	0	0	0	
</pre>

你可以用 chap01_ppm.cc 或者 chap01_ppm.py 来生成一个ppm 文件，然后你找一个 ppm viewer 来看，会发现是这样子的
<img src="chap01_ppm.png">

比如说，一个在线的 ppm 浏览器，
<a href="http://web.eecs.utk.edu/~smarz1/pgmview/">http://web.eecs.utk.edu/~smarz1/pgmview/</a>

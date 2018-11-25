filename = 'img.ppm'

with open(filename, 'w') as f:
	nx = 200
	ny = 100
	f.write("P3\n" + str(nx) + " " + str(ny) + "\n" + "255\n")
	for j in range(ny-1, -1, -1):

		for i in range(0, nx):
			r = float(i) / float(nx)
			g = float(j) / float(ny)
			b = 0.2
			r = int(255.99 * r)
			g = int(255.99 * g)
			b = int(255.99 * b)
			f.write(str(r) + " " + str(g) + " " + str(b) + "\n")

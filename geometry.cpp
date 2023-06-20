#include "geometry.h"
#include "constants.h"
#include <math.h>

	geometry::geometry(int reso_in, float xdim_in, float ydim_in, float timestep)
	{
		resolution = reso_in;
		xdim = xdim_in;
		ydim = ydim_in;
		xsize = xdim * resolution;
		ysize = ydim * resolution;
		tstep = timestep;
		vector<vector<float>> v1(xdim * resolution, vector<float>(ydim * resolution, 13));
		vector<vector<float>> v2(xdim * resolution, vector<float>(ydim * resolution, 1));

		epscell = v1;
		mucell = v2;

	}

	void geometry::block(float xcenter, float ycenter, float length, float width, float eps, float mu) {

		int xmin = (xcenter - length / 2) * resolution;
		int xmax = (xcenter + length / 2) * resolution;
		int ymin = (ycenter - width / 2) * resolution;
		int ymax = (ycenter + width / 2) * resolution;

		if (xmin < 0)
			xmin = 0;

		if (xmax >= xsize)
			xmax = xsize - 1;

		if (ymin < 0)
			ymin = 0;

		if (ymax >= ysize)
			ymax = ysize - 1;



		for (int i = xmin; i <= xmax; i++) {
			for (int j = ymin; j <= ymax; j++) {
				epscell[i][j] = eps;
				mucell[i][j] = mu;
			}
		}
	}

	void geometry::tiltedblock(float theta, float dist, float eps, float mu) {
		int distindx = dist * resolution;
		for (int i = 0; i <= xsize-1; i++) {
			for (int j = 0; j <= ysize-1; j++) {
				if (i * cos(theta * pi / 180) / sin(theta * pi / 180) - j - distindx * cos(theta * pi / 180) / sin(theta * pi / 180) >= 0) {
					epscell[i][j] = eps;
					mucell[i][j] = mu;
				}

			}
		}
	}

	void geometry::disk(float xcenter, float ycenter, float radius, float eps, float mu) {
		int xmin = (xcenter - radius) * resolution;
		int xmax = (xcenter + radius) * resolution;
		int ymin = (ycenter - radius) * resolution;
		int ymax = (ycenter + radius) * resolution;

		if (xmin < 0)
			xmin = 0;

		if (xmax >= xsize)
			xmax = xsize - 1;

		if (ymin < 0)
			ymin = 0;

		if (ymax >= ysize)
			ymax = ysize - 1;


		for (int i = xmin; i <= xmax; i++) {
			for (int j = ymin; j <= ymax; j++) {
				if ((xcenter * resolution - i) * (xcenter * resolution - i) + (ycenter * resolution - j) * (ycenter * resolution - j) <= radius * resolution * radius * resolution)
				{
					epscell[i][j] = eps;
					mucell[i][j] = mu;
				}
					
			}
		}
	}

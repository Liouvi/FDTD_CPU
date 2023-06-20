#include "curl.h"
#include "geometry.h"
#include <cmath>

curl::curl(geometry& GEO) {


	vector<vector<float>> v(GEO.epscell.size(), vector<float>(GEO.epscell[0].size(), 0.));

	epscell = GEO.epscell;
	mucell = GEO.mucell;
	resolution = GEO.resolution;
	tstep = GEO.tstep;

	

	xstep = 1e-6 / resolution;

	Ex = v;
	Ey = v;
	Ez = v;

	Hx = v;
	Hy = v;
	Hz = v;

	Dx = v;
	Dy = v;
	Dz = v;

	CurlEx = v;
	CurlEy = v;
	CurlEz = v;

	CurlHx = v;
	CurlHy = v;
	CurlHz = v;
}

void curl::updateHz() {

	int xmax = epscell.size() - 1;
	int ymax = epscell[0].size() - 1;

	// Curl

	CurlEz[xmax][ymax] =( (0 - Ey[xmax][ymax]) - (0 - Ex[xmax][ymax]) ) / xstep;

	for (int i = 0; i < xmax; i++) {
		CurlEz[i][ymax] =  ( ( 0 - Ey[i][ymax] ) - (0 - Ex[i][ymax] ) ) /xstep;
	}


	for (int j = 0; j < ymax; j++)
	{
		CurlEz[xmax][j] =( (0 - Ey[xmax][j]) - (0 - Ex[xmax][j]) ) / xstep;
		for (int i = 0; i < xmax; i++)
			CurlEz[i][j] = ( (Ey[i + 1][j] - Ey[i][j]) - (Ex[i][j + 1] - Ex[i][j]) ) / xstep;
	}

	// Hz Update

	for (int i = 0; i < xmax; i++) {
		for (int j = 0; j < ymax; j++) {
			Hz[i][j] =  Hz[i][j] + (-speedoflight*tstep / mucell[i][j]) * CurlEz[i][j];
		}

	}

}

void curl::updateDx() {

int xmax = epscell.size() - 1;
int ymax = epscell[0].size() - 1;

	// Curl

	for (int i = 0; i <= xmax; i++)
	{
		CurlHx[i][0] = (Hz[i][0] - 0) / xstep;
		for (int j = 1; j <= ymax; j++)
			CurlHx[i][j] = (Hz[i][j] - Hz[i][j - 1]) / xstep;
	}

	// Dx Update

	for (int i = 0; i < xmax; i++) {
		for (int j = 0; j < ymax; j++) {
			Dx[i][j] = Dx[i][j] + (speedoflight * tstep)* CurlHx[i][j];
		}

	}

}

void curl::updateDy()	{
	int xmax = epscell.size() - 1;
	int ymax = epscell[0].size() - 1;

	// Curl

	for (int j = 0; j <= xmax; j++)
	{
		CurlHy[0][j] = -(Hz[0][j] - 0);
		for (int i = 1; i <= ymax; i++)
			CurlHy[i][j] = -(Hz[i][j] - Hz[i - 1][j]) / xstep;
	}

	// Dy Update

	for (int i = 0; i < xmax; i++) {
		for (int j = 0; j < ymax; j++) {
			Dy[i][j] = Dy[i][j] + (speedoflight * tstep) * CurlHy[i][j];
		}

	}

}

void curl::updateE() {
	int xmax = epscell.size() - 1;
	int ymax = epscell[0].size() - 1;

	for (int i = 0; i <= xmax; i++)
		for (int j = 0; j < ymax; j++)
		{
			Ex[i][j] = Dx[i][j] / epscell[i][j];
			Ey[i][j] = Dy[i][j] / epscell[i][j];
		}

}

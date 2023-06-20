#ifndef CURLV2_H
#define CURLV2_H
#include<algorithm>
#include<iostream>
#include<vector>
#include "constants.h"
#include <cmath>
#include "geometry.h"

using namespace std;

class curl
{
public:
	vector<vector<float>> Ex;
	vector<vector<float>> Ey;
	vector<vector<float>> Ez;

	vector<vector<float>> Dx;
	vector<vector<float>> Dy;
	vector<vector<float>> Dz;

	vector<vector<float>> Hx;
	vector<vector<float>> Hy;
	vector<vector<float>> Hz;

	vector<vector<float>> CurlEx;
	vector<vector<float>> CurlEy;
	vector<vector<float>> CurlEz;

	vector<vector<float>> CurlHx;
	vector<vector<float>> CurlHy;
	vector<vector<float>> CurlHz;

	vector<vector<float>> epscell;
	vector<vector<float>> mucell;

	float tstep;
	int resolution;
	float xstep;
	float courantnumber = 0.5;


	void updateHx();
	void updateHy();
	void updateHz();


	void updateDx();
	void updateDy();
	void updateDz();

	void updateE();

	curl(geometry& GEO);

	friend class geometry;


};


#endif
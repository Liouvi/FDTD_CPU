#include "geometry.h"
#include "curl.h"
#include "sourcetime.h"
#include "constants.h"
#include "dataacc.h"
#include "init.h"
#include "sim.h"
#include <cmath>



int main()
{
	// Geometry Defn and Other Definitions

	float xdim =16.0;
	float ydim = 16.0;
	int resolution = 64;
	float eps_si = pow(3.47,2);
	float mu = 1;
	int maxtime = 2500;

	int xsize = xdim * resolution;
	float freq = 193.41449e12;
	float xstep = 1e-6 / resolution;
	float courantnumber = 0.5;
	float timestep = courantnumber * xstep / speedoflight;

	// Create Geometry Object

	geometry lattice {resolution,xdim, ydim,timestep};

	// Get Geometry
	dat.extract(lattice.epscell,"eps.dat");

	// Create E-H field grid and set the simulation functions

	curl Grid2D{lattice};
	
	// Main Loop
	
	sim(Grid2D,
		dat,
		Srctime,
		freq,
		maxtime,
		timestep);

}




	

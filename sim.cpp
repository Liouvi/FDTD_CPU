#include "sim.h"
#include "curl.h"
#include "dataacc.h"
#include "sourcetime.h"
#include <thread>
#include <cmath>


void sim(curl& Grid2D, dataacc& dat, sourcetime& Srctime,double freq, double maxtime, double timestep) {
	int frame = 0;
	for (int qtime = 0; qtime < maxtime; qtime++) {

		Grid2D.updateHz();
		Grid2D.updateDx();
		Grid2D.updateDy();
		
		for (int j = 0; j < 10; j++) {
			for (int i=0; i<10;i++)
			Grid2D.Hz[507+i][507+j] += Srctime.sinesource(qtime, 2 * pi * freq, timestep);
		}

		Grid2D.updateE();

		if (qtime % 10 == 0) {
			string name = "outputs/Hz";
			name.append(to_string(frame));
			string exten = ".dat";
			dat.extract(Grid2D.Hz, name + exten);
			frame += 1;
		}

	}

}
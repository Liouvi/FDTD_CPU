#ifndef SOURCETIME_H
#define SOURCETIME_H
#include <math.h>

class sourcetime
{
public:
	double expsource(int qtime);
	double sinesource(int qtime, double freq, double timestep);
};

#endif

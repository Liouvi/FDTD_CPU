#include "sourcetime.h"


// SourceTime Expressions go here

double sourcetime::expsource(int qtime) {
	return 1 * exp(-( (qtime)- 30.) * ( (qtime) - 30.) / 100.);
}


double sourcetime::sinesource(int qtime,double freq, double timestep) {
	return 1 * sin(freq * timestep * qtime) * (1-exp(-qtime / 5));
};
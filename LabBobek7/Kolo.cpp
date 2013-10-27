#include "Kolo.h"
#include <math.h>

Kolo::Kolo(double x, double y, double r) :
		x(x), y(y), r(r) {
}

Kolo::~Kolo() {
}

double Kolo::pole() {
	return M_PI * r * r;
}


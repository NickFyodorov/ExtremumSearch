#include "norm.h"

double norm(const vPoint & X)
{
	double s = 0;
	for (int i = 0; i < X.n_elem; ++i) {
		s += (X[i] * X[i]);
	}
	s = sqrt(s);
	return s;
}

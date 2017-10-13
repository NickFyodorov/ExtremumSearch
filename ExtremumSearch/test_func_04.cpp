#include "test_func_04.h"

double TestFunc04::eval(const vPoint & X) const
{
	return 100 * (X[2] - X[1] * X[1] * X[1])*(X[2] - X[1] * X[1] * X[1]) + (1 - X[1])*(1 - X[1]);
}

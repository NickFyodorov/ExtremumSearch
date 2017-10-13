#include "test_func_01.h"

double TestFunc01::eval(const vPoint & X) const
{
	return 100 * (X[1] - X[0]*X[0])*(X[1] - X[0] * X[0]) + (1 - X[0])*(1 - X[0]);
}

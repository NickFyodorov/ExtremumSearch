#include "test_func_03.h"

double TestFunc03::eval(const vPoint & X) const
{
	return (X[2] - X[1] * X[1])*(X[2] - X[1] * X[1]) + 100 * (1 - X[1])*(1 - X[1]);
}

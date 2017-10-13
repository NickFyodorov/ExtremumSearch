#include "test_func_03.h"

double TestFunc03::eval(const vPoint & X) const
{
	return (X[1] - X[0] * X[0])*(X[1] - X[0] * X[0]) + 100 * (1 - X[0])*(1 - X[0]);
}

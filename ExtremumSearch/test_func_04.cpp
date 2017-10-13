#include "test_func_04.h"

double TestFunc04::eval(const vPoint & X) const
{
	return 100 * (X[1] - X[0] * X[0] * X[0])*(X[1] - X[0] * X[0] * X[0]) + (1 - X[0])*(1 - X[0]);
}

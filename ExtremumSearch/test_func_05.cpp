#include "test_func_05.h"

double TestFunc05::eval(const vPoint & X) const
{
	return (1.5 - X[0] * (1 - X[1])) + (2.25 - X[0] * (1 - X[1]) * (1 - X[1]))*(2.25 - X[0] * (1 - X[1]) * (1 - X[1])) + (2.625 - X[0] * (1 - X[1] * X[1] * X[1])) * (2.625 - X[0] * (1 - X[1] * X[1] * X[1]));
}

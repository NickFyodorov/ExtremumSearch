#include "test_func_02.h"

double TestFunc02::eval(const vPoint & X) const
{
	return (X[2] - X[1]*X[1])*(X[2] - X[1] * X[1]) + (1 - X[1])*(1 - X[1]);
}

#include "test_func_02.h"

double TestFunc02::eval(const vPoint & X) const
{
	return (X[1] - X[0]*X[0])*(X[1] - X[0] * X[0]) + (1 - X[0])*(1 - X[0]);
}

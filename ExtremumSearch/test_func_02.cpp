#include "test_func_02.h"

double TestFunc02::eval(const vPoint &X) const
{
	return (X[1] - X[0] * X[0]) * (X[1] - X[0] * X[0]) +
		   (1 - X[0]) * (1 - X[0]);
}

void TestFunc02::Info() const
{
	std::cout << "F(X1, X2) = (X2 - X1^2)^2 + (1 - X1)^2";
}

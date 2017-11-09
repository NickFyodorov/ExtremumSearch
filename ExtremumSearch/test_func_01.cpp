#include "test_func_01.h"

double TestFunc01::eval(const vPoint &X) const
{
	return 100 * (X[1] - X[0] * X[0]) * (X[1] - X[0] * X[0]) +
		   (1 - X[0]) * (1 - X[0]);
}

void TestFunc01::Info() const
{
	std::cout << "F(X1, X2) = 100 * (X2 - X1^2)^2 + (1 - X1)^2";
}

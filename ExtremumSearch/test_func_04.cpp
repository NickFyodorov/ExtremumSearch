#include "test_func_04.h"

double TestFunc04::eval(const vPoint &X) const
{
	return 100 * (X[1] - X[0] * X[0] * X[0]) * (X[1] - X[0] * X[0] * X[0]) +
		   (1 - X[0]) * (1 - X[0]);
}

void TestFunc04::Info() const
{
	std::cout << "F(X1, X2) = 100 * (X2 - X1^3)^2 + (1 - X1)^2";
}

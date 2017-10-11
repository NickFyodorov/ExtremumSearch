#include "function.h"

double CalcGrad(const Function * F, const vPoint & X, double delta)
{
	return (F->eval(X + delta) - F->eval(X - delta)) / (2 * delta);
}

double CalcHessian(const Function * F, const vPoint & X, double delta)
{
	return (F->eval(X + delta) + F->eval(X - delta) - 2 * F->eval(X) ) / (delta * delta);
}

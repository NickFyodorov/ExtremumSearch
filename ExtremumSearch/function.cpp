#include "function.h"

double CalcGrad(Function * F, const vPoint & X, double delta)
{
	return (F->eval(X + delta) - F->eval(X - delta)) / (2 * delta);
}

double CalcHessian(Function * F, const vPoint & X, double delta)
{
	return (F->eval(X + delta) + F->eval(X - delta) - 2 * F->eval(X) ) / (delta * delta);
}

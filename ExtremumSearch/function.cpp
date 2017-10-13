#include "function.h"

double CalcGrad(const Function * F, const vPoint & X, double delta)
{
	vPoint Xleft(X), Xright(X);
	Xleft -= delta;
	Xright += delta;
	return (F->eval(Xright) - F->eval(Xleft)) / (2 * delta);
}

double CalcHessian(const Function * F, const vPoint & X, double delta)
{
	vPoint Xleft(X), Xright(X);
	Xleft -= delta;
	Xright += delta;
	return (F->eval(Xright) + F->eval(Xleft) - 2 * F->eval(X) ) / (delta * delta);
}

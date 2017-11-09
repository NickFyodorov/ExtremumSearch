#include "function.h"

double CalcGrad(std::shared_ptr<Function> F, const vPoint &X, double delta)
{
	vPoint Xleft = X + delta, Xright = X - delta;
	return (F->eval(Xright) - F->eval(Xleft)) / (2 * delta);
}

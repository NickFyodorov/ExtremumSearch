#pragma once

#include "function.h"
#include "area.h"

class SmoothFunction : Function {
    Function * grad;
public:
	SmoothFunction(Area * _domain, Function * _grad = 0) : grad(_grad), Function(_domain) {}
	double evalGrad(const vPoint& X) const { return grad->eval(X); }
	Function * GetGrad() const { return grad; }
};
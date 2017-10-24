#pragma once

#include <memory>

#include "function.h"
#include "area.h"

class SmoothFunction : public Function {
    std::shared_ptr<Function> grad;
public:
	SmoothFunction(std::shared_ptr<Area> _domain, std::shared_ptr<Function> _grad = 0) : grad(_grad), Function(_domain) {}
	double evalGrad(const vPoint& X) const { return grad->eval(X); }
	std::shared_ptr<Function> GetGrad() const { return grad; }
};
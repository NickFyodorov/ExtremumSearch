#pragma once

#include "terminal_condition.h"
#include "eps_condition.h"
#include "smooth_function.h"

const double DELTA_MULT = 1e-3;

class ConditionGrad : public EpsCondition {
public:
	ConditionGrad(double _eps) : EpsCondition(_eps) {}
	~ConditionGrad() {}
	virtual bool Stop(std::shared_ptr<Function> F, const std::vector<vPoint>& Approx, const std::vector<double> Evals) const;
};

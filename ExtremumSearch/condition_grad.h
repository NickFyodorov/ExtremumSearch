#pragma once

#include "terminal_condition.h"
#include "eps_condition.h"
#include "smooth_function.h"

class ConditionGrad : public EpsCondition {
public:
	ConditionGrad(double _eps) : EpsCondition(_eps) {}
	~ConditionGrad() {}
	virtual bool Stop(const Function * F, const std::vector<vPoint>& Approx) const;
};

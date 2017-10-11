#pragma once

#include "terminal_condition.h"
#include "eps_condition.h"
#include "smooth_function.h"

class ConditionGrad : EpsCondition {
public:
	virtual bool Stop(const Function * F, const vPointSeq& Approx) const;
};

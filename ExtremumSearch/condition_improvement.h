#pragma once

#include "terminal_condition.h"
#include "eps_condition.h"
#include "count_condition.h"

class ConditionImprovement : CountCondition {
public:
	virtual bool Stop(const Function * F, const vPointSeq& Approx) const;
};

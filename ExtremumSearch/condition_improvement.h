#pragma once

#include "terminal_condition.h"
#include "eps_condition.h"
#include "count_condition.h"

class ConditionImprovement : public CountCondition {
public:
	ConditionImprovement(int _mcount) : CountCondition(_mcount) {}
	~ConditionImprovement() {}
	virtual bool Stop(const Function * F, const std::vector<vPoint>& Approx) const;
};
#pragma once

#include "terminal_condition.h"
#include "function.h"
#include "area.h"

#include "count_condition.h"

class ConditionIter : public CountCondition {
private:
	int max_count;
public:
	ConditionIter(int _mcount) : CountCondition(_mcount) {}
	virtual bool Stop(const Function * F, const std::vector<vPoint>& Approx) const;
};

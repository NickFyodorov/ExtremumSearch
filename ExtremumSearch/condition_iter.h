#pragma once

#include "terminal_condition.h"
#include "function.h"
#include "area.h"
#include "custom_defines.h"
#include "count_condition.h"

class ConditionIter : CountCondition {
private:
	int max_count;
public:
	ConditionIter(int _mcount) : CountCondition(_mcount) {}
	virtual bool Stop(const Function * F, const vPointSeq& Approx) const;
};

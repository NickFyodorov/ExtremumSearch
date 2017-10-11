#pragma once

#include "terminal_condition.h"
#include "eps_condition.h"

class ConditionXDiff : EpsCondition {
private:
	double epsilon;
public:
	ConditionXDiff(double _eps) : EpsCondition(_eps) {}
	virtual ~ConditionXDiff() {}
	virtual bool Stop(const Function * F, const vPointSeq& Approx) const;
};

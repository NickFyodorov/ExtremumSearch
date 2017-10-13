#pragma once

#include "terminal_condition.h"
#include "eps_condition.h"

class ConditionXDiff : public EpsCondition {
private:
	double epsilon;
public:
	ConditionXDiff(double _eps) : EpsCondition(_eps) {}
	virtual ~ConditionXDiff() {}
	virtual bool Stop(const Function * F, const std::vector<vPoint>& Approx) const;
};

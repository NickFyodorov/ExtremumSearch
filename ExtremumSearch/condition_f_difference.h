#pragma once

#include "terminal_condition.h"
#include "eps_condition.h"

class ConditionFDiff : public EpsCondition {
private:
	double epsilon;
public:
	ConditionFDiff(double _eps) : EpsCondition(_eps) {}
	virtual ~ConditionFDiff() {}
	virtual bool Stop(const Function * F, const std::vector<vPoint>& Approx) const;
};

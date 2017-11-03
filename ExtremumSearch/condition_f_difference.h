#pragma once

#include "terminal_condition.h"
#include "eps_condition.h"

class ConditionFDiff : public EpsCondition {
private:
	double epsilon;
public:
	ConditionFDiff(double _eps) : EpsCondition(_eps) {}
	virtual ~ConditionFDiff() {}
	virtual bool Stop(std::shared_ptr<Function> F, const std::vector<vPoint>& Approx, const std::vector<double> & Evals) const override;
	virtual void Info() const;
};

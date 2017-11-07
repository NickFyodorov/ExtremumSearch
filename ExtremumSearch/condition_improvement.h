#pragma once

#include "terminal_condition.h"
#include "eps_condition.h"
#include "count_condition.h"


/*!
\section DESCRIPTION
ConditionImprovement class is derived from CountCondition and represents a terminal condition based with the method of termination based on the number of failures to improve the current approximation.
*/
class ConditionImprovement : public CountCondition {
public:
	ConditionImprovement(int _mcount) : CountCondition(_mcount) {}///< constructor
	~ConditionImprovement() {}///< destructor
	/*!
	Overrides TerminalCondtion::Stop
	\return FALSE if in the last CountCondition::max_count of iterations the approximation was not improved and TRUE otherwise
	*/
	virtual bool Stop(std::shared_ptr<Function> F, const std::vector<vPoint> & Approx, const std::vector<double>& Evals) const override;
	virtual void Info() const;///< writes the name of the condition and the current value of 
};

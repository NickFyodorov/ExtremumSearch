#pragma once

#include "terminal_condition.h"
#include "eps_condition.h"

/*!
\section DESCRIPTION
ConditionFDiff class is derived from EpsCondition and represents a terminal condition based on the current value between the function evaluations of the last two approximations.
*/
class ConditionFDiff : public EpsCondition
{
  public:
	ConditionFDiff(double _eps) : EpsCondition(_eps) {} ///< constructor
	virtual ~ConditionFDiff() {}						///< destructor
	/*!
	Overrides TerminalCondition::Stop
	\return TRUE if the absolute value of the difference of the function evaluations of the two last approximations is less than epsilon and FALSE otherwise
	*/
	virtual bool Stop(
		std::shared_ptr<Function> F,
		const std::vector<vPoint> &Approx,
		const std::vector<double> &Evals) const override;
	virtual void Info() const; ///< writes the name of the condition and the current value of epsilon
};

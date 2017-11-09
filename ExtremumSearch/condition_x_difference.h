#pragma once

#include "terminal_condition.h"
#include "eps_condition.h"

/*!
\section DESCRIPTION
ConditionXDiff class is derived from EpsCondition and represents a terminal condition based on the current value of the norm of the difference between the last two approximations.
*/

class ConditionXDiff : public EpsCondition
{
  private:
	double epsilon;

  public:
	ConditionXDiff(double _eps) : EpsCondition(_eps) {} ///< constructor
	virtual ~ConditionXDiff() {}						///< destructor
	/*!
	Overrides TerminalCondition::Stop.
	\return TRUE if the norm of the difference betweeen the two last approximations is less than epsilon and FALSE otherwise.
	*/
	virtual bool Stop(std::shared_ptr<Function> F, const std::vector<vPoint> &Approx, const std::vector<double> &Evals) const override;
	virtual void Info() const; ///< writes the name of the condition and the current value of epsilon
};

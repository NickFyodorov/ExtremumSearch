#pragma once

#include "terminal_condition.h"
#include "function.h"
#include "area.h"

#include "count_condition.h"

/*!
\section DESCRIPTION
ConditionIter class is derived from CountCondition and represents a terminal condition based on the current number of iterations.
*/
class ConditionIter : public CountCondition
{
  public:
	ConditionIter(int _mcount) : CountCondition(_mcount) {} ///< constructor
	/*!
	Overrides TerminalCondition::Stop
	\return TRUE if the number of iteration exceeds the maximum count and FALSE otherwise
	*/
	virtual bool Stop(
		std::shared_ptr<Function> F,
		const std::vector<vPoint> &Approx,
		const std::vector<double> &Evals) const override;
	virtual void Info() const; ///< writes the name of the method and the current value of maximum count of iterations
};

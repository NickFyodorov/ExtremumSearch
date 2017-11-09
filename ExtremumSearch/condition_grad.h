#pragma once

#include "terminal_condition.h"
#include "eps_condition.h"
#include "smooth_function.h"

const double DELTA_MULT = 1e-3;

/*!
\section DESCRIPTION
ConditioGrad class is derived from EpsCondition and represents a terminal condition based on the current value of the gradient of the function in the last approximation.
*/

class ConditionGrad : public EpsCondition
{
  public:
	ConditionGrad(double _eps) : EpsCondition(_eps) {} ///< constructor
	~ConditionGrad() {}								   ///< destructor
	/*!
	Overrides TerminalCondition::Stop.
	\return TRUE if the absolute value of the gradient of the function for the last approximation is less than epsilon and FALSE otherwise.
	*/
	virtual bool Stop(
		std::shared_ptr<Function> F,
		const std::vector<vPoint> &Approx,
		const std::vector<double> &Evals) const override;
	virtual void Info() const; ///< writes the name of the condition and the current value of epsilon
};

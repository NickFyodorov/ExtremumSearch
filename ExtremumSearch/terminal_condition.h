#pragma once

#include <vector>
#include <memory>

#include "function.h"
#include "area.h"
#include "vpoint.h"

const long CRIT_ITER = 1000000000; ///< default critical number of iterations constant

/*!
\section DESCRIPTION

The TerminalCondition class represents a method of termination of an optimization process based on the process state
*/
class TerminalCondition
{
	long crititer; ///< critical number of iterations
  public:
	/*!
	constructor that sets the critical number of iterations to a given value
	*/
	TerminalCondition(long _crititer = CRIT_ITER);
	int GetCritIter() const { return crititer; } ///< returns critical number of iterations
	/*!
	analyzes whether the optimization process should be terminated based on the current state of the optimization
	\param F a pointer to the function that is being optimized
	\param Approx std::vector of approximation vector points
	\param Evals std::vector of function evaluations in approximation points
	\return true if the condition requirements for termination are met and false otherwise
	*/
	virtual bool Stop(
		std::shared_ptr<Function> F,
		const std::vector<vPoint> &Approx,
		const std::vector<double> &Evals) const
	{
		return Evals.size() > GetCritIter();
	};
	/*!
	writes the information about the terminal condition to std::cout
	*/
	virtual void Info() const = 0;
	/*!
	overloaded output operator for std::cout
	*/
	friend std::ostream &operator<<(std::ostream &out, std::shared_ptr<TerminalCondition> T)
	{
		T->Info();
		return out;
	}
};
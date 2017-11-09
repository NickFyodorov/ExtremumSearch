#pragma once

#include "terminal_condition.h"

/*!
\section DESCRIPTION

The CountCondition class represents a TerminalCondition with an integer number as main parameter (the count of an event)
*/
class CountCondition : public TerminalCondition
{
  private:
	int max_count; ///< main parameter
  public:
	CountCondition(int _mcount);				  ///< constructor that sets the main parameter of the condition
	virtual ~CountCondition() {}				  ///< destructor
	bool SetMaxCount(int _mcount);				  ///< sets the maximum count of the event to a given value with argument validation.
	int GetMaxCount() const { return max_count; } ///< returns the maximum count
};

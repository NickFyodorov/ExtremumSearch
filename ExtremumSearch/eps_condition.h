#pragma once

#include "terminal_condition.h"

class EpsCondition : public TerminalCondition
{
  protected:
	double epsilon; ///< the main parameter of the condition (a double that is used in number comparison)
  public:
	EpsCondition(double _eps);				  ///< constructor that sets the main parameter of the condition
	virtual ~EpsCondition() {}				  ///< destructor
	bool SetEps(double _eps);				  ///< sets the main parameter of the condition with argument validation
	double GetEps() const { return epsilon; } ///< returns the main parameter of the condition
};

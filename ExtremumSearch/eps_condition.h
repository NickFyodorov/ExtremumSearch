#pragma once

#include "terminal_condition.h"

class EpsCondition : public TerminalCondition {
protected:
	double epsilon;
public:
	EpsCondition(double _eps);
	virtual ~EpsCondition() {}
	bool SetEps(double _eps);
	double GetEps() const { return epsilon; }
};

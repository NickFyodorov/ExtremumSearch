#include "terminal_condition.h"

TerminalCondition::TerminalCondition(long _crititer)
{
	if (_crititer <= 0)
		throw std::invalid_argument("Critical number of iterations
		must be a positive integer");
	crititer = _crititer;
}

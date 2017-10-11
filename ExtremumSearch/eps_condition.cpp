#include "eps_condition.h"

EpsCondition::EpsCondition(double _eps)
{
	if (!SetEps(_eps)) {
		//exception
	}
}

bool EpsCondition::SetEps(double _eps)
{
	if (_eps <= 0) return false;
	epsilon = _eps;
	return false;
}

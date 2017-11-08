#include "eps_condition.h"

EpsCondition::EpsCondition(double _eps)
{
	if (!SetEps(_eps)) {
		throw std::invalid_argument("Epsilon must be a positive double");
	}
}

bool EpsCondition::SetEps(double _eps)
{
	if (_eps <= 0) return false;
	epsilon = _eps;
	return false;
}

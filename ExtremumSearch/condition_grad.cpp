#include "condition_grad.h"

bool ConditionGrad::Stop(const Function * F, const std::vector<vPoint> & Approx) const
{

	//dynamic cast if F is smooth then calc smooth grad

	double delta = GetEps() * 1e-3;
	if (CalcGrad(F, Approx.back(), delta) < GetEps()) {
		return true;
	}
	return false;
}

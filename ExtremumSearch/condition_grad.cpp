#include "condition_grad.h"

bool ConditionGrad::Stop(std::shared_ptr<Function> F, const std::vector<vPoint> &Approx, const std::vector<double> &Evals) const
{
	//dynamic cast if F is smooth then calc smooth grad
	if (Evals.size() > GetCritIter())
		return true;
	double delta = GetEps() * DELTA_MULT;
	if (CalcGrad(F, Approx.back(), delta) < GetEps())
		return true;
	return false;
}

void ConditionGrad::Info() const
{
	std::cout << "Condition Grad(Eps = " << GetEps() << ")";
}

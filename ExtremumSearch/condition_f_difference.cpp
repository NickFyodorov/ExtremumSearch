#include "condition_f_difference.h"

bool ConditionFDiff::Stop(std::shared_ptr<Function> F, const std::vector<vPoint> &Approx, const std::vector<double> &Evals) const
{
	int n = Evals.size();
	if ((n > GetCritIter()) || (n > 1 && fabs(Evals[n - 1] - Evals[n - 2]) < GetEps()))
		return true;
	return false;
}

void ConditionFDiff::Info() const
{
	std::cout << "Condition FDiff("
			  << "Eps = " << GetEps() << ")";
}

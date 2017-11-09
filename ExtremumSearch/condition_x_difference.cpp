#include "condition_x_difference.h"

bool ConditionXDiff::Stop(
	std::shared_ptr<Function> F,
	const std::vector<vPoint> &Approx,
	const std::vector<double> &Evals) const
{
	if (Evals.size() > GetCritIter())
		return true;
	int n = Approx.size();
	if (n > 1 && (norm(Approx[n - 1] - Approx[n - 2]) < GetEps()))
		return true;
	return false;
}

void ConditionXDiff::Info() const
{
	std::cout << "Condition XDiff("
			  << "Eps = " << GetEps() << ")";
}

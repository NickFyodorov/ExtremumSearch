#include "condition_iter.h"

bool ConditionIter::Stop(std::shared_ptr<Function> F, const std::vector<vPoint> &Approx, const std::vector<double> &Evals) const
{
	if (Evals.size() > GetCritIter())
		return true;
	return Approx.size() > GetMaxCount();
}

void ConditionIter::Info() const
{
	std::cout << "Condition Iter(N = " << GetMaxCount() << ")";
}

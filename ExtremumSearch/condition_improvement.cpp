#include "condition_improvement.h"
#include "count_condition.h"

bool ConditionImprovement::Stop(
	std::shared_ptr<Function> F,
	const std::vector<vPoint> &Approx,
	const std::vector<double> &Evals) const
{
	if (Evals.size() > GetCritIter())
		return true;
	if (Approx.size() <= GetMaxCount())
		return false;

	int n = Approx.size();

	for (int i = 0; i < GetMaxCount(); ++i)
	{
		if (Evals[n - i - 2] > Evals[n - 1])
			return false;
	}

	return true;
}

void ConditionImprovement::Info() const
{
	std::cout << "Condition Improvement(N = " << GetMaxCount() << ")";
}

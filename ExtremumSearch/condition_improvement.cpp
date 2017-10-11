#include "condition_improvement.h"
#include "count_condition.h"

bool ConditionImprovement::Stop(const Function * F, const vPointSeq & Approx) const
{
	if (Approx.size() < GetMaxCount()) return false;

	int n = Approx.size();

	double current = F->eval(Approx[n - 1]);

	for (int i = 0; i < GetMaxCount(); ++i) {
		if (F->eval(Approx[n - i - 2]) < current) return false;
	}

	return true;
}

#include "condition_f_difference.h"

bool ConditionFDiff::Stop(const Function * F, const vPointSeq & Approx) const
{
	int n = Approx.size();
	if (n > 1) {
		if (abs(F->eval(Approx[n - 1]) - F->eval(Approx[n - 2])) < GetEps()) return true;
	}
	return false;
}

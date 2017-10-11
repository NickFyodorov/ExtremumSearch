#include "condition_x_difference.h"
#include "norm.h"

bool ConditionXDiff::Stop(const Function * F, const vPointSeq & Approx) const
{
	int n = Approx.size();
	if (n > 1) {
		vPoint tmp = Approx[n - 1] - Approx[n - 2];
		if(norm(tmp) < GetEps()) return true;
	}
	return false;
}

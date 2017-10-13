#include "condition_x_difference.h"


bool ConditionXDiff::Stop(const Function * F, const std::vector<vPoint> & Approx) const
{
	int n = Approx.size();
	if (n > 1) {
		vPoint tmp(Approx[n - 1]);
		tmp -= Approx[n - 2];
		if(norm(tmp) < GetEps()) return true;
	}
	return false;
}

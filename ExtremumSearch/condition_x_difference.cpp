#include "condition_x_difference.h"


bool ConditionXDiff::Stop(std::shared_ptr<Function> F, const std::vector<vPoint> & Approx, const std::vector<double> Evals) const
{
	int n = Approx.size();
	if (n > 1 && norm(Evals[n - 1] - Evals[n - 2]) < GetEps()) return true;
	return false;
}

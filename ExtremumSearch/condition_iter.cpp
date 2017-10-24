#include "condition_iter.h"

bool ConditionIter::Stop(std::shared_ptr<Function> F, const std::vector<vPoint> & Approx, const std::vector<double> Evals) const
{
	return Approx.size() > GetMaxCount();
}

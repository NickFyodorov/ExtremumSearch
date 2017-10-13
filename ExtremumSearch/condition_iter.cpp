#include "condition_iter.h"

bool ConditionIter::Stop(const Function * F, const std::vector<vPoint> & Approx) const
{
	if (Approx.size() >= GetMaxCount()) return true;
	return false;
}

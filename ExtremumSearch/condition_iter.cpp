#include "condition_iter.h"

bool ConditionIter::Stop(const Function * F, const vPointSeq & Approx) const
{
	if (Approx.size() >= GetMaxCount()) return true;
	return false;
}

#include "condition_iter.h"

bool ConditionIter::Stop(const Function * F, const std::vector<vPoint> & Approx) const
{
	//std::cout << "In Iter: " << Approx.size() << std::endl;
	return Approx.size() > GetMaxCount();
}

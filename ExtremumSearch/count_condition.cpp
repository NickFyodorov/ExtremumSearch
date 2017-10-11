#include "count_condition.h"

CountCondition::CountCondition(int _mcount)
{
	if (!SetMaxCount(_mcount)) {
		//exception
	}
}

bool CountCondition::SetMaxCount(int _mcount)
{
	if(_mcount <= 0) return false;
	max_count = _mcount;
	return true;
}

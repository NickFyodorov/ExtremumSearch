#pragma once

#include "terminal_condition.h"

class CountCondition : TerminalCondition {
private:
	int max_count;
public:
	CountCondition(int _mcount);
	virtual ~CountCondition() {}
	bool SetMaxCount(int _mcount);
	int GetMaxCount() const { return max_count; }
};

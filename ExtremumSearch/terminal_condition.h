#pragma once

#include <vector>
#include <memory>

#include "function.h"
#include "area.h"
#include "vpoint.h"

const int CRIT_ITER = 1000000000;

class TerminalCondition {
	int crititer;
public:
	TerminalCondition(int _crititer = CRIT_ITER) { crititer = (_crititer > 0) ? _crititer : CRIT_ITER; }
	int GetCritIter() const { return crititer; }
	virtual bool Stop(std::shared_ptr<Function> F, const std::vector<vPoint>& Approx, const std::vector<double>& Evals) const { return Evals.size() > GetCritIter(); };
	virtual void Info() const = 0;
	friend std::ostream& operator<<(std::ostream& out, std::shared_ptr<TerminalCondition> T) {
		T->Info();
		return out;
	}
};
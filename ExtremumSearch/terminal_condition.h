#pragma once

#include <vector>
#include <memory>

#include "function.h"
#include "area.h"
#include "vpoint.h"

class TerminalCondition {
public:
    virtual bool Stop(std::shared_ptr<Function> F, const std::vector<vPoint>& Approx, const std::vector<double>& Evals) const = 0;
	virtual void Info() const = 0;
	friend std::ostream& operator<<(std::ostream& out, std::shared_ptr<TerminalCondition> T) {
		T->Info();
		return out;
	}
};
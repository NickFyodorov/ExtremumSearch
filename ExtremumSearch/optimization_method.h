#pragma once

#include <vector>

#include "custom_defines.h"
#include "area.h"
#include "function.h"
#include "terminal_condition.h"

class OptimizationMethod {
private:
public:
	OptimizationMethod() {}
	virtual ~OptimizationMethod() {}
	virtual vPointSeq Optimize(const Area * A, const Function * F, const TerminalCondition * T, const vPoint& FirstPoint) = 0;
    virtual char* Name() const = 0;
};
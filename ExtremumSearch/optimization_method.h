#pragma once

#include <vector>

#include "area.h"
#include "function.h"
#include "terminal_condition.h"

class OptimizationMethod {
private:
public:
    OptimizationMethod();
    virtual ~OptimizationMethod();
	virtual std::vector<Point> Optimize(const Area& A, const Function& F, const TerminalCondition& T, const Point& FirstPoint) = 0;
	virtual std::vector<Point> Optimize(const Area& A, const Function& F, const Function& G, const TerminalCondition& T, const Point& FirstPoint) = 0;
    virtual char* Name() const = 0;
};
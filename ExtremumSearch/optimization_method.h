#pragma once

#include <vector>
#include <string>

#include "vpoint.h"
#include "area.h"
#include "function.h"
#include "terminal_condition.h"

struct OptResult {
	std::shared_ptr<Function> Fun;
	std::shared_ptr<Area> OptArea;
	std::vector<vPoint> Approximations;
	std::vector<double> Evaluations;
	vPoint Result;
	double ResFuncValue;
	int Iterations;
};

class OptimizationMethod {
private:
public:
	OptimizationMethod() {}
	virtual ~OptimizationMethod() {}
	virtual OptResult Optimize(std::shared_ptr<Area> A, std::shared_ptr<Function> F, std::shared_ptr<TerminalCondition> T, const vPoint& FirstPoint) = 0;
    virtual char* Name() const = 0;
	virtual void Info() const = 0;
	friend std::ostream& operator<<(std::ostream& out, std::shared_ptr<OptimizationMethod> optMethod) {
		optMethod->Info();
		return out;
	}
};
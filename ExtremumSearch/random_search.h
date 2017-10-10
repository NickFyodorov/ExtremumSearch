#pragma once

#include <random>

#include "optimization_method.h"

class RandomSearch : public OptimizationMethod {
private:
	double p;
	double gamma;
public:
	RandomSearch(double _p, double _gamma) : p(_p), gamma(_gamma), OptimizationMethod() {}
	virtual vPointSeq& Optimize(const Area * A, const Function * F, const TerminalCondition * T, const vPoint& FirstPoint);
	virtual char* Name() const { return "Random Search"; }
};
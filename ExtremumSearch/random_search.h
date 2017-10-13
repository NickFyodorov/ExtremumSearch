#pragma once

#include <random>

#include "optimization_method.h"

class RandomSearch : public OptimizationMethod {
private:
	double p;
	double gamma;
public:
	RandomSearch(double _p = 0.5, double _gamma = 0.5) : p(_p), gamma(_gamma), OptimizationMethod() {}
	double GetP() const { return p; }
	double GetGamma() const { return gamma; }
	bool SetP(double _p);
	bool SetGamma(double _gamma);
	virtual std::vector<vPoint>& Optimize(const Area * A, const Function * F, const TerminalCondition * T, const vPoint& FirstPoint);
	virtual char* Name() const { return "Random Search"; }
};
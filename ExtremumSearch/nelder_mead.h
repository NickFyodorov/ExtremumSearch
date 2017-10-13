#pragma once

#include "optimization_method.h"
#include "Simplex.h"

class NelderMead : public OptimizationMethod {
private:
    double reflection;
    double expansion;
    double contraction;
    double shrink;
public:
	NelderMead(double _reflection = 1.0, double _expansion = 2.0, double _contraction = 0.5, double _shrink = 0.5);
	virtual ~NelderMead() {}
    virtual std::vector<vPoint>& Optimize(const Area * A, const Function * F, const TerminalCondition * T, const vPoint& FirstPoint);
	virtual char* Name() const { return "Nelder-Mead"; }
	bool SetReflection(double _reflection);
	bool SetExpansion(double _expansion);
	bool SetContraction(double _contraction);
	bool SetShrink(double _shrink);
	double GetReflection() const { return reflection; }
	double GetExpansion() const { return expansion; }
	double GetContraction() const { return contraction; }
	double GetShrink() const { return shrink; }
};
#pragma once

#include "optimization_method.h"

class NelderMead : public OptimizationMethod {
private:
    double reflection;
    double expansion;
    double contraction;
    double shrink;
    vPointSeq simplex;
public:
    NelderMead(double _reflection, double _expansion, double _contraction, double _shrink, const vPointSeq& _simplex) : OptimizationMethod() {}
	virtual ~NelderMead() {}
    virtual vPointSeq& Optimize(const Area * A, const Function * F, const TerminalCondition * T, const vPoint& FirstPoint);
	virtual char* Name() const { return "Nelder-Mead"; }
	bool SetSimplex(const vPointSeq& _simplex) { simplex = _simplex; }
	bool SetReflection(double _reflection) { reflection = _reflection; }
	bool SetExpansion(double _expansion) { expansion = _expansion; }
	bool SetContraction(double _contraction) { contraction = _contraction; }
	bool SetShrink(double _shrink) { shrink = _shrink; }
	double GetReflection() { return reflection; }
	double GetExpansion() { return expansion; }
	double GetContraction() { return contraction; }
	double GetShrink() { return shrink; }
};
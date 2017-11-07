#pragma once

#include "optimization_method.h"
#include "Simplex.h"


/*!
\section DESCRIPTION

The NelderMead class is derived from OptimizationMethod and represents an instance of Nelder-Mead optimization algorithm with algorithm parameters
*/
class NelderMead : public OptimizationMethod {
private:
    double reflection;///< the reflection parameter of the method (0 < R)
    double expansion;///< the expansion parameter of the method (1 < E)
    double contraction;///< the contraction parameter of the method (0 <= C <= 0.5)
    double shrink;///< the shrink parameter of the method (0 < S < 1)
public:
	/*!
	constructor that sets the parameters of the method to the given values or to default values if no value is provided
	*/
	NelderMead(double _reflection = 1.0, double _expansion = 2.0, double _contraction = 0.5, double _shrink = 0.5);
	virtual ~NelderMead() {}///< destructor
	/*!
	inherited from OptimizationMethod
	optimizes the function in given area using the Nelder-Mead algorithm
	*/
	virtual OptResult Optimize(std::shared_ptr<Area> A, std::shared_ptr<Function> F, std::shared_ptr<TerminalCondition> T, const vPoint& FirstPoint);
	virtual char* Name() const { return "Nelder-Mead"; }///< returns the name of the method
	bool SetReflection(double _reflection);///< sets the reflection parameter of the method with argument validation
	bool SetExpansion(double _expansion);///< sets the expansion parameter of the method with argument validation
	bool SetContraction(double _contraction);///< sets the contraction parameter of the method with argument validation
	bool SetShrink(double _shrink);///< sets the shrink parameter of the method with argument validation
	double GetReflection() const { return reflection; }///< returns the reflection parameter of the method
	double GetExpansion() const { return expansion; }///< returns the expansion parameter of the method
	double GetContraction() const { return contraction; }///< returns the contraction parameter of the method
	double GetShrink() const { return shrink; }///< returns the shrink parameter of the method
	virtual void Info() const;///< writes the information about the method and its arguments to std::cout
};
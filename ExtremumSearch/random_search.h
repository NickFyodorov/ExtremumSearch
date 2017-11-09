#pragma once

#include <random>

#include "optimization_method.h"

/*!
\section DESCRIPTION

The NelderMead class is derived from OptimizationMethod and represents an instance of Nelder-Mead optimization algorithm with algorithm parameters
*/

class RandomSearch : public OptimizationMethod
{
  private:
	double p;	 ///< the bernoulli distribution parameter of the method (0 < p < 1)
	double gamma; ///< the shrinking parameter of the method (0 < gamma < 1)
  public:
	/*!
	constructor that sets the parameters of the method to the given values or to default values if no value is provided
	*/
	RandomSearch(double _p = 0.5, double _gamma = 0.5) : p(_p), gamma(_gamma), OptimizationMethod() {}
	double GetP() const { return p; }		  /// returns the bernoulli distribution parameter of the method
	double GetGamma() const { return gamma; } ///< returns the shrinking parameter of the method
	bool SetP(double _p);					  ///< sets the bernoulli distribution parameter of the method with argument validation
	bool SetGamma(double _gamma);			  ///< sets the shrinking parameter of the method with argument validation
	/*!
	inherited from OptimizationMethod
	optimizes the function in given area using the modified Random Search algorithm
	*/
	virtual OptResult Optimize(std::shared_ptr<Area> A, std::shared_ptr<Function> F, std::shared_ptr<TerminalCondition> T, const vPoint &FirstPoint);
	virtual char *Name() const { return "Random Search"; } ///< returns the name of the method
	virtual void Info() const;							   ///< writes the information about the method and its arguments to std::cout
};
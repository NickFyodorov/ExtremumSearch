#pragma once

#include <memory>

#include "function.h"
#include "area.h"

/*!
\section DESCRIPTION

The SmoothFunction class is derived from Function and represents a smooth function with known gradient formula
*/
class SmoothFunction : public Function
{
	std::shared_ptr<Function> grad; ///< pointer to the gradient function
  public:
	/*!
	sets the domain and gradient function values of the smooth function
	*/
	SmoothFunction(
		std::shared_ptr<Area> _domain, 
		std::shared_ptr<Function> _grad = 0) : grad(_grad), Function(_domain) {}
	double evalGrad(const vPoint &X) const { return grad->eval(X); } ///< returns the evaluation of the gradient function at given point
	std::shared_ptr<Function> GetGrad() const { return grad; }		 ///< returns a pointer to the gradient function
};
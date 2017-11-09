#pragma once

#include "function.h"
#include "smooth_function.h"
#include "area.h"

/*!
\section DESCRIPTION
TestFunc03 is derived from Function and represents the third test function from Khimmelblau 'Nonlinear Programming' for optimization algorithms testing
*/
class TestFunc03 : public Function
{
  public:
	TestFunc03(std::shared_ptr<Area> _domain) : Function(_domain) {}
	virtual ~TestFunc03() { domain = 0; }
	virtual double eval(const vPoint &X) const;
	virtual void Info() const;
};

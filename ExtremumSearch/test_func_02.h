#pragma once

#include "function.h"
#include "smooth_function.h"
#include "area.h"

/*!
\section DESCRIPTION
TestFunc02 is derived from Function and represents the second test function from Khimmelblau 'Nonlinear Programming' for optimization algorithms testing
*/
class TestFunc02 : public Function
{
  public:
	TestFunc02(std::shared_ptr<Area> _domain) : Function(_domain) {}
	virtual ~TestFunc02() { domain = 0; }
	virtual double eval(const vPoint &X) const;
	virtual void Info() const;
};

#pragma once

#include "function.h"
#include "smooth_function.h"
#include "area.h"

/*!
\section DESCRIPTION
TestFunc04 is derived from Function and represents the fourth test function from Khimmelblau 'Nonlinear Programming' for optimization algorithms testing
*/
class TestFunc04 : public Function
{
public:
	TestFunc04(std::shared_ptr<Area> _domain) : Function(_domain) {}
	virtual ~TestFunc04() { domain = 0; }
	virtual double eval(const vPoint &X) const;
	virtual void Info() const;
};

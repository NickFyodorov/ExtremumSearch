#pragma once



#include "function.h"
#include "smooth_function.h"
#include "area.h"

/*!
\section DESCRIPTION
TestFunc05 is derived from Function and represents the fifth test function from Khimmelblau 'Nonlinear Programming' for optimization algorithms testing
*/
class TestFunc05 : public Function {
public:
	TestFunc05(std::shared_ptr<Area> _domain) : Function(_domain) {}
	virtual ~TestFunc05() { domain = 0; }
	virtual double eval(const vPoint& X) const;
	virtual void Info() const;
};

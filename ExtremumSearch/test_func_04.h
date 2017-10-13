#pragma once



#include "function.h"
#include "smooth_function.h"
#include "area.h"

class TestFunc04 : public Function {
public:
	TestFunc04(Area * _domain) : Function(_domain) {}
	virtual ~TestFunc04() { domain = 0; }
	virtual double eval(const vPoint& X) const;
};

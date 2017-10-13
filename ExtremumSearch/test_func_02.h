#pragma once



#include "function.h"
#include "smooth_function.h"
#include "area.h"

class TestFunc02 : public Function {
public:
	TestFunc02(Area * _domain) : Function(_domain) {}
	virtual ~TestFunc02() { domain = 0; }
	virtual double eval(const vPoint& X) const;
};

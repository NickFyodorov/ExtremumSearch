#pragma once



#include "function.h"
#include "smooth_function.h"
#include "area.h"

class TestFunc01 : public Function {
public:
	TestFunc01(Area * _domain) : Function(_domain) {}
	virtual ~TestFunc01() { domain = 0; }
	virtual double eval(const vPoint& X) const;
};

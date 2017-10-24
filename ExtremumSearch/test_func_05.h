#pragma once



#include "function.h"
#include "smooth_function.h"
#include "area.h"

class TestFunc05 : public Function {
public:
	TestFunc05(std::shared_ptr<Area> _domain) : Function(_domain) {}
	virtual ~TestFunc05() { domain = 0; }
	virtual double eval(const vPoint& X) const;
};

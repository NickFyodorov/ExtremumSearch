#pragma once



#include "function.h"
#include "smooth_function.h"
#include "area.h"

class TestFunc03 : public Function {
public:
	TestFunc03(std::shared_ptr<Area> _domain) : Function(_domain) {}
	virtual ~TestFunc03() { domain = 0; }
	virtual double eval(const vPoint& X) const;
};

#pragma once



#include "function.h"
#include "smooth_function.h"
#include "area.h"

class TestFunc04 : public Function {
public:
	TestFunc04(std::shared_ptr<Area> _domain) : Function(_domain) {}
	virtual ~TestFunc04() { domain = 0; }
	virtual double eval(const vPoint& X) const;
	virtual void Info() const;
};

#pragma once


#include "vpoint.h"
#include "area.h"

class Function {
protected:
	Area * domain;
public:
    Function(Area * _domain) : domain(_domain) {}
	virtual ~Function() { domain = 0; }
    virtual double eval(const vPoint& X) const = 0;
    int GetDim() const {
        return domain->GetDim();
    }
	friend double CalcGrad(const Function * F, const vPoint& X, double delta);
	friend double CalcHessian(const Function * F, const vPoint& X, double delta);
};
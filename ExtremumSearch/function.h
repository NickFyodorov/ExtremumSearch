#pragma once

#include <memory>
#include <string>

#include "vpoint.h"
#include "area.h"

class Function {
protected:
	std::shared_ptr<Area> domain;
public:
    Function(std::shared_ptr<Area> _domain) : domain(_domain) {}
	virtual ~Function() { }
    virtual double eval(const vPoint& X) const = 0;
    int GetDim() const {
        return domain->GetDim();
    }
	double operator()(const vPoint& X) const { return eval(X); }
	virtual void Info() const = 0;
	friend std::ostream& operator<<(std::ostream& out, std::shared_ptr<Function> F) {
		F->Info();
		return out;
	}
	friend double CalcGrad(std::shared_ptr<Function> F, const vPoint& X, double delta);
};
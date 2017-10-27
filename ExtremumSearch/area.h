#pragma once

#include <random>
#include <memory>

#include "vpoint.h"
#include "random_seed.h"

class Area {
protected:
    int dim;
public:
	Area(int _dim) : dim(_dim) {}
	virtual ~Area() {}
    virtual bool In(const vPoint& X) const = 0;
	virtual vPoint RandomPoint() const = 0;
	virtual std::shared_ptr<Area> SubArea(const vPoint& X, double epsilon) const = 0;
	int GetDim() const { return dim; }
	virtual void Info() const = 0;
	friend std::ostream& operator<<(std::ostream& out, std::shared_ptr<Area> A) {
		A->Info();
		return out;
	}
};
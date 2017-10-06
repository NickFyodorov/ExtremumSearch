#pragma once

#include <armadillo>

#include "custom_defines.h"

class Area {
private:
    int dim;
public:
	Area(int _dim) : dim(_dim) {}
	virtual ~Area() {}
    virtual bool In(const vPoint& X) const = 0;
	int GetDim() const { return dim; }
};
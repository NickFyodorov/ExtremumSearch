#pragma once

#include "custom_defines.h"
#include "area.h"


const int RANGE_DIM = 1;

class Range : Area {
private:
	double min, max;
public:
	Range(double _min = -1.0, double _max = 1.0) : Area(RANGE_DIM), min(_min), max(_max) {}
	virtual ~Range() {}
	virtual bool In(const vPoint& X) const { return X.size == RANGE_DIM && X[0] > min && X[0] < max; }
	double GetMax() const { return max; }
	double GetMin() const { return min; }
};
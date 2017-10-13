#pragma once

#include <random>


#include "area.h"


const int RANGE_DIM = 1;

class Range : public Area {
private:
	double min, max;
public:
	Range(double _min = -1.0, double _max = 1.0) : Area(RANGE_DIM), min(_min), max(_max) {}
	virtual ~Range() {}
	virtual bool In(const vPoint& X) const { return X.GetDim() == RANGE_DIM && X[0] > min && X[0] < max; }
	virtual vPoint& RandomPoint() const;
	virtual Area* SubArea(const vPoint& X, double epsilon) const;
	double GetMax() const { return max; }
	double GetMin() const { return min; }
};
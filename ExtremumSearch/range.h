#pragma once

#include <random>
#include <memory>

#include "area.h"


const int RANGE_DIM = 1;

class Range : public Area {
private:
	double min, max;
public:
	Range(double _min = -1.0, double _max = 1.0) : Area(RANGE_DIM), min(_min), max(_max) {}
	virtual ~Range() {}
	virtual bool In(const vPoint& X) const { return X.GetDim() == RANGE_DIM && In(X[0]); }
	bool In(double X) const { return X > min && X < max; }
	virtual vPoint RandomPoint() const;
	virtual std::shared_ptr<Area> SubArea(const vPoint& X, double epsilon) const;
	double GetMax() const { return max; }
	double GetMin() const { return min; }
	virtual void Info() const;
	friend std::ostream& operator<<(std::ostream& out, std::shared_ptr<Range> R) {
		R->Info();
		return out;
	}
};
#pragma once


#include <vector>

#include "area.h"
#include "range.h"

typedef std::vector<Range> RangeVec;

class NCube : public Area {
private:
	RangeVec ranges;
public:
	NCube(const RangeVec& _ranges, int _dim = 2) : Area(_dim), ranges(_ranges) {}
	NCube(int _dim = 2);
	virtual ~NCube() {}
	virtual bool In(const vPoint& X) const;
	virtual vPoint& RandomPoint() const;
	virtual Area* SubArea(const vPoint& X, double epsilon) const;
	const Range& operator[](int index) const { return ranges[index]; }
	Range& operator[](int index) { return ranges[index]; }
};

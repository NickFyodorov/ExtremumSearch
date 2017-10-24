#pragma once


#include <vector>

#include "area.h"
#include "range.h"

typedef std::vector<std::shared_ptr<Range>> RangeVec;

class NCube : public Area {
private:
	RangeVec ranges;
public:
	NCube(const RangeVec& _ranges) : Area(_ranges.size()), ranges(_ranges) {}
	NCube(int _dim = 2);
	NCube(std::vector<double> & minimums, std::vector<double> & maximums);
	virtual ~NCube() {}
	virtual bool In(const vPoint& X) const;
	virtual vPoint RandomPoint() const;
	virtual std::shared_ptr<Area> SubArea(const vPoint& X, double epsilon) const;
	const Range& operator[](int index) const { return *ranges[index]; }
	Range& operator[](int index) { return *ranges[index]; }
	const Range& at(int index) const { if (index < 0 || index > ranges.size()) {/*exception*/ } else return *ranges[index]; }
	Range& at(int index) { if (index < 0 || index > ranges.size()) {/*exception*/ } else return *ranges[index]; }
};

#pragma once


#include <vector>

#include "area.h"
#include "range.h"

typedef std::vector<std::shared_ptr<Range>> RangeVec;///< short version of std::vector of ranges for the cube


/*!
\section DESCRIPTION

The NCube class is derived from Area and represents a multidimensional cube that consists of onedimensional ranges
*/
class NCube : public Area {
private:
	RangeVec ranges;///< the std::vector of ranges of the cube
public:
	/*!
	constructor that sets the ranges of the cube
	*/
	NCube(const RangeVec& _ranges) : Area(_ranges.size()), ranges(_ranges) {}
	/*!
	constructor that sets the dimension of the cube and fills it with standard ranges
	*/
	NCube(int _dim = 2);
	/*!
	constructor that sets the ranges of the cube to ranges with given left and right bounds
	\param minimums std::vector of left bounds of the ranges
	\param maximums std::vector of right bounds of the ranges
	*/
	NCube(std::vector<double> & minimums, std::vector<double> & maximums);
	virtual ~NCube() {}///< destructor
	/*!
	inhereted from Area
	\param X vector point
	\return true if coordinates of X are in within the ranges of the cube and false otherwise
	*/
	virtual bool In(const vPoint& X) const;
	/*!
	inherited from Area
	\return a random vector point that is uniformly distributed in the cube
	*/
	virtual vPoint RandomPoint() const;
	/*!
	inherited from Area
	\return intersection of epsilon cube around vector point X and this cube
	*/
	virtual std::shared_ptr<Area> SubArea(const vPoint& X, double epsilon) const;
	const Range& operator[](int index) const { return *(ranges[index]); }///< returns the range of the cube at given index
	Range& operator[](int index) { return *(ranges[index]); }///< returns the range of the cube at given index
	const Range& at(int index) const { if (index < 0 || index > ranges.size()) { throw std::out_of_range("Index out of range"); } return *(ranges[index]); }///< returns the range of the cube at given index but validates whether the index is in index range
	Range& at(int index) { if (index < 0 || index > ranges.size()) { throw std::out_of_range("Index out of range"); } return *(ranges[index]); }///< returns the range of the cube at given index but validates whether the index is in index range
	virtual void Info() const;///< writes the information about the cube and its ranges to std::cout
};

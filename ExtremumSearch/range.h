#pragma once

#include <random>
#include <memory>

#include "area.h"

const int RANGE_DIM = 1; ///< constant value that represents the dimension of the range

/*!
\section DESCRIPTION

The Range class is derived from Area and represents a onedimensional range of real numbers (a, b)
*/

class Range : public Area
{
  private:
	double min; ///< left bound of the range
	double max; ///< right bound of the range
  public:
	/*!
	constructor that sets the bounds of the range
	*/
	Range(double _min = -1.0, double _max = 1.0) : Area(RANGE_DIM), min(_min), max(_max) {}
	virtual ~Range() {} ///< destructor
	/*!
	inhereted from Area
	\param X vector point
	\return true if X is onedimensional and its coordinate is in the range and false otherwise
	*/
	virtual bool In(const vPoint &X) const { return X.GetDim() == RANGE_DIM && In(X[0]); }
	/*!
	inhereted from Area
	\param X vector point
	\return true if X is onedimensional and its coordinate is in the range and false otherwise
	*/
	bool In(double X) const { return X > min && X < max; } ///< checks whether a double number is within the range
	/*!
	inhereted from Area
	\return a random onedimensioal vector point uniformly distributed in the range
	*/
	virtual vPoint RandomPoint() const;
	/*!
	inhereted from Area
	\return the intersection between the epsilon range of vector point X and the range
	*/
	virtual std::shared_ptr<Area> SubArea(const vPoint &X, double epsilon) const;
	double GetMax() const { return max; } ///< return the right bound of the range
	double GetMin() const { return min; } ///< return the left bound of the range
	/*!
	inherited from Area
	prints the range bounds to std::cout
	*/
	virtual void Info() const;
	/*!
	prints the range bounds to std::cout
	*/
	friend std::ostream &operator<<(std::ostream &out, std::shared_ptr<Range> R)
	{
		R->Info();
		return out;
	}
};
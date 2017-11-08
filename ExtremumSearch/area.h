#pragma once

#include <random>
#include <memory>

#include "vpoint.h"
#include "random_seed.h"

/*!
\section DESCRIPTION

The Area class represents a multidimensional subset of real vector points
*/

class Area {
protected:
	int dim;///<the dimension of the area
public:
	/*!
	constructor that sets the dimension of the area
	\param _dim the area dimension
	*/
	Area(int _dim) : dim(_dim) {}
	/*!
	destructor of the class
	*/
	virtual ~Area() {}
	/*!
	abstract method that indicates whether vector point is in the area
	\param X vector point
	\return true if the point is in the area and false otherwise
	*/
	virtual bool In(const vPoint& X) const = 0;
	/*!
	abstract method that returns a uniformly distributed random point from the area
	*/
	virtual vPoint RandomPoint() const = 0;
	/*!
	abstract method that returns a pointer to a neighbourhood of a point within the area
	\param X vector point for which the neighbourhood is provided
	\param epsilon positive real number that indicates the size of the neighbourhood
	\return shared pointer to the neighbourhood of the point
	*/
	virtual std::shared_ptr<Area> SubArea(const vPoint& X, double epsilon) const = 0;
	/*!
	returns the area dimension
	\return the dimension of the area
	*/
	int GetDim() const { return dim; }///<returns the dimension of the area
	/*!
	writes information about the area to std::cout
	*/
	virtual void Info() const = 0;
	/*!
	overloaded output to std::cout
	*/
	friend std::ostream& operator<<(std::ostream& out, std::shared_ptr<Area> A) {
		A->Info();
		return out;
	}
};
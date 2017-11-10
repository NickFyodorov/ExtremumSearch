#pragma once

#include <vector>
#include <iostream>

/*!
\section DESCRIPTION

The vPoint class represents a vector point with real number coordinates
*/
class vPoint
{
  protected:
	int dim;						 ///< the dimension of the point (the number of point coordinates)
	std::vector<double> coordinates; ///< std::vector of coordinates of the point
  public:
	/*!
	constructor that sets the coordinates and dimension of the point based on the std::vector of coordinates
	\param _coords the coordinates of the vector
	*/
	vPoint(std::vector<double> _coords);
	/*!
	constructor that sets the dimension of the vector point and fills it with zeroes
	\param _dim the dimension of the point
	*/
	vPoint(int _dim = 2);
	vPoint(const vPoint &other);									  ///< copy constructor
	vPoint(vPoint &&other);											  ///< move constructor
	virtual ~vPoint() {}											  ///< destructor
	int GetDim() const { return dim; }								  ///< returns the dimeision of the vector point
	double &operator[](int index) { return coordinates[index]; }	  ///< returns the coordinate of the vector point at given index
	double operator[](int index) const { return coordinates[index]; } ///< returns the coordinate of the vector point at given index
	vPoint &operator=(const vPoint &other);							  ///< copy operator
	vPoint &operator=(const vPoint &&other);						  ///< move operator
	/*!
	adds the coordinates of another vector point to this vector point
	\param other vector point which is added to this vector point
	\return the resulting vector point
	*/
	vPoint &operator+=(const vPoint &other);
	/*!
	subtracts the coordinates of another vector point to this vector point
	\param other vector point which is subtracted this vector point
	\return the resulting vector point
	*/
	vPoint &operator-=(const vPoint &other);
	friend vPoint &operator+(const vPoint &left, const vPoint &right); ///< returns the sum of two vector points
	friend vPoint &operator-(const vPoint &left, const vPoint &right); ///< subtracts one vector point from another and returns the result
	/*!
	offsets the coordinates of the point via addition of a real number to each coordinate
	\param point the vector point that is being offset
	\param offset the double number that represents the offset value
	\return vector point with offset coordinates
	*/
	friend vPoint &operator+(const vPoint &point, double offset);
	/*!
	offsets the coordinates of the point via subtraction of a real number to each coordinate
	\param point the vector point that is being offset
	\param offset the double number that represents the offset value
	\return vector point with offset coordinates
	*/
	friend vPoint &operator-(const vPoint &point, double offset);
	vPoint &operator+=(double offset); ///< offsetsthe vector point by addition of the offset value to each coordinate
	vPoint &operator-=(double offset); ///< offsetsthe vector point by subtraction of the offset value from each coordinate
	/*!
	\param point vector point coordinates of which are multiplied
	\param scalar a double by which the coordinates of the vector point are multiplied
	\result vector point with multiplied coordinates
	*/
	friend vPoint &operator*(const vPoint &point, double scalar);
	vPoint &operator*=(double scalar); ///< multiplies each coordinate of the point by the scalar value
	/*!
	\param point vector point coordinates of which are divided
	\param scalar a double by which the coordinates of the vector point are divided
	\result vector point with divided coordinates
	*/
	friend vPoint &operator/(const vPoint &point, double scalar);
	vPoint &operator/=(double scalar);										 ///< divides each coordinate of the point by the scalar value
	friend std::ostream &operator<<(std::ostream &out, const vPoint &Point); ///< writes the information about the vector point to an std::ostream object
	friend double norm(const vPoint &Point);								 ///<calculates the standard norm of the point
};

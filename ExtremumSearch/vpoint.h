#pragma once

#include <vector>
#include <iostream>

class vPoint {
protected:
	int dim;
	std::vector<double> coordinates;
public:
	vPoint(std::vector<double> _coords);
	vPoint(int _dim = 2);
	vPoint(const vPoint& other);
	virtual ~vPoint() {}
	int GetDim() const { return dim; }
	double& operator[](int index) { return coordinates[index]; }
	double operator[](int index) const { return coordinates[index]; }
	vPoint& operator+=(const vPoint& other);
	vPoint& operator-=(const vPoint& other);
	vPoint& operator+(const vPoint& other);
	vPoint& operator-(const vPoint& other);
	vPoint& operator+(double offset);
	vPoint& operator-(double offset);
	vPoint& operator+=(double offset);
	vPoint& operator-=(double offset);
	vPoint& operator*(double scalar);
	vPoint& operator*=(double scalar);
	vPoint& operator/(double scalar);
	vPoint& operator/=(double scalar);
	friend std::ostream& operator<<(std::ostream& out, const vPoint& Point);
	friend double norm(const vPoint& Point);
};

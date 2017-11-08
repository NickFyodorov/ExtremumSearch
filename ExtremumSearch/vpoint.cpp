#include "vpoint.h"

vPoint::vPoint(std::vector<double> _coords)
{
	coordinates = _coords;
	dim = _coords.size();
}

vPoint::vPoint(int _dim)
{
	if (_dim <= 0) {
		throw std::invalid_argument("Point dimension must be a positive integer");
	}

	dim = _dim;
	for (int i = 0; i < dim; ++i) coordinates.push_back(0);
}

vPoint::vPoint(const vPoint & other) : dim(other.GetDim()), coordinates(other.coordinates)
{
}

vPoint::vPoint(vPoint && other)
{
	dim = other.dim;
	coordinates = std::move(other.coordinates);
}

vPoint & vPoint::operator=(const vPoint & other)
{
	dim = other.dim;
	coordinates = other.coordinates;
	return *this;
}

vPoint & vPoint::operator=(const vPoint && other)
{
	dim = other.dim;
	coordinates = std::move(other.coordinates);
	return *this;
}

vPoint & vPoint::operator+=(const vPoint & other)
{
	if (GetDim() != other.GetDim()) {
		throw std::invalid_argument("Point dimensions must be equal for the addition procedure");
	}

	for (int i = 0; i < GetDim(); ++i) {
		(*this)[i] += other[i];
	}
	return *this;
}

vPoint & vPoint::operator-=(const vPoint & other)
{
	if (GetDim() != other.GetDim()) {
		throw std::invalid_argument("Point dimensions must be equal for the subtraction procedure");
	}

	for (int i = 0; i < GetDim(); ++i) {
		(*this)[i] -= other[i];
	}
	return *this;
}

vPoint & vPoint::operator+=(double offset)
{
	for (int i = 0; i < GetDim(); ++i) (*this)[i] += offset;
	return *this;
}

vPoint & vPoint::operator-=(double offset)
{
	return operator+=(-offset);
}

vPoint & vPoint::operator*=(double scalar)
{
	for (int i = 0; i < GetDim(); ++i) {
		(*this)[i] *= scalar;
	}
	return *this;
}

vPoint & vPoint::operator/=(double scalar)
{
	for (int i = 0; i < GetDim(); ++i) {
		(*this)[i] /= scalar;
	}
	return *this;
}

vPoint & operator+(const vPoint & left, const vPoint & right)
{
	vPoint res(left);
	return res += right;
}

vPoint & operator-(const vPoint & left, const vPoint & right)
{
	vPoint res(left);
	return res -= right;
}

vPoint & operator+(const vPoint & point, double offset)
{
	vPoint res(point);
	return res += offset;
}

vPoint & operator-(const vPoint & point, double offset)
{
	vPoint res(point);
	return res -= offset;
}

vPoint & operator*(const vPoint & point, double scalar)
{
	vPoint res(point);
	return res *= scalar;
}

vPoint & operator/(const vPoint & point, double scalar)
{
	vPoint res(point);
	return res /= scalar;
}

std::ostream & operator<<(std::ostream & out, const vPoint & Point)
{
	out << "(" << Point[0];
	for (int i = 1; i < Point.GetDim(); ++i) {
		out << ", " << Point[i];
	}
	out << ")";
	return out;
}

double norm(const vPoint & Point)
{
	double ans = 0;
	for (int i = 0; i < Point.GetDim(); ++i) ans += Point[i] * Point[i];
	ans = sqrt(ans);
	return ans;
}

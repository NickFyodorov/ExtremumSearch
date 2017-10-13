#include "vpoint.h"

vPoint::vPoint(std::vector<double> _coords)
{
	coordinates = _coords;
	dim = _coords.size();
}

vPoint::vPoint(int _dim)
{
	if (_dim <= 0) {
		//exception
	}

	dim = _dim;
	for (int i = 0; i < dim; ++i) coordinates.push_back(0);
}

vPoint::vPoint(const vPoint & other) : dim(other.GetDim()), coordinates(other.coordinates)
{
}

vPoint & vPoint::operator+=(const vPoint & other)
{
	if (GetDim() != other.GetDim()) {
		//exception
	}

	for (int i = 0; i < GetDim(); ++i) {
		(*this)[i] += other[i];
	}
	return *this;
}

vPoint & vPoint::operator-=(const vPoint & other)
{
	if (GetDim() != other.GetDim()) {
		//exception
	}

	for (int i = 0; i < GetDim(); ++i) {
		(*this)[i] -= other[i];
	}
	return *this;
}

vPoint & vPoint::operator+(const vPoint & other)
{
	if (GetDim() != other.GetDim()) {
		//exception
	}

	vPoint Res(*this);

	return Res += other;
}

vPoint & vPoint::operator+(double offset)
{
	vPoint Res(*this);
	return Res += offset;
}

vPoint & vPoint::operator-(double offset)
{
	return operator+(-offset);
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

vPoint & vPoint::operator-(const vPoint & other)
{
	if (GetDim() != other.GetDim()) {
		//exception
	}

	vPoint Res(*this);
	return Res -= other;
}

vPoint & vPoint::operator*(double scalar)
{
	vPoint Res(*this);
	return Res*= scalar;
}

vPoint & vPoint::operator*=(double scalar)
{
	for (int i = 0; i < GetDim(); ++i) {
		(*this)[i] *= scalar;
	}
	return *this;
}

vPoint & vPoint::operator/(double scalar)
{
	vPoint Res(*this);
	return Res /= scalar;
}

vPoint & vPoint::operator/=(double scalar)
{
	for (int i = 0; i < GetDim(); ++i) {
		(*this)[i] /= scalar;
	}
	return *this;
}

std::ostream & operator<<(std::ostream & out, const vPoint & Point)
{
	out << "(";
	for (int i = 0; i < Point.GetDim(); ++i) {
		out << Point[i] << ", ";
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

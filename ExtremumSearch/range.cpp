#include <random>
#include <exception>

#include "range.h"

vPoint Range::RandomPoint() const
{
	std::uniform_real_distribution<double> urng(GetMin(), GetMax());

	vPoint X(1);
	X[0] = urng(rng);

	return X;
}

std::shared_ptr<Area> Range::SubArea(const vPoint & X, double epsilon) const
{
	if (!In(X))	throw new std::invalid_argument("Point is not inside the area.");

	double left = X[0] - epsilon > GetMin() ? X[0] - epsilon : GetMin();
	double right = X[0] + epsilon < GetMax() ? X[0] + epsilon : GetMax();
	return  std::shared_ptr<Area>(new Range(left, right));
}

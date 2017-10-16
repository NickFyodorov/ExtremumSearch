#include <random>

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
	if (!In(X)) {
		//exception
	}

	return  std::shared_ptr<Area>(new Range(X[0] - epsilon, X[0] + epsilon));
}

#include <exception>

#include "ncube.h"

NCube::NCube(int _dim) : Area(_dim)
{
	ranges.reserve(_dim);
}

NCube::NCube(std::vector<double> & minimums, std::vector<double> & maximums) : Area(minimums.size())
{
	if (minimums.size() != maximums.size()) throw std::invalid_argument("Numbers of minimums and maximums must be equal.");
	int n = minimums.size();

	for (int i = 0; i < n; ++i) ranges.push_back(std::make_shared<Range>(minimums[i], maximums[i]));
}

bool NCube::In(const vPoint & X) const
{
	bool ans = X.GetDim() == GetDim();

	for (int i = 0; i < X.GetDim() && ans; ++i) {
		ans = ranges[i]->In(X[i]);
	}
	return ans;
}

vPoint NCube::RandomPoint() const
{
	vPoint X(GetDim());

	for (int i = 0; i < GetDim(); ++i) {
		X[i] = ranges[i]->RandomPoint()[0];
	}
	return X;
}

std::shared_ptr<Area> NCube::SubArea(const vPoint & X, double epsilon) const
{
	if (!In(X)) throw std::invalid_argument("Point outside of area.");

	std::shared_ptr<Area> pCube = std::make_shared<NCube>(GetDim());
	std::shared_ptr<NCube> ptrCube = std::static_pointer_cast<NCube>(pCube);

	vPoint T(1);

	for (int i = 0; i < GetDim(); ++i) {
		T[0] = X[i];
		ptrCube->at(i) = *std::static_pointer_cast<Range>(this->at(i).SubArea(T, epsilon));
	}

	return pCube;

}

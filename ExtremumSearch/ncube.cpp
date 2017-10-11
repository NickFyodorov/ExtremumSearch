#include "ncube.h"

NCube::NCube(int _dim) : Area(_dim)
{
	ranges.reserve(_dim);
}

bool NCube::In(const vPoint & X) const
{
	bool ans = X.size() == GetDim();

	for (int i = 0; i < X.size() && ans; ++i) ans = ranges[i].In(X.subvec(i, i));

	return false;
}

vPoint & NCube::RandomPoint() const
{
	// TODO: insert return statement here
}

Area * NCube::SubArea(const vPoint & X, double epsilon) const
{
	return nullptr;
}

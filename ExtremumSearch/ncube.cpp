#include "ncube.h"

NCube::NCube(int _dim) : Area(_dim)
{
	ranges.reserve(_dim);
}

bool NCube::In(const vPoint & X) const
{
	bool ans = X.GetDim() == GetDim();

	vPoint T(1);
	for (int i = 0; i < X.GetDim() && ans; ++i) {
		T[0] = X[i];
		ans = ranges[i].In(T);
	}
	return ans;
}

vPoint & NCube::RandomPoint() const
{
	vPoint X(GetDim());

	for (int i = 0; i < GetDim(); ++i) {
		X[i] = (ranges[i]).RandomPoint()[0];
	}
	return X;
}

Area * NCube::SubArea(const vPoint & X, double epsilon) const
{
	if (!In(X)) {
		//exception
	}

	vPoint T(1);

	Area * pR = new NCube(GetDim());

	for (int i = 0; i < GetDim(); ++i) {
		T[0] = X[i];
		(*((NCube*)pR))[i] = *((Range*)(ranges[i].SubArea(T, epsilon)));
		delete pR;
	}

	return pR;
}

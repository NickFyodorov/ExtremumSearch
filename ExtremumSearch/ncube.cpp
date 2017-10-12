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
	vPoint X(GetDim());

	for (int i = 0; i < GetDim(); ++i) {
		X[i] = (ranges[i]).RandomPoint()[0];
	}
	return X;
}

Area * NCube::SubArea(const vPoint & X, double epsilon) const
{
	if (!In(X)) {
		//expection
	}

	vPoint T(1);

	NCube ncube(GetDim());
	Area * pR;

	for (int i = 0; i < GetDim(); ++i) {
		T[0] = X[i];
		pR = ranges[i].SubArea(T, epsilon);
		ncube[i] = *(dynamic_cast<Range*>(pR));
		delete pR;
	}

	return &ncube;
}

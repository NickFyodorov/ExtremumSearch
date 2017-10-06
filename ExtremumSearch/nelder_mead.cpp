
#include <algorithm>

#include "nelder_mead.h"

vPointSeq NelderMead::Optimize(const Area * A, const Function * F, const TerminalCondition * T, const vPoint & FirstPoint)
{
	vPointSeq Approximation;
	Approximation.push_back(FirstPoint);

	std::sort(simplex.begin(), simplex.end(),
		[&](const vPoint& X1, const vPoint& X2) {
			return F->eval(X1) < F->eval(X2);
		}
	);

	vPoint Centroid = simplex[1];

	for (int i = 2; i < simplex.size(); ++i) Centroid += simplex[i];

	Centroid /= (simplex.size() - 1);

	return vPointSeq();
}

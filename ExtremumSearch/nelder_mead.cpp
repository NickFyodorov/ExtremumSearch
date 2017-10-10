
#include <algorithm>

#include "nelder_mead.h"

vPointSeq& NelderMead::Optimize(const Area * A, const Function * F, const TerminalCondition * T, const vPoint & FirstPoint)
{
	if (A->GetDim() != F->GetDim()) {
		//exception
	}

	if (A->GetDim() != simplex.size() - 1) {
		//exception
	}

	for (int i = 0; i < simplex.size(); ++i) {
		if (!A->In(simplex[i])) {
			//exception
		}
	}

	vPointSeq Approximation;
	Approximation.push_back(FirstPoint);

	int n = A->GetDim();

	for (int i = 0; i <= n; ++i) Approximation.push_back(simplex[i]);

	do {
		//step 1 - Order
		std::sort(simplex.begin(), simplex.end(),
			[&](const vPoint& X1, const vPoint& X2) {
			return F->eval(X1) < F->eval(X2);
		}
		);

		Approximation.push_back(simplex[0]);

		//step 2 - Centroid
		vPoint Centroid(simplex[0]);
		for (int i = 1; i < n; ++i) Centroid += simplex[i];
		Centroid /= n;

		//step 3 - Reflection
		vPoint Reflected = Centroid + reflection * (Centroid - simplex[n]);

		if (F->eval(simplex[0]) <= F->eval(Reflected) && F->eval(Reflected) <= F->eval(simplex[n - 1])) {
			simplex[n] = Reflected;
			continue;
		}

		//step 4 - Expansion
		if (F->eval(Reflected) < F->eval(simplex[0])) {
			vPoint Expanded = Centroid + expansion * (Reflected - Centroid);
			simplex[n] = (F->eval(Expanded) < F->eval(Reflected)) ? Expanded : Reflected;
			continue;
		}

		//step 5 - Contraction
		vPoint Contracted = Centroid + contraction * (simplex[n] - Centroid);
		if (F->eval(Contracted) < F->eval(simplex[n])) {
			simplex[n] = Contracted;
			continue;
		}

		//step 6 - Shrink
		for (int i = 1; i <= n; ++i) simplex[i] = simplex[0] + shrink * (simplex[i] - simplex[0]);
	} while (!T->Stop(F, Approximation));

	return Approximation;
}

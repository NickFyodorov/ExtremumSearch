
#include <algorithm>

#include "nelder_mead.h"

NelderMead::NelderMead(double _reflection, double _expansion, double _contraction, double _shrink) : OptimizationMethod()
{
	if (!SetReflection(_reflection)) {
		//exception
	}

	if (!SetContraction(_contraction)) {
		//exception
	}

	if (!SetExpansion(_expansion)) {
		//exception
	}

	if (!SetShrink(_shrink)) {
		//exception
	}
}

std::vector<vPoint>& NelderMead::Optimize(const Area * A, const Function * F, const TerminalCondition * T, const vPoint & FirstPoint)
{
	if (A->GetDim() != F->GetDim()) {
		//exception
	}

	Simplex simplex(A->GetDim());
	simplex.MoveTo(FirstPoint);
	simplex.Squeeze(A);

	if (A->GetDim() != simplex.Size() - 1) {
		//exception
	}

	for (int i = 0; i < simplex.Size(); ++i) {
		if (!A->In(simplex[i])) {
			//exception
		}
	}

	std::vector<vPoint> Approximation;
	Approximation.push_back(FirstPoint);

	int n = A->GetDim();

	for (int i = 0; i <= n; ++i) Approximation.push_back(simplex[i]);

	do {
		//step 1 - Order
		std::sort(&(simplex[0]), &(simplex[n]),
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
		vPoint Reflected(Centroid);
		Reflected -= simplex[n];
		Reflected *= reflection;
		Reflected += Centroid;

		if (F->eval(simplex[0]) <= F->eval(Reflected) && F->eval(Reflected) <= F->eval(simplex[n - 1])) {
			simplex[n] = Reflected;
			continue;
		}

		//step 4 - Expansion
		if (F->eval(Reflected) < F->eval(simplex[0])) {
			vPoint Expanded(Reflected);
			Expanded -= Centroid;
			Expanded *= expansion;
			Expanded += Centroid;
			simplex[n] = (F->eval(Expanded) < F->eval(Reflected)) ? Expanded : Reflected;
			continue;
		}

		//step 5 - Contraction
		vPoint Contracted(simplex[n]);
		Contracted -= Centroid;
		Contracted *= contraction;
		Contracted += Centroid;
		if (F->eval(Contracted) < F->eval(simplex[n])) {
			simplex[n] = Contracted;
			continue;
		}

		//step 6 - Shrink
		for (int i = 1; i <= n; ++i) { 
			simplex[i] -= simplex[0];
			simplex[i] *= shrink;
			simplex[i] += simplex[0];
		}
	} while (!T->Stop(F, Approximation));

	return Approximation;
}

bool NelderMead::SetReflection(double _reflection)
{
	if (_reflection > 0) { 
		reflection = _reflection; 
		return true;
	}
	return false;
}

bool NelderMead::SetExpansion(double _expansion)
{
	if (_expansion > 1) {
		expansion = _expansion;
		return true;
	}
	return false;
}

bool NelderMead::SetContraction(double _contraction)
{
	if (0 < _contraction && _contraction <= 0.5) {
		contraction = _contraction;
		return true;
	}
	return false;
}

bool NelderMead::SetShrink(double _shrink)
{
	if (0 < _shrink && _shrink < 1) {
		shrink = _shrink;
		return true;
	}
	return false;
}

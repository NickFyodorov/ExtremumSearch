
#include <algorithm>
#include <functional>
#include <iostream>

#include "nelder_mead.h"

NelderMead::NelderMead(double _reflection, double _expansion, double _contraction, double _shrink) : OptimizationMethod()
{
	if (!SetReflection(_reflection)) {
		throw std::invalid_argument("Reflection parameter must be a positive number.");
	}

	if (!SetContraction(_contraction)) {
		throw std::invalid_argument("Contraction parameter must be a number between 0 and 0.5.");
	}

	if (!SetExpansion(_expansion)) {
		throw std::invalid_argument("Expansion parameter must be a number exceeding 1.");
	}

	if (!SetShrink(_shrink)) {
		throw std::invalid_argument("Shrink parameter must be a number between 0 and 1.");
	}
}

OptResult NelderMead::Optimize(std::shared_ptr<Area> A, std::shared_ptr<Function> F, std::shared_ptr<TerminalCondition> T, const vPoint & FirstPoint)
{
	if (A->GetDim() != F->GetDim())  throw std::invalid_argument("Function dimension and area dimension must be equal.");
	if (!A->In(FirstPoint)) throw std::invalid_argument("First point must be in area.");

	Simplex simplex(A->GetDim());
	simplex.MoveTo(FirstPoint);
	simplex.Squeeze(A);

	std::vector<vPoint> Approx;
	Approx.push_back(FirstPoint);

	std::vector<double> Evals;
	Evals.push_back(F->eval(FirstPoint));

	int n = A->GetDim();
	do {
		//step 0 - Squeeze
		simplex.Squeeze(A);

		//step 1 - Order
		simplex.Sort(F);
		Approx.push_back(simplex[0]);

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


	} while (!(T->Stop(F, Approx, Evals)));

	OptResult Res;

	Res.Fun = F;
	Res.OptArea = A;
	Res.Approximations = Approx;
	Res.Evaluations = Evals;
	Res.Iterations = Evals.size();
	Res.Result = Approx.back();
	Res.ResFuncValue = Evals.back();

	return Res;
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

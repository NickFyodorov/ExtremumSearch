#include "optimization_method.h"
#include "random_search.h"
#include "random_seed.h"

bool RandomSearch::SetP(double _p)
{
	if(_p < 0 || _p > 1) return false;
	p = _p;
	return true;
}

bool RandomSearch::SetGamma(double _gamma)
{
	if(_gamma < 0 || _gamma > 1) return false;
	gamma = _gamma;
	return true;
}

std::vector<vPoint> RandomSearch::Optimize(const Area * A, const Function * F, const TerminalCondition * T, const vPoint & FirstPoint)
{
	std::vector<vPoint> Approximation;
	Approximation.push_back(FirstPoint);

	std::bernoulli_distribution ber(p);

	std::shared_ptr<Area> pSubArea;
	double subarea_size = 1;
	vPoint Current;

	do {
		if (ber(rng)) {
			Current = A->RandomPoint();
		}
		else {
			pSubArea = A->SubArea(Approximation.back(), subarea_size);
			do {
				Current = pSubArea->RandomPoint();
			} while (!A->In(Current));
			subarea_size *= gamma;
		}
		Approximation.push_back(Current);
	} while (!T->Stop(F, Approximation));

	return Approximation;
}

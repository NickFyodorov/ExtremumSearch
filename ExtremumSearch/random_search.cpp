#include "optimization_method.h"
#include "random_search.h"
#include "random_seed.h"

vPointSeq& RandomSearch::Optimize(const Area * A, const Function * F, const TerminalCondition * T, const vPoint & FirstPoint)
{
	vPointSeq Approximation;
	Approximation.push_back(FirstPoint);

	std::bernoulli_distribution ber(p);

	Area * pSubArea;
	double subarea_size = 1;
	vPoint Current;

	do {
		if (ber(rng)) {
			Current = A->RandomPoint();
		}
		else {
			pSubArea = A->SubArea(*Approximation.end(), subarea_size);
			Current = pSubArea->RandomPoint();
			subarea_size *= gamma;
		}
		Approximation.push_back(Current);
	} while (!T->Stop(F, Approximation));

	return Approximation;
}

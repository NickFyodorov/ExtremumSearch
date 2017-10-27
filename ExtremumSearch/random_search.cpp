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

OptResult RandomSearch::Optimize(std::shared_ptr<Area> A, std::shared_ptr<Function> F, std::shared_ptr<TerminalCondition> T, const vPoint & FirstPoint)
{
	std::vector<vPoint> Approx;
	Approx.push_back(FirstPoint);

	std::vector<double> Evals;
	Evals.push_back(F->eval(FirstPoint));

	std::bernoulli_distribution ber(p);

	std::shared_ptr<Area> pSubArea;
	double subarea_size = 1;
	vPoint Current;

	do {
		if (ber(rng)) {
			Current = A->RandomPoint();
		}
		else {
			pSubArea = A->SubArea(Approx.back(), subarea_size);
			do {
				Current = pSubArea->RandomPoint();
			} while (!A->In(Current));
			subarea_size *= gamma;
		}
		Approx.push_back(Current);
		Evals.push_back(F->eval(Current));
	} while (!T->Stop(F, Approx, Evals));

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

void RandomSearch::Info() const
{
	std::cout << "Random Search(" << "P = " << GetP() << "," << "Gamma = " << GetGamma() << ")";
}

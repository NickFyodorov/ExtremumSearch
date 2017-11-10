#include "Simplex.h"

Simplex::Simplex(int _dim) : dim(_dim)
{
	vPoint X(dim);
	vertices.push_back(X);
	for (int i = 0; i < dim; ++i)
	{
		X[i] = 1;
		vertices.push_back(X);
		X[i] = 0;
	}
}

Simplex::Simplex(const std::vector<vPoint> &_vertices) : 
	dim(_vertices[0].GetDim())
{

	if (vertices.size() != (dim + 1))
	{
		throw std::invalid_argument("Simplex dimension must be"
			" equal to its veritices dimension plus one");
	}

	for (int i = 0; i < _vertices.size(); ++i)
	{
		if (_vertices[i].GetDim() != dim)
		{
			throw std::invalid_argument("Simplex vertices dimensions"
				" must be equal");
		}
	}

	//check that it is a simplex (too complicated)

	for (int i = 0; i < _vertices.size(); ++i)
		vertices.push_back(_vertices[i]);
}

void Simplex::MoveTo(const vPoint &X)
{
	vPoint Offset(X);
	Offset -= vertices[0];
	for (int i = 0; i < vertices.size(); ++i)
		vertices[i] += Offset;
}

void Simplex::Squeeze(std::shared_ptr<Area> A)
{
	double squeeze = 1;
	vPoint tmp;
	bool all_in;
	do
	{
		all_in = true;
		for (int i = 0; i < vertices.size(); ++i)
		{
			if (!A->In(vertices[i]))
			{
				all_in = false;
				break;
			}
		}
		if (!all_in)
		{
			squeeze *= 0.5;
			for (int i = 1; i < vertices.size(); ++i)
			{
				vertices[i] -= vertices[0];
				vertices[i] *= squeeze;
				vertices[i] += vertices[0];
			}
		}
	} while (!all_in);
}

void Simplex::Sort(std::shared_ptr<Function> F)
{
	std::sort(vertices.begin(), vertices.end(), 
	[&](const vPoint &X1, const vPoint &X2) 
	{ return F->eval(X1) < F->eval(X2); });
}
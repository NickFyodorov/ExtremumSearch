#include "Simplex.h"

Simplex::Simplex(int _dim) : dim(_dim)
{
	vPoint X(dim, arma::fill::zeros);
	vertices.push_back(X);
	for (int i = 0; i < dim; ++i) {
		X[i] = 1;
		vertices.push_back(X);
		X[i] = 0;
	}
}

Simplex::Simplex(const vPointSeq & _vertices) : dim(_vertices[0].n_elem)
{

	if (vertices.size() != (dim + 1)) {
		//exception
	}

	for (int i = 0; i < _vertices.size(); ++i) {
		if (_vertices[i].n_elem != dim) {
			//exception
		}
	}

	//check that it is a simplex

	for (int i = 0; i < _vertices.size(); ++i) vertices.push_back(_vertices[i]);
}

void Simplex::MoveTo(const vPoint & X)
{
	vPoint Centroid(vertices[0]);

	for (int i = 1; i < vertices.size(); ++i) Centroid += vertices[i];
	Centroid /= vertices.size();

	vPoint Offset = X - Centroid;

	for (int i = 0; i < vertices.size(); ++i) vertices[i] += Offset;
}

void Simplex::Squeeze(const Area * A)
{
	vPoint Centroid(vertices[0]);

	for (int i = 1; i < vertices.size(); ++i) Centroid += vertices[i];
	Centroid /= vertices.size();

	double squeeze = 1;

	if (!A->In(Centroid)) {
		//exception
	}

	bool all_in;
	do {
		all_in = true;
		for (int i = 0; i < vertices.size; ++i) {
			if (!A->In(vertices[i])) {
				all_in = false;
				break;
			}
		}
		if (!all_in) {
			squeeze *= 0.5;
			for (int i = 0; i < vertices.size; ++i) {
				vertices[i] = Centroid + squeeze * (vertices[i] - Centroid);
			}
		}
	} while (!all_in);
}



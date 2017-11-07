#pragma once

#include <algorithm>
#include <functional>

#include "area.h"
#include "function.h"
#include "vpoint.h"


/*!
\section DESCRIPTION

The Simplex class is used by NelderMead and represents a simplex of vector points
*/
class Simplex {
private:
	int dim;///< the size of the simplex
	std::vector<vPoint> vertices;///< the vectices of the simplex
public:
	Simplex(int _dim = 2);///< creates a standard simplex with given size
	Simplex(const std::vector<vPoint>& _vertices);///< creates a simplex with given vertices
	virtual ~Simplex() {};///< destructor
	void MoveTo(const vPoint& X);///< offsets all vertices of the simplex by given vector point
	void Squeeze(std::shared_ptr<Area> A);///< shrinks the simplex until it fits the area
	const vPoint& operator[](int index) const { return vertices[index]; }///< returns a vertex of the simplex at given index
	vPoint& operator[](int index) { return vertices[index]; }///< returns a vertex of the simplex at given index
	int Size() const { return vertices.size(); }///< returns the size of the simplex
	void Sort(std::shared_ptr<Function> F);///< sorts the vertices of the simplex by comparing the evaluations of a function at each vertex
};

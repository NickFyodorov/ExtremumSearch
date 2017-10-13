#pragma once

#include <algorithm>
#include <functional>

#include "area.h"
#include "function.h"
#include "vpoint.h"

class Simplex {
private:
	int dim;
	std::vector<vPoint> vertices;
public:
	Simplex(int _dim = 2);
	Simplex(const std::vector<vPoint>& _vertices);
	virtual ~Simplex() {};
	void MoveTo(const vPoint& X);
	void Squeeze(const Area * A);
	const vPoint& operator[](int index) const { return vertices[index]; }
	vPoint& operator[](int index) { return vertices[index]; }
	int Size() const { return vertices.size(); }
	void Sort(const Function * F);
};

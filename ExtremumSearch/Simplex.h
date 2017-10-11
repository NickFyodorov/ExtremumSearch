#pragma once

#include "area.h"
#include "custom_defines.h"

class Simplex {
private:
	int dim;
	vPointSeq vertices;
public:
	Simplex(int _dim = 2);
	Simplex(const vPointSeq& _vertices);
	virtual ~Simplex() {};
	void MoveTo(const vPoint& X);
	void Squeeze(const Area * A);
	const vPoint& operator[](int index) const { return vertices[index]; }
	vPoint& operator[](int index) { return vertices[index]; }
	int Size() const { return vertices.size(); }
};

#pragma once

#include "area.h"
#include "custom_defines.h"

class Simplex : Area {
private:
	vPointSeq vertices;
public:
	Simplex(int _dim = 2);
	Simplex(const vPointSeq& _vertices);
	virtual ~Simplex() {};
	void MoveTo(const vPoint& X);
	void Squeeze(Area * A);
	virtual bool In(const vPoint& X) const;
	virtual vPoint& RandomPoint() const;
	virtual Area* SubArea(const vPoint& X, double epsilon) const;
};

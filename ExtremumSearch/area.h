#pragma once

#include <iostream>
#include <cstdlib>
#include <armadillo>

class Point {

};

class Area {
private:
    int dim;
public:
    Area(int _dim);
    virtual ~Area();
    virtual bool In(const Point& P) const = 0;
};
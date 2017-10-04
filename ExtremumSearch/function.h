#pragma once

#include <armadillo>

class Function {
private:
    int dim;
public:
    Function(int _dim) : dim(_dim) {}
    virtual ~Function();
    virtual double eval() const = 0;
    int GetDim() const {
        return dim;
    }
};
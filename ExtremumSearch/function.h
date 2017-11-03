#pragma once

#include <memory>
#include <string>

#include "vpoint.h"
#include "area.h"

/*!
\file
\author Nikita Fyodorov
\version 1.0

\section DESCRIPTION

The Function class represents an abstract vector-function which can be evaluated in given domain
*/

class Function {
protected:
	std::shared_ptr<Area> domain;///<the domain of the function (the area in which the function is defined)
public:
	/*!
	constructor that sets the domain of the function
	\param _domain Domain of the function
	*/
    Function(std::shared_ptr<Area> _domain) : domain(_domain) {}
	/*!
	destructor of the class
	*/
	virtual ~Function() { }
	/*!
	abstract method that returns the result of evaluation of the function in given point
	\param X The point in which the function is evaluated
	\return double precision number which represents the result of the evaluation
	*/
    virtual double eval(const vPoint& X) const = 0;
	/*!
	returns the dimension of the function domain
	\return the domain dimension
	*/
    int GetDim() const {
        return domain->GetDim();
    }
	/*!
	returns the result of evaluation of the function in given point (equal to eval(X))
	\param X The point in which the function is evaluated
	\return double precision number which represents the result of the evaluation
	*/
	double operator()(const vPoint& X) const { return eval(X); }
	/*!
	abstract method that prints the formula of the function
	*/
	virtual void Info() const = 0;
	/*!
	prints the formula of the function std::cout stream
	\param out output stream
	\param F shared pointer to the function, which formula is to be printed
	*/
	friend std::ostream& operator<<(std::ostream& out, std::shared_ptr<Function> F) {
		F->Info();
		return out;
	}
	/*!
	calculates gradient of the function F using formula: 1 / (2*dX) * (F(X + dX) - F(X - dX))
	\return double precision number which represents the result of the gradient calculation
	*/
	friend double CalcGrad(std::shared_ptr<Function> F, const vPoint& X, double delta);
};
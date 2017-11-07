#pragma once

#include <vector>
#include <string>

#include "vpoint.h"
#include "area.h"
#include "function.h"
#include "terminal_condition.h"


/*!
\section DESCRIPTION

The OptResult structure represents the result of optimization process for a function in given area
*/
struct OptResult {
	std::shared_ptr<Function> Fun;///< pointer to the function for which the optimization was done
	std::shared_ptr<Area> OptArea;///< pointer to the area in which the optimization was done
	std::vector<vPoint> Approximations;///< std::vector of approximation vector points
	std::vector<double> Evaluations;///< std::vector of function evaluations in approximation points
	vPoint Result;///< vector point that represents the result of optimization
	double ResFuncValue;///< function evaluation value in the resulting point
	int Iterations;///< number of iterations of the optimization process
};


/*!
\section DESCRIPTION

The OptimizationMethod class represent an optimization method with the method parameters
*/
class OptimizationMethod {
private:
public:
	OptimizationMethod() {}///< constructor
	virtual ~OptimizationMethod() {}///< destructor
	/*!
	abstract method that runs the optimization process using the optimization method for a function in given area with given terminal condition
	\param A pointer the area in which the function is optimized
	\param F pointer to the function that is optimized
	\param T pointer to the terminal condition for the method
	\param FirstPoint vector point from which the optimization process begins
	\return OptResult structure with the result of the optimization
	*/
	virtual OptResult Optimize(std::shared_ptr<Area> A, std::shared_ptr<Function> F, std::shared_ptr<TerminalCondition> T, const vPoint& FirstPoint) = 0;
    virtual char* Name() const = 0;///< abstract method that returns the name of the method
	virtual void Info() const = 0;///< abstract method that writes the information about the method to std::cout
	/*!
	overloaded output operator for std::cout
	*/
	friend std::ostream& operator<<(std::ostream& out, std::shared_ptr<OptimizationMethod> optMethod) {
		optMethod->Info();
		return out;
	}
};
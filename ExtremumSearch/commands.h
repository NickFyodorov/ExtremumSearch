#pragma once

/* system headers and other libraries*/
#include <iostream>
#include <cstdlib>
#include <string>
#include <random>
#include <vector>
#include <map>

#include <memory>
#include <sstream>

/* base headers */

#include "random_seed.h"
#include "vpoint.h"
#include "variables.h"

/* abstract headers */
#include "area.h"
#include "function.h"
#include "smooth_function.h"
#include "terminal_condition.h"
#include "optimization_method.h"

/* terminal conditions */
#include "count_condition.h"
#include "eps_condition.h"
#include "condition_f_difference.h"
#include "condition_x_difference.h"
#include "condition_improvement.h"
#include "condition_grad.h"
#include "condition_iter.h"

/* functions */
#include "test_func_01.h"
#include "test_func_02.h"
#include "test_func_03.h"
#include "test_func_04.h"
#include "test_func_05.h"

/* areas */
#include "range.h"
#include "ncube.h"

/* optimization methods */
#include "nelder_mead.h"
#include "random_search.h"

/* used by nelder-mead */
#include "Simplex.h"

typedef std::map<std::string, std::shared_ptr<void>> VarMap;
typedef void (*pcommand)(std::stringstream &, VarMap &);
typedef std::map<std::string, pcommand> CommandMap;

template <typename T>
std::shared_ptr<T> GetVariable(VarMap &varmap, std::string &varname)
{
	if (varmap.find(varname) == varmap.end())
	{
		std::stringstream message;
		message << "Error: variable " << varname << " does not exist";
		throw std::invalid_argument(message.str());
	}
	return std::static_pointer_cast<T>(varmap[varname]);
}

void execute(std::stringstream &command, CommandMap &commands, VarMap &variables)
{
	command.exceptions(std::ios::failbit);
	std::string name;
	command >> name;

	if (commands.find(name) == commands.end())
	{
		std::cout << "Error: command " << name << " does not exist" << std::endl;
	}
	else
	{
		try
		{
			(*commands[name])(command, variables);
		}
		catch (std::exception e)
		{
			std::cout << e.what() << std::endl;
		}
	}
}

enum VarType
{
	FUN,
	AREA,
	METHOD,
	COND,
	POINT
};

std::map<std::string, VarType> VarTypeMap;

void InitVarTypeMap()
{
	VarTypeMap["function"] = VarType::FUN;
	VarTypeMap["fun"] = VarType::FUN;
	VarTypeMap["fn"] = VarType::FUN;
	VarTypeMap["area"] = VarType::AREA;
	VarTypeMap["condition"] = VarType::COND;
	VarTypeMap["cond"] = VarType::COND;
	VarTypeMap["method"] = VarType::METHOD;
	VarTypeMap["optmethod"] = VarType::METHOD;
	VarTypeMap["point"] = VarType::POINT;
	VarTypeMap["pt"] = VarType::POINT;
}

//enum FuncType {
//	F1,
//	F2,
//	F3,
//	F4,
//	F5
//};
//
//std::map<std::string, FuncType> FuncTypeMap;
//
//void InitFuncTypeMap() {
//	FuncTypeMap["f1"] = FuncType::F1;
//	FuncTypeMap["f2"] = FuncType::F2;
//	FuncTypeMap["f3"] = FuncType::F3;
//	FuncTypeMap["f4"] = FuncType::F4;
//	FuncTypeMap["f5"] = FuncType::F5;
//}

enum CondType
{
	ITER,
	IMPROVEMENT,
	XDIFF,
	FDIFF,
	GRAD
};

std::map<std::string, CondType> CondTypeMap;

void InitCondTypeMap()
{
	CondTypeMap["iteration"] = CondType::ITER;
	CondTypeMap["iter"] = CondType::ITER;
	CondTypeMap["improvement"] = CondType::IMPROVEMENT;
	CondTypeMap["improve"] = CondType::IMPROVEMENT;
	CondTypeMap["xdiff"] = CondType::XDIFF;
	CondTypeMap["fdiff"] = CondType::FDIFF;
	CondTypeMap["grad"] = CondType::GRAD;
}

enum MethodType
{
	NELDER,
	RANDOM
};

std::map<std::string, MethodType> MethodTypeMap;

void InitMethodTypeMap()
{
	MethodTypeMap["nelder"] = MethodType::NELDER;
	MethodTypeMap["random"] = MethodType::RANDOM;
}

VarMap Variables;
CommandMap Commands;

void InitVarMap()
{
	std::vector<std::shared_ptr<Range>> ranges;
	ranges.push_back(std::make_shared<Range>(-100, 100));
	ranges.push_back(std::make_shared<Range>(-100, 100));
	std::shared_ptr<Area> domain = 
		std::static_pointer_cast<Area>(std::make_shared<NCube>(ranges));

	Variables["f1"] = 
		std::static_pointer_cast<void>(std::make_shared<TestFunc01>(domain));
	Variables["f2"] = 
		std::static_pointer_cast<void>(std::make_shared<TestFunc02>(domain));
	Variables["f3"] = 
		std::static_pointer_cast<void>(std::make_shared<TestFunc03>(domain));
	Variables["f4"] = 
		std::static_pointer_cast<void>(std::make_shared<TestFunc04>(domain));
	Variables["f5"] = 
		std::static_pointer_cast<void>(std::make_shared<TestFunc05>(domain));
}

void command_test(std::stringstream &params, VarMap &variables)
{
	std::cout << "test OK";
}

/* opt <fun> <area> <method> <condition> <point>*/
void command_opt(std::stringstream &params, VarMap &variables)
{
	std::string fvar, areavar, methodvar, condvar, pvar;

	try
	{
		params >> fvar;
		if (fvar == "")
			throw std::invalid_argument("Error: function argument"
				" is missing with no default");
	}
	catch (...)
	{
		if (params.fail())
			throw std::invalid_argument("Error: failed to read function"
				" argument");
	}

	try
	{
		params >> areavar;
		if (areavar == "")
			throw std::invalid_argument("Error: area argument is missing"
				" with no default");
	}
	catch (...)
	{
		if (params.fail())
			throw std::invalid_argument("Error: failed to read area argument");
	}

	try
	{
		params >> methodvar;
		if (methodvar == "")
			throw std::invalid_argument("Error: optimization method argument"
				" is missing with no default");
	}
	catch (...)
	{
		if (params.fail())
			throw std::invalid_argument("Error: failed to read optimization"
				" method argument");
	}

	try
	{
		params >> condvar;
		if (condvar == "")
			throw std::invalid_argument("Error: terminal condition argument"
				" is missing with no default");
	}
	catch (...)
	{
		if (params.fail())
			throw std::invalid_argument("Error: failed to read terminal"
				" condition argument");
	}

	try
	{
		params >> pvar;
		if (pvar == "")
			throw std::invalid_argument("Error: first point argument"
				" is missing with no default");
	}
	catch (...)
	{
		if (params.fail())
			throw std::invalid_argument("Error: failed to read "
				"first point argument");
	}

	OptResult optres = 
		GetVariable<OptimizationMethod>(variables, methodvar)->Optimize(
			GetVariable<Area>(variables, areavar), 
			GetVariable<Function>(variables, fvar), 
			GetVariable<TerminalCondition>(variables, condvar), 
			*GetVariable<vPoint>(variables, pvar));
	std::shared_ptr<OptResult> optRes(new OptResult);
	*optRes = optres;
	std::string optresvar;
	try
	{
		params >> optresvar;
	}
	catch (...)
	{
		optresvar = "default";
	}
	variables[optresvar] = std::static_pointer_cast<void>(optRes);

	std::cout << "Result: " << optRes->Result << std::endl
			  << optRes->Iterations << " iterations";
}

/* get <vartype> <varname>*/
void command_get(std::stringstream &params, VarMap &variables)
{
	std::string vartype;
	try
	{
		if (params.eof())
			throw std::invalid_argument("Error: variable type argument"
				" is missing with no default");
		params >> vartype;
	}
	catch (...)
	{
		if (params.fail())
			throw std::invalid_argument("Error: failed to read variable"
				" type argument");
	}

	std::string varname;
	try
	{
		if (params.eof())
			throw std::invalid_argument("Error: variable name argument"
				" is missing with no default");
		params >> varname;
	}
	catch (...)
	{
		if (params.fail())
			throw std::invalid_argument("Error: failed to read variable"
				" name argument");
	}

	switch (VarTypeMap[vartype])
	{
	case VarType::FUN:
		std::cout << GetVariable<Function>(variables, varname);
		break;
	case VarType::AREA:
		std::cout << GetVariable<Area>(variables, varname);
		break;
	case VarType::COND:
		std::cout << GetVariable<TerminalCondition>(variables, varname);
		break;
	case VarType::METHOD:
		std::cout << GetVariable<OptimizationMethod>(variables, varname);
		break;
	case VarType::POINT:
		std::cout << *GetVariable<vPoint>(variables, varname);
		break;
	default:
		throw std::invalid_argument("Error: incorrect variable type");
		break;
	}
}

/*add <vartype> <varname> [variable params]*/
void command_add(std::stringstream &params, VarMap &variables)
{
	std::string vartype;
	try
	{
		if (params.eof())
			throw std::invalid_argument("Error: variable type argument"
				" is missing with no default");
		params >> vartype;
	}
	catch (...)
	{
		if (params.fail())
			throw std::invalid_argument("Error: failed to read variable"
				" type argument");
	}

	std::string varname;
	try
	{
		if (params.eof())
			throw std::invalid_argument("Error: variable name argument"
				" is missing with no default");
		params >> varname;
	}
	catch (...)
	{
		if (params.fail())
			throw std::invalid_argument("Error: failed to read variable"
				" name argument");
	}

	std::string param;

	std::vector<std::shared_ptr<Range>> ranges;
	std::vector<double> coords;
	int maxiter;
	double eps;
	double reflection, contraction, expansion, shrink;
	double p, gamma;
	int dim;

	switch (VarTypeMap[vartype])
	{
	case VarType::AREA:
		if (params.eof())
			throw std::invalid_argument("Error: area dimension parameter"
				" is missing");
		try
		{
			params >> dim;
		}
		catch (...)
		{
			throw std::invalid_argument("Error: unable to read area "
				"dimension argument");
		}
		double min, max;
		for (int i = 0; i < dim; ++i)
		{
			if (params.eof())
				throw std::invalid_argument("Error: range left bound "
					"parameter is missing");
			try
			{
				params >> min;
			}
			catch (...)
			{
				if (params.fail())
					throw std::invalid_argument("Error: unable to read left"
						" range bound parameter");
			}
			if (params.eof())
				throw std::invalid_argument("Error: range right bound"
					" parameter is missing");
			try
			{
				params >> max;
			}
			catch (...)
			{
				if (params.fail())
					throw std::invalid_argument("Error: unable to read right"
						" range bound parameter");
			}
			ranges.push_back(std::make_shared<Range>(min, max));
		}
		variables[varname] = 
			std::static_pointer_cast<void>(std::make_shared<NCube>(ranges));
		break;
	case VarType::COND:
		if (params.eof())
			throw std::invalid_argument("Error: terminal condition type "
				"argument is missing");
		try
		{
			params >> param;
		}
		catch (...)
		{
			throw std::invalid_argument("Error: unable to read terminal"
				" condition type argument");
		}
		switch (CondTypeMap[param])
		{
		case CondType::ITER:
			if (params.eof())
				throw std::invalid_argument("Error: maximal iterations"
					" argument is missing");
			try
			{
				params >> maxiter;
			}
			catch (...)
			{
				throw std::invalid_argument("Error: unable to read"
					" maximal iterations argument");
			}
			variables[varname] = 
				std::static_pointer_cast<void>(
					std::make_shared<ConditionIter>(maxiter));
			break;
		case CondType::IMPROVEMENT:
			if (params.eof())
				throw std::invalid_argument("Error: maximal iterations"
					" argument is missing");
			try
			{
				params >> maxiter;
			}
			catch (...)
			{
				throw std::invalid_argument("Error: unable to read"
					" maximal iterations argument");
			}
			variables[varname] = 
				std::static_pointer_cast<void>(
					std::make_shared<ConditionImprovement>(maxiter));
			break;
		case CondType::XDIFF:
			if (params.eof())
				throw std::invalid_argument("Error: epsilon argument"
					" is missing");
			try
			{
				params >> eps;
			}
			catch (...)
			{
				throw std::invalid_argument("Error: unable to read"
					" epsilon argument");
			}
			variables[varname] = 
				std::static_pointer_cast<void>(
					std::make_shared<ConditionXDiff>(eps));
			break;
		case CondType::FDIFF:
			if (params.eof())
				throw std::invalid_argument("Error: epsilon argument"
					" is missing");
			try
			{
				params >> eps;
			}
			catch (...)
			{
				throw std::invalid_argument("Error: unable to read"
					" epsilon argument");
			}
			variables[varname] = 
				std::static_pointer_cast<void>(
					std::make_shared<ConditionFDiff>(eps));
			break;
		case CondType::GRAD:
			if (params.eof())
				throw std::invalid_argument("Error: epsilon argument"
					" is missing");
			try
			{
				params >> eps;
			}
			catch (...)
			{
				throw std::invalid_argument("Error: unable to read"
					" epsilon argument");
			}
			variables[varname] = 
				std::static_pointer_cast<void>(
					std::make_shared<ConditionGrad>(eps));
			break;
		default:
			break;
		}
		break;
	case VarType::METHOD:
		if (params.eof())
			throw std::invalid_argument("Error: optimization method"
				" type argument is missing");
		try
		{
			params >> param;
		}
		catch (...)
		{
			throw std::invalid_argument("Error: unable to read"
				" optimization method type argument");
		}
		switch (MethodTypeMap[param])
		{
		case MethodType::NELDER:
			if (params.eof())
				throw std::invalid_argument("Error: reflection argument"
					" is missing");
			try
			{
				params >> reflection;
			}
			catch (...)
			{
				throw std::invalid_argument("Error: unable to read"
					" reflection argument");
			}
			if (params.eof())
				throw std::invalid_argument("Error: expansion"
					" argument is missing");
			try
			{
				params >> expansion;
			}
			catch (...)
			{
				throw std::invalid_argument("Error: unable to read"
					" expansion argument");
			}
			if (params.eof())
				throw std::invalid_argument("Error: contraction"
					" argument is missing");
			try
			{
				params >> contraction;
			}
			catch (...)
			{
				throw std::invalid_argument("Error: unable to read"
					" contraction argument");
			}
			if (params.eof())
				throw std::invalid_argument("Error: shrink argument"
					" is missing");
			try
			{
				params >> shrink;
			}
			catch (...)
			{
				throw std::invalid_argument("Error: unable to read"
					" shrink argument");
			}
			variables[varname] = 
				std::static_pointer_cast<void>(
					std::make_shared<NelderMead>(
						reflection, 
						expansion, 
						contraction, 
						shrink));
			break;
		case MethodType::RANDOM:
			if (params.eof())
				throw std::invalid_argument("Error: p argument"
					" is missing");
			try
			{
				params >> p;
			}
			catch (...)
			{
				throw std::invalid_argument("Error: unable to read"
					" p argument");
			}
			if (params.eof())
				throw std::invalid_argument("Error: gamma argument"
					" is missing");
			try
			{
				params >> gamma;
			}
			catch (...)
			{
				throw std::invalid_argument("Error: unable to read"
					" gamma argument");
			}
			variables[varname] = 
				std::static_pointer_cast<void>(
					std::make_shared<RandomSearch>(p, gamma));
			break;
		default:
			break;
		}
		break;
	case VarType::POINT:
		if (params.eof())
			throw std::invalid_argument("Error: point dimension"
				" argument is missing");
		try
		{
			params >> dim;
		}
		catch (...)
		{
			throw std::invalid_argument("Error: unable to read point"
				" dimension argument");
		}
		double x;
		for (int i = 0; i < dim; ++i)
		{
			if (params.eof())
				throw std::invalid_argument("Error: number of coordinates"
					" is less than the point dimension argument");
			try
			{
				params >> x;
			}
			catch (...)
			{
				throw std::invalid_argument("Error: unable to read"
					" point coordinate argument");
			}
			coords.push_back(x);
		}
		variables[varname] = 
			std::static_pointer_cast<void>(
				std::make_shared<vPoint>(coords));
		break;
	default:
		std::cout << "Incorrect Input";
		return;
		break;
	}
	std::cout << "variable " << varname << " added successfully";
}

void command_rm(std::stringstream &params, VarMap &variables)
{
	std::string varname;
	if (params.eof())
		throw std::invalid_argument("Error: variable name argument"
			" is missing");
	try
	{
		params >> varname;
	}
	catch (...)
	{
		throw std::invalid_argument("Error: unable to read variable"
			" name argument");
	}
	variables.erase(varname);
	std::cout << "variable " << varname << " erased successfully";
}

void InitCommandMap()
{
	Commands["opt"] = &command_opt;
	Commands["add"] = &command_add;
	Commands["rm"] = &command_rm;
	Commands["get"] = &command_get;
	Commands["test"] = &command_test;
}

void Initialize()
{
	InitCommandMap();
	InitVarMap();
	InitVarTypeMap();
	InitCondTypeMap();
	InitMethodTypeMap();
}
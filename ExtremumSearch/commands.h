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
typedef void (*pcommand)(std::stringstream&, VarMap&);
typedef std::map<std::string, pcommand> CommandMap;

template <typename T>
std::shared_ptr<T> GetVariable(VarMap& varmap, std::string& varname) {
	return std::static_pointer_cast<T>(varmap[varname]);
}

void execute(std::stringstream& command, CommandMap& commands, VarMap& variables) {
	std::string name;
	command >> name;
	
	(*commands[name])(command, variables);
}

enum VarType {
	FUN,
	AREA,
	METHOD,
	COND,
	POINT
};

std::map<std::string, VarType> VarTypeMap;

void InitVarTypeMap() {
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

enum CondType {
	ITER,
	IMPROVEMENT,
	XDIFF,
	FDIFF,
	GRAD
};

std::map<std::string, CondType> CondTypeMap;

void InitCondTypeMap() {
	CondTypeMap["iteration"] = CondType::ITER;
	CondTypeMap["iter"] = CondType::ITER;
	CondTypeMap["improvement"] = CondType::IMPROVEMENT;
	CondTypeMap["improve"] = CondType::IMPROVEMENT;
	CondTypeMap["xdiff"] = CondType::XDIFF;
	CondTypeMap["fdiff"] = CondType::FDIFF;
	CondTypeMap["grad"] = CondType::GRAD;
}

enum MethodType {
	NELDER,
	RANDOM
};

std::map<std::string, MethodType> MethodTypeMap;

void InitMethodTypeMap() {
	MethodTypeMap["nelder"] = MethodType::NELDER;
	MethodTypeMap["random"] = MethodType::RANDOM;
}

VarMap Variables;
CommandMap Commands;

void InitVarMap() {
	std::vector<std::shared_ptr<Range>> ranges;
	ranges.push_back(std::make_shared<Range>(-100, 100));
	ranges.push_back(std::make_shared<Range>(-100, 100));
	std::shared_ptr<Area> domain = std::static_pointer_cast<Area>(std::make_shared<NCube>(ranges));

	Variables["f1"] = std::static_pointer_cast<void>(std::make_shared<TestFunc01>(domain));
	Variables["f2"] = std::static_pointer_cast<void>(std::make_shared<TestFunc02>(domain));
	Variables["f3"] = std::static_pointer_cast<void>(std::make_shared<TestFunc03>(domain));
	Variables["f4"] = std::static_pointer_cast<void>(std::make_shared<TestFunc04>(domain));
	Variables["f5"] = std::static_pointer_cast<void>(std::make_shared<TestFunc05>(domain));
}

void command_test(std::stringstream& params, VarMap& variables) {
	std::cout << "test OK";
}

/* opt <fun> <area> <method> <condition> <point>*/
void command_opt(std::stringstream& params, VarMap& variables) {
	std::string fvar, areavar, methodvar, condvar, pvar;
	params >> fvar >> areavar >> methodvar >> condvar >> pvar;
	OptResult optres = GetVariable<OptimizationMethod>(variables, methodvar)->Optimize(
		GetVariable<Area>(variables, areavar),
		GetVariable<Function>(variables, fvar),
		GetVariable<TerminalCondition>(variables, condvar),
		*GetVariable<vPoint>(variables, pvar)
	);
	std::shared_ptr<OptResult> optRes(new OptResult);
	*optRes = optres;
	std::string optresvar;
	params >> optresvar;
	variables[optresvar] = std::static_pointer_cast<void>(optRes);

	std::cout << optRes->Result;
}

/* get <vartype> <varname>*/
void command_get(std::stringstream& params, VarMap& variables) {
	std::string vartype;
	params >> vartype;

	std::string varname;
	params >> varname;

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
		std::cout << "Incorrect Input";
		break;
	}
}

/*add <vartype> <varname> [variable params]*/
void command_add(std::stringstream& params, VarMap& variables) {
	std::string vartype;
	params >> vartype;

	std::string varname;
	params >> varname;

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
		params >> dim;
		double min, max;
		for (int i = 0; i < dim; ++i) {
			params >> min;
			params >> max;
			ranges.push_back(std::make_shared<Range>(min, max));
		}
		variables[varname] = std::static_pointer_cast<void>(std::make_shared<NCube>(ranges));
		break;
	case VarType::COND:
		params >> param;
		switch (CondTypeMap[param])
		{
		case CondType::ITER:
			params >> maxiter;
			variables[varname] = std::static_pointer_cast<void>(std::make_shared<ConditionIter>(maxiter));
			break;
		case CondType::IMPROVEMENT:
			params >> maxiter;
			variables[varname] = std::static_pointer_cast<void>(std::make_shared<ConditionImprovement>(maxiter));
			break;
		case CondType::XDIFF:
			params >> eps;
			variables[varname] = std::static_pointer_cast<void>(std::make_shared<ConditionXDiff>(eps));
			break;
		case CondType::FDIFF:
			params >> eps;
			variables[varname] = std::static_pointer_cast<void>(std::make_shared<ConditionFDiff>(eps));
			break;
		case CondType::GRAD:
			params >> eps;
			variables[varname] = std::static_pointer_cast<void>(std::make_shared<ConditionGrad>(eps));
			break;
		default:
			break;
		}
		break;
	case VarType::METHOD:
		params >> param;
		switch (MethodTypeMap[param])
		{
		case MethodType::NELDER:
			params >> reflection >> expansion >> contraction >> shrink;
			variables[varname] = std::static_pointer_cast<void>(std::make_shared<NelderMead>(reflection, expansion, contraction, shrink));
			break;
		case MethodType::RANDOM:
			params >> p >> gamma;
			variables[varname] = std::static_pointer_cast<void>(std::make_shared<RandomSearch>(p, gamma));
			break;
		default:
			break;
		}
		break;
	case VarType::POINT:
		params >> dim;
		double x;
		for (int i = 0; i < dim; ++i) {
			params >> x;
			coords.push_back(x);
		}
		variables[varname] = std::static_pointer_cast<void>(std::make_shared<vPoint>(coords));
		break;
	default:
		std::cout << "Incorrect Input";
		return;
		break;
	}
	std::cout << "variable " << varname << " added successfully";
}

void command_rm(std::stringstream& params, VarMap& variables) {
	std::string varname;
	params >> varname;
	variables.erase(varname);
	std::cout << "variable " << varname << " erased successfully";
}

void InitCommandMap() {
	Commands["opt"] = &command_opt;
	Commands["add"] = &command_add;
	Commands["rm"] = &command_rm;
	Commands["get"] = &command_get;
	Commands["test"] = &command_test;
}

void Initialize() {
	InitCommandMap();
	InitVarMap();
	InitVarTypeMap();
	InitCondTypeMap();
	InitMethodTypeMap();
}
/* system headers and other libraries*/
#include <iostream>
#include <cstdlib>
#include <string>
#include <random>
#include <vector>

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

int main() {
	std::vector<Range> Ranges = { Range(-100, 100), Range(-100, 100) };
	std::vector<Area*> Areas = {
		new NCube(Ranges),
		new NCube,
		new NCube
	};
	std::vector<Function*> Functions = {
		new TestFunc01(Areas[0]),
		new TestFunc02(Areas[0]),
		new TestFunc03(Areas[0]),
		new TestFunc04(Areas[0]),
		new TestFunc05(Areas[0]) 
	};
	std::vector<OptimizationMethod*> OptMethods = {
		new NelderMead,
		new RandomSearch(1.0)
	};
	std::vector<TerminalCondition*> Conditions = {
		new ConditionFDiff(eps),
		new ConditionXDiff(eps),
		new ConditionGrad(eps),
		new ConditionIter(count),
		new ConditionImprovement(count)
	};

	std::vector<vPoint> Result;

	std::vector<vPoint> FirstPoints;
	vPoint Point(2);

	Point[0] = 0; Point[1] = 0;
	FirstPoints.push_back(Point);

	Point[0] = -5; Point[1] = -5;
	FirstPoints.push_back(Point);

	Point[0] = 10; Point[1] = 20;
	FirstPoints.push_back(Point);

	//bool next = true;
	//std::string command;
	//while (next) {
	//	std::cin >> command;
	//	std::stringstream comm_stream(command);
	//	std::string buffer;

	//	comm_stream >> buffer;

	//	if (buffer == "exit") {
	//		next = false;
	//		break;
	//	}

	//	int func = 0;
	//	if (buffer == "F01") func = 0;
	//	if (buffer == "F02") func = 1;
	//	if (buffer == "F03") func = 2;
	//	if (buffer == "F04") func = 3;
	//	if (buffer == "F05") func = 4;

	//	comm_stream >> buffer;

	//	int area = 0;
	//	if (buffer == "Area0") area = 0;
	//	if (buffer == "Area1") area = 1;
	//	if (buffer == "Area2") area = 2;
	//	if (buffer == "Area3") area = 3;

	//	comm_stream >> buffer;

	//	int method = 0;
	//	if (buffer == "Nelder") method = 0;
	//	if (buffer == "Random") method = 1;

	//	comm_stream >> buffer;

	//	int cond = 0;
	//	if (buffer == "fDiff") cond = 0;
	//	if (buffer == "xDiff") cond = 1;
	//	if (buffer == "Grad") cond = 2;
	//	if (buffer == "Iter") cond = 3;
	//	if (buffer == "Improvement") cond = 4;

	//	comm_stream >> buffer;
	//	int first_point = 0;
	//	if (buffer == "Zero") first_point = 0;
	//	if (buffer == "(-5,-5)") first_point = 1;
	//	if (buffer == "(10,20)") first_point = 2;

	//	Result = OptMethods[0]->Optimize(Areas[0], Functions[0], Conditions[0], FirstPoints[0]);

	//	std::cout << (Result.back()) << std::endl;
	//}

	Result = OptMethods[0]->Optimize(Areas[0], Functions[0], Conditions[3], FirstPoints[0]);
	std::cout << "Result.size = " << Result.size() << std::endl;
	//std::cout << Result.back() << std::endl;
	//std::cout << ((ConditionIter*)Conditions[3])->GetMaxCount() << std::endl;
	system("pause");
	return 0;
}
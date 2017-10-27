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
#include "commands.h"

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
	Initialize();

	std::string command("");
	while(true) {
		std::cout << "> ";
		getline(std::cin, command);
		if (command == "exit") break;
		std::stringstream commstream(command);
		execute(commstream, Commands, Variables);
		std::cout << std::endl;
	}
}
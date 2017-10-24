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
	

	bool next = true;
	std::string command;
	while (next) {
		std::cin >> command;
		std::stringstream comm_stream(command);
		std::string buffer;

		comm_stream >> buffer;

		if (buffer == "exit") next = false;
		else if (buffer == "area") {
			comm_stream >> buffer;
			if (buffer == "set") {

			}
			else if (buffer == "get") {

			}
			else std::cout << "Incorrect command parameters" << std::endl;
		}
		else if (buffer == "function") {
			if (buffer == "set") {

			}
			else if (buffer == "get") {

			}
			else std::cout << "Incorrect command parameters" << std::endl;
		}
		else if (buffer == "method") {
			if (buffer == "set") {

			}
			else if (buffer == "get") {

			}
			else std::cout << "Incorrect command parameters" << std::endl;
		}
		else if (buffer == "condition") {
			if (buffer == "set") {

			}
			else if (buffer == "get") {

			}
			else std::cout << "Incorrect command parameters" << std::endl;
		}
		else if (buffer == "point") {

		}
		else if (buffer == "opt") {

		}
		else if (buffer == "") continue;
		else std::cout << "Unknown command" << std::endl;
	}

	system("pause");
	return 0;
}
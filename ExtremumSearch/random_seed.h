#pragma once

#include <random>

static std::random_device seed_gen;                ///< seed generator for the random number generator used in the program
static std::default_random_engine rng(seed_gen()); ///< random number generator that is used in the program

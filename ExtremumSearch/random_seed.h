#pragma once

#include <random>

static std::random_device seed_gen;
static std::default_random_engine rng(seed_gen());

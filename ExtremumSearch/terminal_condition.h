#pragma once

#include <vector>
#include <armadillo>

#include "custom_defines.h"
#include "function.h"
#include "area.h"

class TerminalCondition {
public:
    virtual bool Stop(const Function * F, const vPointSeq& Approx) const = 0;
};
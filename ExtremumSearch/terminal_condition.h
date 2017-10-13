#pragma once

#include <vector>

#include "function.h"
#include "area.h"
#include "vpoint.h"

class TerminalCondition {
public:
    virtual bool Stop(const Function * F, const std::vector<vPoint>& Approx) const = 0;
};
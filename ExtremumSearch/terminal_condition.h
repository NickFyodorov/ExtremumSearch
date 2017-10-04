#pragma once

#include <armadillo>

class TerminalCondition {
public:
    virtual bool Stop() const = 0;
};
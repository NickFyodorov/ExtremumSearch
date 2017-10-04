#include <vector>
#include "area.h"
#include "function.h"
#include "terminal_condition.h"

class OptimizationMethod {
private:
    Area * pArea;
    Function * pFunc;
    TerminalCondition * pTCond;
    vector<Point> Approx;
    int iteration;
public:
    OptimizationMethod(const Area& A, const Function& F, const TerminalCondition& T, const Point& FirstPoint);
    virtual ~OptimizationMethod();
    virtual bool NextIteration() const = 0;
    virtual char* Name() const = 0;
};
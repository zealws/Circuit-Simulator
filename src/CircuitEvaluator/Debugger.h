#ifndef __DEBUGGER_EVALUATOR__
#define __DEBUGGER_EVALUATOR__

#include "DelayCircuitIterator.h"
#include <vector>
using namespace std;

////
//// Debugger class
////

class Debugger : public DelayCircuitIterator {

protected:

    // Evaluate the current item
    virtual void Evaluate();

public:

    ~Debugger();

};

#endif

#ifndef __DELAY_EVALUATOR__
#define __DELAY_EVALUATOR__

#include "DelayCircuitIterator.h"
#include <vector>
using namespace std;

////
//// DelayEvaluator class
////

class DelayEvaluator : public DelayCircuitIterator {

protected:

    // Evaluate the current item
    virtual void Evaluate();

public:

    ~DelayEvaluator();

};

#endif

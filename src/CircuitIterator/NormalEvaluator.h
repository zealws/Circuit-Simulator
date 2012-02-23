#ifndef __NORMAL_EVALUATOR__
#define __NORMAL_EVALUATOR__

#include "CircuitIterator.h"
#include "BFSIterator.h"
#include <list>
using namespace std;

////
//// NormalEvaluator class
////

class NormalEvaluator : public BFSIterator {

protected:

    // Evaluate the current item
    virtual void EvaluateCurrentItem();

public:

    // Destructor
    virtual ~NormalEvaluator();

};

#endif

#ifndef __CIRCUIT_ITERATOR_H__
#define __CIRCUIT_ITERATOR_H__

#include "Circuit.h"
#include "Subcircuit.h"
#include "gc_cpp.h"

////
//// ABC CircuitIterator class
////

class CircuitIterator : public gc {

protected:

    // Are we done?
    virtual bool IsDone() = 0;

    // Evaluate the current item
    virtual void EvaluateCurrentItem() = 0;

    // Proceeds to the next item
    virtual void Progress() = 0;

    // Fetch the current item
    virtual Subcircuit* CurrentItem() = 0;

public:

    // Destructor
    virtual ~CircuitIterator();

    // Sets up iteration for a given circuit.
    virtual void Setup(Circuit&) = 0;

    // Iterate
    virtual void Iterate() = 0;

};

#endif /* __CIRCUIT_EVALUATOR_H__ */


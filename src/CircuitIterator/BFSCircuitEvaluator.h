#ifndef __BFS_CIRCUIT_EVALUATOR__
#define __BFS_CIRCUIT_EVALUATOR__

#include "CircuitIterator.h"
#include <list>
using namespace std;

////
//// BFSCircuitEvaluator class
////

class BFSCircuitEvaluator : public CircuitIterator {

private:

    list<CustomComponent*> toBeVisited;
    list<CustomComponent*> outputList;

    CustomComponent* myCurrItem;

    Circuit* myCircuit;

protected:

    // Returns whether or not a component occurs in outputList
    bool IsOutput(CustomComponent*);

    // Are we done?
    virtual bool IsDone();

    // Evaluate the current item
    virtual void EvaluateCurrentItem();

    // Proceeds to the next item
    virtual void Progress();

    // Fetch the current item
    virtual CustomComponent* CurrentItem();

    // Resets the simulator for the given circuit.
    void reset();

public:

    BFSCircuitEvaluator();

    // Destructor
    virtual ~BFSCircuitEvaluator();

    // Sets up iteration for a given circuit.
    virtual void Setup(Circuit&);

    // Iterate
    virtual void Iterate();

    // Clears the queue of items.
    void Clear();

};

#endif

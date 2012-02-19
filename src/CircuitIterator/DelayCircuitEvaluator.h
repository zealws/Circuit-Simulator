#ifndef __DELAY_CIRCUIT_EVALUATOR__
#define __DELAY_CIRCUIT_EVALUATOR__

#include "CircuitIterator.h"
#include <vector>
using namespace std;

////
//// DelayCircuitEvaluator class
////

class DelayCircuitEvaluator : public CircuitIterator {

private:

    // For the heap priority queue
    class pair {
    public:
        pair();
        pair(CustomComponent*, State::Timestamp);
        pair(State::Timestamp, CustomComponent*);
        CustomComponent* first;
        State::Timestamp second;

        // For comparison
        bool operator>(const pair&) const;
        bool operator<(const pair&) const;
    };

    // The nodes we have yet to visit
    vector<pair> toBeVisited;

    // The list of all the output components
    list<CustomComponent*> outputList;

    // The current item
    pair myCurrItem;

    // The circuit we're evaluating
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
    virtual State::Timestamp CurrentDelay();

    // Resets the simulator for the given circuit.
    void reset();

public:

    DelayCircuitEvaluator();

    // Destructor
    virtual ~DelayCircuitEvaluator();

    // Sets up iteration for a given circuit.
    virtual void Setup(Circuit&);

    // Iterate
    virtual void Iterate();

    // Clears the queue of items.
    void Clear();

};

#endif

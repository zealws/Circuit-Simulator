#ifndef __DELAY_CIRCUIT_ITERATOR__
#define __DELAY_CIRCUIT_ITERATOR__

#include "CircuitIterator.h"
#include <vector>
using namespace std;

////
//// DelayCircuitIterator class
////

class DelayCircuitIterator : public CircuitIterator {

protected:

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

private:

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
    virtual void EvaluateCurrentItem() = 0;

    // Proceeds to the next item
    virtual void Progress();

    // Fetch the current item
    virtual CustomComponent* CurrentItem();
    virtual State::Timestamp CurrentDelay();

    // Add a component to the queue
    virtual void AddComponent(CustomComponent*);
    virtual void enqueue(Wire*);

    // Resets the simulator for the given circuit.
    void reset();

public:

    // Destructor
    virtual ~DelayCircuitIterator();

    // Sets up iteration for a given circuit.
    virtual void Setup(Circuit&);

    // Iterate
    virtual void Iterate();

    // Clears the queue of items.
    void Clear();

};

#endif

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
    class triple {
    public:
        triple();
        triple(Wire*, State::Timestamp, State::Boolean);
        Wire* wire;
        State::Boolean value;
        State::Timestamp time;

        // For comparison
        bool operator>(const triple&) const;
        bool operator<(const triple&) const;
    };

private:

    // The nodes we have yet to visit
    vector<triple> toBeVisited;

    // The current item
    triple myCurrItem;

    // The circuit we're evaluating
    Circuit* myCircuit;

protected:

    // Are we done?
    virtual bool IsDone();

    // Evaluate the current item
    virtual void Evaluate() = 0;

    // Proceeds to the next item
    virtual void Progress();

    // Fetch the current item
    virtual CustomComponent* CurrentItem();
    virtual State::Timestamp CurrentDelay();

    // Add a component to the queue
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

#ifndef __CIRCUIT_REFRESHER__
#define __CIRCUIT_REFRESHER__

#include "CircuitIterator.h"

////
//// CircuitRefresher class
////

class CircuitRefresher : public CircuitIterator {

private:

    list<CustomComponent*> beenVisited;

    list<CustomComponent*> toBeVisited;

    CustomComponent* myCurrItem;

protected:

    // Are we done?
    virtual bool IsDone();

    // Evaluate the current item
    virtual void EvaluateCurrentItem();

    // Proceeds to the next item
    virtual void Progress();

    // Fetch the current item
    virtual CustomComponent* CurrentItem();

    // Add a component to the queue
    virtual void AddComponent(CustomComponent*);

public:

    CircuitRefresher();

    // Destructor
    virtual ~CircuitRefresher();

    // Sets up iteration for a given circuit.
    virtual void Setup(Circuit&);

    // Iterate
    virtual void Iterate();

    // Clears the queue of items.
    void Clear();

};

// Functional wrapper for CircuitRefresher
void RefreshCircuit(Circuit&);

#endif

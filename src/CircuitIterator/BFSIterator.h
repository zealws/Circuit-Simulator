#ifndef __BFS_ITERATOR__
#define __BFS_ITERATOR__

#include "CircuitIterator.h"
#include <list>
using namespace std;

////
//// BFSIterator class
////

class BFSIterator : public CircuitIterator {

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
    virtual void EvaluateCurrentItem() = 0;

    // Proceeds to the next item
    virtual void Progress();

    // Fetch the current item
    virtual CustomComponent* CurrentItem();

    // Resets the simulator for the given circuit.
    void reset();

    // Add a component to the queue
    virtual void AddComponent(CustomComponent*);

    // Removes instances all of a component from the queue
    virtual void RemoveComponent(CustomComponent*);

public:

    // Destructor
    virtual ~BFSIterator();

    // Sets up iteration for a given circuit.
    virtual void Setup(Circuit&);

    // Iterate
    virtual void Iterate();

    // Clears the queue of items.
    void Clear();

};

#endif

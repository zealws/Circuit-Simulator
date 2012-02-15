#include "BFSCircuitEvaluator.h"
#include "Exceptions.h"
#include "CircuitRefresher.h"
#include <iostream>
using namespace std;

////
//// BFSCircuitEvaluator class
////

// Are we done?
bool BFSCircuitEvaluator::IsDone() {
    return toBeVisited.empty() && myCurrItem == NULL;
}

// Evaluate the current item
void BFSCircuitEvaluator::EvaluateCurrentItem() {

    // Remove duplicates from the toBeVisited vector
    list<CustomComponent*>::iterator search = toBeVisited.begin();
    while(search != toBeVisited.end()) {
        if(*search == myCurrItem) {
            list<CustomComponent*>::iterator del = search;
            search++;
            toBeVisited.erase(del);
        }
        else {
            search++;
        }
    }

    list<CustomComponent*> updated = myCurrItem->EvaluateCustomComponent();

    while(not(updated.empty())) {
        CustomComponent* p = updated.front();
        toBeVisited.push_back(p);
        updated.pop_front();
    }
}

// Proceeds to the next item
void BFSCircuitEvaluator::Progress() {
    if(toBeVisited.empty()) {
        myCurrItem = NULL;
    }
    else {
        myCurrItem = toBeVisited.front();
        toBeVisited.pop_front();
    }
}

CustomComponent* BFSCircuitEvaluator::CurrentItem() {
    return myCurrItem;
}

// Resets the simulator for the given circuit.
void BFSCircuitEvaluator::reset() {
    Clear();
    toBeVisited = myCircuit->GetInputComponents();
    Progress();
}

BFSCircuitEvaluator::BFSCircuitEvaluator() {
    // Do Nothing
}

// Destructor
BFSCircuitEvaluator::~BFSCircuitEvaluator() {
    // Do Nothing
}

// Sets up iteration for a given circuit.
void BFSCircuitEvaluator::Setup(Circuit& toEvaluate) {
    myCircuit = &toEvaluate;
    reset();
}

// Iterate
void BFSCircuitEvaluator::Iterate() {
    reset();
    while(not IsDone()) {
        EvaluateCurrentItem();
        Progress();
    }
}

// Clears the queue of items.
void BFSCircuitEvaluator::Clear() {
    toBeVisited.clear();
    myCurrItem = NULL;
}

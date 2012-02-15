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
    list<Subcircuit*>::iterator search = toBeVisited.begin();
    while(search != toBeVisited.end()) {
        if(*search == myCurrItem) {
            list<Subcircuit*>::iterator del = search;
            search++;
            toBeVisited.erase(del);
        }
        else {
            search++;
        }
    }

    list<Subcircuit*> updated = myCurrItem->EvaluateSubcircuit();

    while(not(updated.empty())) {
        Subcircuit* p = updated.front();
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

Subcircuit* BFSCircuitEvaluator::CurrentItem() {
    return myCurrItem;
}

// Resets the simulator for the given circuit.
void BFSCircuitEvaluator::reset() {
    Clear();
    toBeVisited = myCircuit->GetInputSubcircuits();
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

// Functional wrapper for BFSCircuitEvaluator
void EvaluateCircuit(Circuit& c) {
    BFSCircuitEvaluator v;
    v.Setup(c);
    try {
        try {
            v.Iterate();
        } catch (SubcircuitError e) {
            cerr << "Circuit Evaluation failed. Circuit gave message:\n";
            cerr << "'" << e.text() << "' at Circuit '" << e.Offender()->GetSubcircuitName() << "'\n";
        }
    } catch (WireError e) {
        cerr << "Circuit Evaluation failed. Wire gave message:\n";
        cerr << "'" << e.text() << "' at wire between '" << e.Offender()->Prev()->GetSubcircuitName() << "' and '" << e.Offender()->Next()->GetSubcircuitName() << "'\n";
    }
    v.Clear();
}

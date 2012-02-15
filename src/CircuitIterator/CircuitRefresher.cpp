#include "CircuitRefresher.h"
#include "Exceptions.h"
#include <iostream>
using namespace std;

// Helper Function
// Removes all instances of a given item from a list
template<typename T>
void RemoveAll(T item, list<T>& lis) {
    list<T>::iterator search = lis.begin();
    while(search != lis.end()) {
        if(*search == item) {
            list<T>::iterator del = search;
            search++;
            lis.erase(del);
        }
        else {
            search++;
        }
    }
}


////
//// CircuitRefresher class
////

// Are we done?
bool CircuitRefresher::IsDone() {
    return toBeVisited.empty() && myCurrItem == NULL;
}

// Evaluate the current item
void CircuitRefresher::EvaluateCurrentItem() {
    vector<Wires*> nextWires = myCurrItem->getOutputWires();

    for(int i = 0; i < nextWires.size(); i++) {
        nextWires[i]->Refresh();
        toBeVisited.push_back(nextWires[i]->Next());
    }
}

// Proceeds to the next item
void CircuitRefresher::Progress() {
    beenVisited.push_back(myCurrItem);
    if(toBeVisited.empty()) {
        myCurrItem = NULL;
    }
    else {
        myCurrItem = toBeVisited.front();
        toBeVisited.pop_front();
    }

    RemoveAll(myCurrItem, toBeVisited);
    for(list<Subcircuit*>::iterator p = beenVisited.begin();
        p != beenVisited.end();
        p++) {
        RemoveAll(*p, toBeVisited);
    }
}

Subcircuit* CircuitRefresher::CurrentItem() {
    return myCurrItem;
}

CircuitRefresher::CircuitRefresher() {
    // Do Nothing
}

// Destructor
CircuitRefresher::~CircuitRefresher() {
    // Do Nothing
}

// Sets up iteration for a given circuit.
void CircuitRefresher::Setup(Circuit& toEvaluate) {
    toBeVisited = toEvaluate.GetInputSubcircuits();
    Progress();
}

// Iterate
void CircuitRefresher::Iterate() {
    while(not IsDone()) {
        EvaluateCurrentItem();
        Progress();
    }
}

// Clears the queue of items.
void CircuitRefresher::Clear() {
    toBeVisited.clear();
    beenVisited.clear();
    myCurrItem = NULL;
}

// Functional wrapper for CircuitRefresher
void RefreshCircuit(Circuit& c) {
    CircuitRefresher v;
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

#include "DelayCircuitIterator.h"
#include "CircuitSimulator.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
using namespace std;

////
//// DelayCircuitIterator class
////
DelayCircuitIterator::triple::triple()
    : wire(NULL), time(0), value(State::Down) {
    // Do Nothing
}
DelayCircuitIterator::triple::triple(Wire* w, State::Timestamp t, State::Boolean v)
    : wire(w), time(t), value(v) {
    // Do Nothing
}

// For comparison
bool DelayCircuitIterator::triple::operator>(const triple& other) const {
    return time > other.time;
}
bool DelayCircuitIterator::triple::operator<(const triple& other) const {
    return time < other.time;
}

// Are we done?
bool DelayCircuitIterator::IsDone() {
    return (toBeVisited.size() == 0) && myCurrItem.wire == NULL;
}

// Proceeds to the next item
void DelayCircuitIterator::Progress() {
    if(toBeVisited.size() == 0) {
        myCurrItem.wire = NULL;
    }
    else {
        myCurrItem = toBeVisited.front();
        pop_heap(toBeVisited.begin(), toBeVisited.end());
        toBeVisited.pop_back();
    }
}

CustomComponent* DelayCircuitIterator::CurrentItem() {
    return myCurrItem.wire->Next();
}

State::Timestamp DelayCircuitIterator::CurrentDelay() {
    return myCurrItem.time;
}

State::Boolean DelayCircuitIterator::CurrentValue() {
    return myCurrItem.value;
}

void DelayCircuitIterator::enqueue(Wire* p) {
    toBeVisited.push_back(triple(p, p->GetState().Time(), p->GetState().CurrentValue()));
    push_heap(toBeVisited.begin(), toBeVisited.end());
}

// Resets the simulator for the given circuit.
void DelayCircuitIterator::reset() {
    Clear();
    list<CustomComponent*> components = myCircuit->GetInputComponents();
    list<CustomComponent*>::iterator it = components.begin();
    while(it != components.end()) {
        // Since we do our traversal by wires now, we need some way to kickstart
        // the iteration with the input nodes. So we create "void" wires,
        // and make them lead to the input nodes.
        Wire* p = new Wire();
        p->SetOutputCircuit(*it, 0);
        toBeVisited.push_back(triple(p,0, State::Up));
        push_heap(toBeVisited.begin(), toBeVisited.end());
        it++;
    }
    Progress();
}

// Destructor
DelayCircuitIterator::~DelayCircuitIterator() {
    // Do Nothing
}

// Sets up iteration for a given circuit.
void DelayCircuitIterator::Setup(Circuit& toEvaluate) {
    myCircuit = &toEvaluate;
    reset();
}

// Iterate
void DelayCircuitIterator::Iterate() {
    reset();
    while(not IsDone()) {
        myCurrItem.wire->SetState(State(CurrentValue(), CurrentDelay()));
        if(myCurrItem.wire->ForcesEvaluation())
            Evaluate();
        Progress();
    }
}

// Clears the queue of items.
void DelayCircuitIterator::Clear() {
    toBeVisited.clear();
    myCurrItem.wire = NULL;
    myCurrItem.time = 0;
}

#include "DelayCircuitEvaluator.h"
#include "Exceptions.h"
#include "CircuitRefresher.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
using namespace std;

////
//// DelayCircuitEvaluator class
////
DelayCircuitEvaluator::pair::pair()
    : first(NULL), second(0) {
    // Do Nothing
}
DelayCircuitEvaluator::pair::pair(CustomComponent* f, State::Timestamp s)
    : first(f), second(s) {
    // Do Nothing
}
DelayCircuitEvaluator::pair::pair(State::Timestamp s, CustomComponent* f)
    : first(f), second(s) {
    // Do Nothing
}

// For comparison
bool DelayCircuitEvaluator::pair::operator>(const pair& other) const {
    return second > other.second;
}
bool DelayCircuitEvaluator::pair::operator<(const pair& other) const {
    return second < other.second;
}

// Returns whether or not a component occurs in outputList
bool DelayCircuitEvaluator::IsOutput(CustomComponent* search) {
    list<CustomComponent*>::iterator it = outputList.begin();
    while(it != outputList.end()) {
        if(*it == search)
            return true;
        else
            it++;
    }
    return false;
}

// Are we done?
bool DelayCircuitEvaluator::IsDone() {
    return (toBeVisited.size() == 0) && myCurrItem.first == NULL;
}

// Evaluate the current item
void DelayCircuitEvaluator::EvaluateCurrentItem() {

    list<Wire*> updated = myCurrItem.first->EvaluateCustomComponent();

    while(not(updated.empty())) {
        Wire* p = updated.front();
        toBeVisited.push_back(pair(p->Next(), p->GetState().Time()));
        push_heap(toBeVisited.begin(), toBeVisited.end());
        updated.pop_front();
    }
}

// Proceeds to the next item
void DelayCircuitEvaluator::Progress() {
    if(toBeVisited.size() == 0) {
        myCurrItem.first = NULL;
    }
    else {
        myCurrItem = toBeVisited.front();
        pop_heap(toBeVisited.begin(), toBeVisited.end());
        toBeVisited.pop_back();
    }
    if(IsOutput(myCurrItem.first)) {
        Progress();
    }
}

CustomComponent* DelayCircuitEvaluator::CurrentItem() {
    return myCurrItem.first;
}

State::Timestamp DelayCircuitEvaluator::CurrentDelay() {
    return myCurrItem.second;
}

// Resets the simulator for the given circuit.
void DelayCircuitEvaluator::reset() {
    Clear();
    list<CustomComponent*> components = myCircuit->GetInputComponents();
    outputList = myCircuit->GetOutputComponents();
    list<CustomComponent*>::iterator it = components.begin();
    while(it != components.end()) {
        toBeVisited.push_back(pair(*it,0));
        push_heap(toBeVisited.begin(), toBeVisited.end());
        it++;
    }
    Progress();
}

DelayCircuitEvaluator::DelayCircuitEvaluator() {
    // Do Nothing
}

// Destructor
DelayCircuitEvaluator::~DelayCircuitEvaluator() {
    // Do Nothing
}

// Sets up iteration for a given circuit.
void DelayCircuitEvaluator::Setup(Circuit& toEvaluate) {
    myCircuit = &toEvaluate;
    reset();
}

// Iterate
void DelayCircuitEvaluator::Iterate() {
    reset();
    while(not IsDone()) {
        EvaluateCurrentItem();
        Progress();
    }
    list<CustomComponent*>::iterator it = outputList.begin();
    while(it != outputList.end()) {
        (*it)->EvaluateCustomComponent();
        it++;
    }
}

// Clears the queue of items.
void DelayCircuitEvaluator::Clear() {
    toBeVisited.resize(0);
    myCurrItem.first = NULL;
    myCurrItem.second = 0;
}

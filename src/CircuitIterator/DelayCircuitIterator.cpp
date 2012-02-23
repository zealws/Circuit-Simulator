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
DelayCircuitIterator::pair::pair()
    : first(NULL), second(0) {
    // Do Nothing
}
DelayCircuitIterator::pair::pair(CustomComponent* f, State::Timestamp s)
    : first(f), second(s) {
    // Do Nothing
}
DelayCircuitIterator::pair::pair(State::Timestamp s, CustomComponent* f)
    : first(f), second(s) {
    // Do Nothing
}

// For comparison
bool DelayCircuitIterator::pair::operator>(const pair& other) const {
    return second > other.second;
}
bool DelayCircuitIterator::pair::operator<(const pair& other) const {
    return second < other.second;
}

// Returns whether or not a component occurs in outputList
bool DelayCircuitIterator::IsOutput(CustomComponent* search) {
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
bool DelayCircuitIterator::IsDone() {
    return (toBeVisited.size() == 0) && myCurrItem.first == NULL;
}

// Proceeds to the next item
void DelayCircuitIterator::Progress() {
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

CustomComponent* DelayCircuitIterator::CurrentItem() {
    return myCurrItem.first;
}

State::Timestamp DelayCircuitIterator::CurrentDelay() {
    return myCurrItem.second;
}

// Add a component to the queue
void DelayCircuitIterator::AddComponent(CustomComponent* p) {
    toBeVisited.push_back(pair(p, 0));
    push_heap(toBeVisited.begin(), toBeVisited.end());
}

void DelayCircuitIterator::enqueue(Wire* p) {
    toBeVisited.push_back(pair(p->Next(), p->GetState().Time()));
    push_heap(toBeVisited.begin(), toBeVisited.end());
}

// Resets the simulator for the given circuit.
void DelayCircuitIterator::reset() {
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
void DelayCircuitIterator::Clear() {
    toBeVisited.resize(0);
    myCurrItem.first = NULL;
    myCurrItem.second = 0;
}

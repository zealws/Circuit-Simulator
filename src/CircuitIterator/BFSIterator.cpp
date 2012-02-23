#include "BFSIterator.h"
#include "CircuitSimulator.h"
#include <iostream>
using namespace std;

////
//// BFSIterator class
////

// Returns whether or not a component occurs in outputList
bool BFSIterator::IsOutput(CustomComponent* search) {
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
bool BFSIterator::IsDone() {
    return toBeVisited.empty() && myCurrItem == NULL;
}

// Proceeds to the next item
void BFSIterator::Progress() {
    if(toBeVisited.empty()) {
        myCurrItem = NULL;
    }
    else {
        myCurrItem = toBeVisited.front();
        toBeVisited.pop_front();
    }
    if(IsOutput(myCurrItem)) {
        Progress();
    }

    // Remove duplicates from the toBeVisited lists
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
}


// Add a component to the queue
void BFSIterator::AddComponent(CustomComponent* p) {
    toBeVisited.push_back(p);
}

// Removes instances all of a component from the queue
void BFSIterator::RemoveComponent(CustomComponent* p) {
    list<CustomComponent*>::iterator search = toBeVisited.begin();
    while(search != toBeVisited.end()) {
        if(*search == p) {
            list<CustomComponent*>::iterator del = search;
            search++;
            toBeVisited.erase(del);
        }
        else {
            search++;
        }
    }
}

// Fetch the current item
CustomComponent* BFSIterator::CurrentItem() {
    return myCurrItem;
}

// Resets the simulator for the given circuit.
void BFSIterator::reset() {
    Clear();
    toBeVisited = myCircuit->GetInputComponents();
    outputList = myCircuit->GetOutputComponents();
    Progress();
}

// Destructor
BFSIterator::~BFSIterator() {
    // Do Nothing
}

// Sets up iteration for a given circuit.
void BFSIterator::Setup(Circuit& toEvaluate) {
    myCircuit = &toEvaluate;
    reset();
}

// Iterate
void BFSIterator::Iterate() {
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
void BFSIterator::Clear() {
    toBeVisited.clear();
    myCurrItem = NULL;
}

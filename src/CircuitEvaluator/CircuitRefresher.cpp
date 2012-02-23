#include "CircuitRefresher.h"
#include "CircuitSimulator.h"
#include <iostream>
using namespace std;

// Helper Function
// Removes all instances of a given item from a list
template<typename T>
bool Exists(T item, list<T>& lis) {
    typename list<T>::iterator search = lis.begin();
    while(search != lis.end()) {
        if(*search == item) {
            return true;
        }
        else {
            search++;
        }
    }
    return false;
}

////
//// CircuitRefresher class
////

// Evaluate the current item
void CircuitRefresher::Evaluate() {
    if(Exists(CurrentItem(), beenVisited)) {
        // Do Nothing
    }
    else {
        vector<Wire*> nextWires = CurrentItem()->GetOutputWires();

        for(int i = 0; i < nextWires.size(); i++) {
            nextWires[i]->Refresh();

            AddComponent(nextWires[i]->Next());
        }

        beenVisited.push_back(CurrentItem());
        RemoveComponent(CurrentItem());
    }
}

// Destructor
CircuitRefresher::~CircuitRefresher() {
    // Do Nothing
}

#include "Circuit.h"
#include "CustomComponent.h"
#include "WireState.h"
#include "Wire.h"
#include <cstdlib>
using namespace std;

////
//// Wire Class
////

// Constructor
// Create a wire with no output gate.
Wire::Wire()
    : beenUpdated(false), myState(), outputCircuit(NULL) {
    // Do Nothing
}

// Destructor
Wire::~Wire () {
    // Do Nothing
}

// Updates the state of the wire.
// Returns true if the wire's state was changed.
bool Wire::Update(WireState newState) {
    if(beenUpdated && myState == newState) {
        beenUpdated = true;
        return false;
    }
    else {
        myState = newState;
        beenUpdated = true;
        NotifyObservers();
        return true;
    }
}

// Sets the state without modifying beenUpdated or notifying observers.
bool Wire::SetState(WireState newState) {
    myState = newState;
}

// The output circuit of this wire.
CustomComponent* Wire::Next() {
    return outputCircuit;
}

// The input circuit of this wire.
CustomComponent* Wire::Prev() {
    return inputCircuit;
}

// Gets the state of the wire.
WireState Wire::State() const {
    return myState;
}

// Sets the output of this wire.
void Wire::SetOutputCircuit(CustomComponent* c) {
    outputCircuit = c;
}

// Sets the input of this wire.
void Wire::SetInputCircuit(CustomComponent* c) {
    inputCircuit = c;
}

// Refreshes the wire, so it will be freshly evaluated.
void Wire::Refresh() {
    beenUpdated = false;
}

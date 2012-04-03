#include "Circuit.h"
#include "CustomComponent.h"
#include "State.h"
#include "Wire.h"
#include <cstdlib>
using namespace std;

////
//// Wire Class
////

// Constructor
// Create a wire with no output gate.
Wire::Wire()
    : evaluationForced(true), beenUpdated(false), myState(), outputCircuit(NULL) {
    // Do Nothing
}

// Destructor
Wire::~Wire () {
    // Do Nothing
}

// Updates the state of the wire.
// Returns true if the wire's state was changed.
bool Wire::Update(State newState) {
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
bool Wire::SetState(State newState) {
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
State Wire::GetState() const {
    return myState;
}

// Sets the output of this wire.
void Wire::SetOutputCircuit(CustomComponent* c, int out) {
    outputCircuit = c;
    outputPin = out;
}

// Sets the input of this wire.
void Wire::SetInputCircuit(CustomComponent* c, int in) {
    inputCircuit = c;
    inputPin = in;
}

// Evaluation of this wire does not cause re-evaluation of it's output
// component. Used for busses.
void Wire::DoNotForceEvaluation() {
    evaluationForced = false;
}

// Does this wire force evaluation of it's output component?
bool Wire::ForcesEvaluation() {
    return evaluationForced;
}

// Refreshes the wire, so it will be freshly evaluated.
void Wire::Refresh() {
    beenUpdated = false;
}

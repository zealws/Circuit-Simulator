#include "CustomComponent.h"
#include "Circuit.h"
#include "Observable.h"
#include "Exceptions.h"
#include "Wire.h"
#include "WireState.h"
#include <cstdlib>
#include <sstream>
#include <iostream>
#include <vector>
using namespace std;

////
//// CustomComponent Class
////

// Constructor
CustomComponent::CustomComponent() {
    // Do Nothing
}

// Specifies the sizes of the input and output list, respectively
CustomComponent::CustomComponent(string id, int inSize, int outSize)
    : identifier(id) {
    inputWireList.resize(inSize, NULL);
    outputWireList.resize(outSize, NULL);
}

// Destructor
CustomComponent::~CustomComponent() {
    // Do Nothing
}

// Evaluate the CustomComponent
// Creates the state vectors for input/output
// Then calls Evaluate
// Then copies the output state vector to the output wires.
// Returns a list of all the CustomComponents that need to be evaluated.
list<CustomComponent*> CustomComponent::EvaluateCustomComponent() {

    // Create the input state vector
    vector<State::Boolean> inputStateList(inputWireList.size(), State::Boolean(false));
    for(int i = 0; i < inputStateList.size(); i++) {
        if(inputWireList[i] == NULL) {
            ostringstream s;
            s << "Missing input Wire on port " << i;
            throw ComponentError(s.str(), this);
        }
        inputStateList[i] = inputWireList[i]->GetState().CurrentValue();
    }

    // Create the output state vector
    vector<State::Boolean> outputStateList(outputWireList.size(), State::Boolean(false));

    list<CustomComponent*> updated;

    // Evaluate the CustomComponent
    Evaluate(inputStateList, outputStateList);
    // Record the changed time signature.
    State::Timestamp delta = Delay();

    // Now update each of the output wires.
    for(int i = 0; i < outputStateList.size(); i++) {
        // If the wire doesn't exist, something is wrong.
        if(outputWireList[i] == NULL) {
            ostringstream s;
            s << "Missing output Wire on port " << i;
            throw ComponentError(s.str(), this);
        }

        // If the wire's next doesn't exist, something is still wrong.
        else if(outputWireList[i]->Next() == NULL) {
            ostringstream s;
            s << "Missing Next Circuit on port " << i;
            throw ComponentError(s.str(), this);
        }

        // Finally, we update the wire.
        bool oldState = bool(outputWireList[i]->GetState());
        bool changed = outputWireList[i]->Update(State(outputStateList[i], delta));
        //cout << GetCustomComponentName() << "[" << i << "] updated from " << oldState << " to " << bool(outputWireList[i]->State()) << ".\n";

        // If it was actually changed, we mark the CustomComponent for evaluation.
        if(changed) {
            updated.push_back(outputWireList[i]->Next());
        }
    }

    return updated;
}

// Get Input Wires to this CustomComponent.
vector<Wire*> CustomComponent::getInputWires() {
    return inputWireList;
}

// Get Output Wires to this CustomComponent.
vector<Wire*> CustomComponent::getOutputWires() {
    return outputWireList;
}

// Sets an Input Wire
void CustomComponent::SetInputWire(Wire* w, int n) {
    inputWireList[n] = w;
}

// Sets an Output Wire
void CustomComponent::SetOutputWire(Wire* w, int n) {
    outputWireList[n] = w;
}

// Gets the name of the circuit
string CustomComponent::GetName() const {
    return identifier;
}

// Sets the name of the circuit
void CustomComponent::SetName(const string& newId) {
    identifier = newId;
}
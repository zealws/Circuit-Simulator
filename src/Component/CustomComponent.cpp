#include "CustomComponent.h"
#include "CircuitSimulator.h"
#include <cstdlib>
#include <sstream>
#include <iostream>
#include <vector>
using namespace std;

////
//// CustomComponent Class
////

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
list<Wire*> CustomComponent::EvaluateCustomComponent() {

    // Create the input state vector
    vector<State::Boolean> inputStateList(inputWireList.size(), State::Boolean(false));
    State::Timestamp latestChange = 0;
    for(int i = 0; i < inputStateList.size(); i++) {
        if(inputWireList[i]->GetState().Time() > latestChange) {
            latestChange = inputWireList[i]->GetState().Time();
        }
        if(inputWireList[i] == NULL) {
            ostringstream s;
            s << "Missing input Wire on port " << i;
            throw ComponentError(s.str(), this);
        }
        inputStateList[i] = inputWireList[i]->GetState().CurrentValue();
    }

    // Create the output state vector
    vector<State::Boolean> outputStateList(outputWireList.size(), State::Boolean(false));

    list<Wire*> updated;

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
        bool changed = outputWireList[i]->Update(State(outputStateList[i], latestChange = delta));

        // If it was actually changed, we mark the CustomComponent for evaluation.
        if(changed) {
            updated.push_back(outputWireList[i]);
        }
    }

    return updated;
}

// Get Input Wires to this CustomComponent.
vector<Wire*> CustomComponent::GetInputWires() {
    return inputWireList;
}

// Get Output Wires to this CustomComponent.
vector<Wire*> CustomComponent::GetOutputWires() {
    return outputWireList;
}

// Returns the input/output size of the component.
unsigned int CustomComponent::InputSize() {
    return inputWireList.size();
}
unsigned int CustomComponent::OutputSize() {
    return outputWireList.size();
}

// Sets an Input Wire
void CustomComponent::SetInputWire(Wire* w, int n) {
    if(n >= inputWireList.size()) {
        ostringstream s;
        s << identifier << " has no input port " << n;
        throw ComponentError(s.str(), this);
    }
    else {
        inputWireList[n] = w;
    }
}

// Sets an Output Wire
void CustomComponent::SetOutputWire(Wire* w, int n) {
    if(n >= outputWireList.size()) {
        ostringstream s;
        s << identifier << " has no output port " << n;
        throw ComponentError(s.str(), this);
    }
    else {
        outputWireList[n] = w;
    }
}

// Gets the name of the circuit
string CustomComponent::GetName() const {
    return identifier;
}

// Sets the name of the circuit
void CustomComponent::SetName(const string& newId) {
    identifier = newId;
}

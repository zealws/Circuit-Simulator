#include "Subcircuit.h"
#include "Circuit.h"
#include "Observable.h"
#include "Exceptions.h"
#include "Wire.h"
#include <cstdlib>
#include <sstream>
#include <iostream>
#include <vector>
using namespace std;

////
//// Subcircuit Class
////

// Constructor
Subcircuit::Subcircuit() {
    // Do Nothing
}

// Specifies the sizes of the input and output list, respectively
Subcircuit::Subcircuit(string id, int inSize, int outSize)
    : identifier(id) {
    inputWireList.resize(inSize, NULL);
    outputWireList.resize(outSize, NULL);
}

// Destructor
Subcircuit::~Subcircuit() {
    // Do Nothing
}

// Evaluate the Subcircuit
// Creates the state vectors for input/output
// Then calls Evaluate
// Then copies the output state vector to the output wires.
// Returns a list of all the subcircuits that need to be evaluated.
list<Subcircuit*> Subcircuit::EvaluateSubcircuit() {

    // Create the input state vector
    vector<State> inputStateList(inputWireList.size(), State(false));
    for(int i = 0; i < inputStateList.size(); i++) {
        if(inputWireList[i] == NULL) {
            ostringstream s;
            s << "Missing input Wire on port " << i;
            throw SubcircuitError(s.str(), this);
        }
        inputStateList[i] = inputWireList[i]->State().CurrentState();
    }

    // Create the output state vector
    vector<State> outputStateList(outputWireList.size(), State(false));

    list<Subcircuit*> updated;

    // Evaluate the subcircuit, recording the changed time signature.
    TimeStamp delta = Evaluate(inputStateList, outputStateList);

    // Now update each of the output wires.
    for(int i = 0; i < outputStateList.size(); i++) {
        // If the wire doesn't exist, something is wrong.
        if(outputWireList[i] == NULL) {
            ostringstream s;
            s << "Missing output Wire on port " << i;
            throw SubcircuitError(s.str(), this);
        }

        // If the wire's next doesn't exist, something is still wrong.
        else if(outputWireList[i]->Next() == NULL) {
            ostringstream s;
            s << "Missing Next Circuit on port " << i;
            throw SubcircuitError(s.str(), this);
        }

        // Finally, we update the wire.
        bool oldState = bool(outputWireList[i]->State());
        bool changed = outputWireList[i]->Update(WireState(outputStateList[i], delta));
        //cout << GetSubcircuitName() << "[" << i << "] updated from " << oldState << " to " << bool(outputWireList[i]->State()) << ".\n";

        // If it was actually changed, we mark the subcircuit for evaluation.
        if(changed) {
            updated.push_back(outputWireList[i]->Next());
        }
    }

    return updated;
}

// Get Input Wires to this Subcircuit.
vector<Wire*> Subcircuit::getInputWires() {
    return inputWireList;
}

// Get Output Wires to this Subcircuit.
vector<Wire*> Subcircuit::getOutputWires() {
    return outputWireList;
}

// Sets an Input Wire
void Subcircuit::SetInputWire(Wire* w, int n) {
    inputWireList[n] = w;
}

// Sets an Output Wire
void Subcircuit::SetOutputWire(Wire* w, int n) {
    outputWireList[n] = w;
}

// Gets the name of the circuit
string Subcircuit::GetSubcircuitName() const {
    return identifier;
}

// Sets the name of the circuit
void Subcircuit::SetSubcircuitName(const string& newId) {
    identifier = newId;
}
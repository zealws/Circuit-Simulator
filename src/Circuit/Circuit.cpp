#include "Circuit.h"
#include "CircuitSimulator.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <utility>
using namespace std;

////
//// Circuit Class
////

// Constructor
Circuit::Circuit() : simulateGateDelays(false) {
    // Do Nothing
}

// Destructor
Circuit::~Circuit () {
    // Do Nothing
}

// Links a circuit as an input gate of this circuit.
void Circuit::AddInput(Component c) {
    inputComponents.push_back(c.body());
}

void Circuit::AddInput(string id) {
    AddInput(Lookup(id));
}

// Links a subcircuit as an output gate of this circuit.
void Circuit::AddOutput(Component c) {
    outputComponents.push_back(c.body());
}

void Circuit::AddOutput(string id) {
    AddOutput(Lookup(id));
}

// Links an arbitrary component with an identifier.
void Circuit::AddComponent(string id, Component c) {
    components[id] = c;
    c.body()->SetName(c.body()->GetName() + ":" + id);
}

// Returns the input subcircuits
list<CustomComponent*> Circuit::GetInputComponents() const {
    return inputComponents;
}

// Returns the output subcircuits
list<CustomComponent*> Circuit::GetOutputComponents() const {
    return outputComponents;
}

// Returns the component with the given identifier.
Component Circuit::Lookup(string id) {
    return components[id];
}

// Links two circuits with a wire.
// Uses the specified input and output wire numbers.
void Circuit::Connect(Component in, unsigned int inNo, Component out, unsigned int outNo, bool initWireState) {
    Wire* p = new Wire();
    in.body()->SetOutputWire(p, inNo);
    out.body()->SetInputWire(p, outNo);
    p->SetOutputCircuit(out.body());
    p->SetInputCircuit(in.body());
    p->SetState(State(State::Boolean(initWireState), 0));
    p->AttachObserver(new UpdateCounter());
}

// Links two components in this circuit.
void Circuit::Connect(string inId, unsigned int inNo, string outId, unsigned int outNo, bool initWireState) {
    Connect(Lookup(inId), inNo, Lookup(outId), outNo, initWireState);
}

// Evaluates the circuit
void Circuit::Evaluate() {
    if(simulateGateDelays) {
        DelayEvaluator v;
        v.Setup(*this);
        try {
            try {
                v.Iterate();
            } catch (ComponentError e) {
                cerr << "Circuit Evaluation failed. Circuit gave message:\n";
                cerr << "'" << e.text() << "' at Circuit '" << e.Offender()->GetName() << "'\n";
            }
        } catch (WireError e) {
            cerr << "Circuit Evaluation failed. Wire gave message:\n";
            cerr << "'" << e.text() << "' at wire between '" << e.Offender()->Prev()->GetName() << "' and '" << e.Offender()->Next()->GetName() << "'\n";
        }
        v.Clear();
    }
    else {
        NormalEvaluator v;
        v.Setup(*this);
        try {
            try {
                v.Iterate();
            } catch (ComponentError e) {
                cerr << "Circuit Evaluation failed. Circuit gave message:\n";
                cerr << "'" << e.text() << "' at Circuit '" << e.Offender()->GetName() << "'\n";
            }
        } catch (WireError e) {
            cerr << "Circuit Evaluation failed. Wire gave message:\n";
            cerr << "'" << e.text() << "' at wire between '" << e.Offender()->Prev()->GetName() << "' and '" << e.Offender()->Next()->GetName() << "'\n";
        }
        v.Clear();
    }
}

// Toggle gate delays
void Circuit::UseGateDelays() {
    simulateGateDelays = true;
}
void Circuit::IgnoreGateDelays() {
    simulateGateDelays = false;
}

// Copies a circuit's output components's states to a vector:
void Circuit::PushOutput(vector<State::Boolean>& output) {
    list<CustomComponent*>::iterator it(outputComponents.begin());
    for(int i = 0; i < output.size(); i++) {
        CircuitOutput* out = dynamic_cast<CircuitOutput*>(*it);
        output[i] = out->GetState();
        it++;
    }
}

// Provides input to the circuit from a vector:
void Circuit::PullInput(const vector<State::Boolean>& input) {
    list<CustomComponent*>::iterator it(inputComponents.begin());
    for(int i = 0; i < input.size(); i++) {
        CircuitInput* in = dynamic_cast<CircuitInput*>(*it);
        in->SetState(input[i]);
        it++;
    }
}

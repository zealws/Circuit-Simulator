#include "Circuit.h"
#include "CustomComponent.h"
#include "UpdateCounter.h"
#include "BFSCircuitEvaluator.h"
#include "Exceptions.h"
#include "Component.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <utility>
using namespace std;

////
//// Circuit Class
////

// Helper Function to add a component pair
void Circuit::AddComponent(string id,Component c) {
    components[id.data()] = c;
}

// Constructor
Circuit::Circuit() {
    // Do Nothing
}

// Destructor
Circuit::~Circuit () {
    // Do Nothing
}

// Links a circuit as an input gate of this circuit.
void Circuit::LinkInput(Component c) {
    inputSubcircuits.push_back(c.body());
}

void Circuit::LinkInput(CustomComponent* c) {
    inputSubcircuits.push_back(c);
}

void Circuit::LinkInput(string id) {
    LinkInput(Lookup(id));
}

// Links a subcircuit as an output gate of this circuit.
void Circuit::LinkOutput(Component c) {
    outputComponents.push_back(c.body());
}

void Circuit::LinkOutput(CustomComponent* c) {
    outputComponents.push_back(c);
}

void Circuit::LinkOutput(string id) {
    LinkOutput(Lookup(id));
}

// Links an arbitrary component with an identifier.
void Circuit::Link(string id, Component c) {
    AddComponent(id,c);
    c.body()->SetName(c.body()->GetName() + ":" + id);
}

// Returns the input subcircuits
list<CustomComponent*> Circuit::GetInputComponents() const {
    return inputSubcircuits;
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
void Circuit::LinkWithWire(Component in, int inNo, Component out, int outNo, bool initWireState) {
    Wire* p = new Wire();
    in.body()->SetOutputWire(p, inNo);
    out.body()->SetInputWire(p, outNo);
    p->SetOutputCircuit(out.body());
    p->SetInputCircuit(in.body());
    p->SetState(WireState(State(initWireState), 0));
    p->AttachObserver(new UpdateCounter());
}

// Links two components in this circuit.
void Circuit::LinkWithWire(string inId, int inNo, string outId, int outNo, bool initWireState) {
    LinkWithWire(Lookup(inId), inNo, Lookup(outId), outNo, initWireState);
}

// Evaluates the circuit
void Circuit::Evaluate() {
    BFSCircuitEvaluator v;
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

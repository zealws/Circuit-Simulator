#include "Circuit.h"
#include "Subcircuit.h"
#include "UpdateCounter.h"
#include "Component.h"
#include <string>
#include <cstdlib>
#include <utility>
using namespace std;

////
//// Circuit Class
////

// For comparing pairs, so I can use std::list's built-in sort operation.
bool Circuit::compare_subcircuit_pairs(pair<string,Component> first,
                                       pair<string,Component> second) {
    return first.first < second.first;
}

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

void Circuit::LinkInput(Subcircuit* c) {
    inputSubcircuits.push_back(c);
}

void Circuit::LinkInput(string id, Subcircuit* c) {
    inputSubcircuits.push_back(c);
    AddComponent(id,Component(c));
    c->SetSubcircuitName(c->GetSubcircuitName() + ":" + id);
}

void Circuit::LinkInput(string id, Component c) {
    inputSubcircuits.push_back(c.body());
    AddComponent(id,c);
    c.body()->SetSubcircuitName(c.body()->GetSubcircuitName() + ":" + id);
}

// Links a subcircuit as an output gate of this circuit.
void Circuit::LinkOutput(Component c) {
    outputComponents.push_back(c.body());
}

void Circuit::LinkOutput(Subcircuit* c) {
    outputComponents.push_back(c);
}

void Circuit::LinkOutput(string id, Subcircuit* c) {
    outputComponents.push_back(c);
    AddComponent(id,Component(c));
    c->SetSubcircuitName(c->GetSubcircuitName() + ":" + id);
}

void Circuit::LinkOutput(string id, Component c) {
    outputComponents.push_back(c.body());
    AddComponent(id,c);
    c.body()->SetSubcircuitName(c.body()->GetSubcircuitName() + ":" + id);
}

// Links an arbitrary component with an identifier.
void Circuit::Link(string id, Component c) {
    AddComponent(id,c);
    c.body()->SetSubcircuitName(c.body()->GetSubcircuitName() + ":" + id);
}

// Returns the input subcircuits
list<Subcircuit*> Circuit::GetInputSubcircuits() const {
    return inputSubcircuits;
}

// Returns the output subcircuits
list<Subcircuit*> Circuit::GetOutputSubcircuits() const {
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
#include "Circuit.h"
#include "Subcircuit.h"
#include "UpdateCounter.h"
#include <string>
#include <cstdlib>
#include <utility>
using namespace std;

////
//// Circuit Class
////

// For comparing pairs, so I can use std::list's built-in sort operation.
bool Circuit::compare_subcircuit_pairs(pair<string,Subcircuit*> first,
                                       pair<string,Subcircuit*> second) {
    return first.first < second.first;
}

void Circuit::LinkOutput(Subcircuit* c) {
    outputSubcircuits.push_back(c);
}

void Circuit::LinkInput(Subcircuit* c) {
    inputSubcircuits.push_back(c);
}

// Helper Function to add a component pair
void Circuit::AddComponent(string id,Subcircuit* c) {
    components[id.data()] = c;
}

// Constructor
Circuit::Circuit()
    : bodyRef(NULL) {
    // Do Nothing
}

// Creates a top-level circuit from a Subcircuit
Circuit::Circuit(Subcircuit& c)
    : bodyRef(&c) {
    // Do Nothing
}

Circuit::Circuit(const string& id, Subcircuit* c)
    : bodyRef(c) {
    bodyRef->SetSubcircuitName(bodyRef->GetSubcircuitName() + ":" + id);
}

// Destructor
Circuit::~Circuit () {
    // Do Nothing
}

// Returns the body of this circuit.
Subcircuit* Circuit::body() {
    return bodyRef;
}

// Links a circuit as an input gate of this circuit.
/*void Circuit::LinkInput(Circuit& c) { // deprecated
    inputSubcircuits.push_back(c.body());
}*/

void Circuit::LinkInput(string id,Subcircuit* c) {
    LinkInput(c);
    AddComponent(id,c);
    c->SetSubcircuitName(c->GetSubcircuitName() + ":" + id);
}

// Links a subcircuit as an output gate of this circuit.
/*void Circuit::LinkOutput(Circuit& c) { // deprecated
    outputSubcircuits.push_back(c.body());
}*/

void Circuit::LinkOutput(string id,Subcircuit* c) {
    LinkOutput(c);
    AddComponent(id,c);
    c->SetSubcircuitName(c->GetSubcircuitName() + ":" + id);
}

// Links an arbitrary component with an identifier.
void Circuit::Link(string id, Subcircuit* c) {
    AddComponent(id,c);
    c->SetSubcircuitName(c->GetSubcircuitName() + ":" + id);
}

// Returns the input subcircuits
list<Subcircuit*> Circuit::GetInputSubcircuits() const {
    return inputSubcircuits;
}

// Returns the output subcircuits
list<Subcircuit*> Circuit::GetOutputSubcircuits() const {
    return outputSubcircuits;
}

// Returns the component with the given identifier.
Subcircuit* Circuit::Lookup(const string& id) {
    return components[id];
}

// Links two circuits with a wire.
// Uses the specified input and output wire numbers.
void Circuit::LinkWithWire(Subcircuit* in, int inNo, Subcircuit* out, int outNo, bool initWireState) {
    Wire* p = new Wire();
    in->SetOutputWire(p, inNo);
    out->SetInputWire(p, outNo);
    p->SetOutputCircuit(out);
    p->SetInputCircuit(in);
    p->SetState(WireState(State(initWireState), 0));
    p->AttachObserver(new UpdateCounter());
}

void Circuit::LinkWithWire(Subcircuit& in, int inNo, Subcircuit& out, int outNo, bool initWireState) {
    LinkWithWire(&in, inNo, &out, outNo, initWireState);
}

void Circuit::LinkWithWire(Circuit& in, int inNo, Circuit& out, int outNo, bool initWireState) {
    LinkWithWire(in.body(), inNo, out.body(), outNo, initWireState);
}

// Links two components in this circuit.
void Circuit::LinkWithWire(string inId, int inNo, string outId, int outNo, bool initWireState) {
    LinkWithWire(Lookup(inId), inNo, Lookup(outId), outNo, initWireState);
}
#include "Component.h"
#include "Subcircuit.h"
#include <string>
using namespace std;

////
//// Component Class
////

// Constructor
Component::Component()
    : bodyRef(NULL) {
    // Do Nothing
}

// Creates a top-level circuit from a Subcircuit
Component::Component(Subcircuit* c)
    : bodyRef(c) {
    // Do Nothing
}

Component::Component(const string& id, Subcircuit* c)
    : bodyRef(c) {
    bodyRef->SetSubcircuitName(bodyRef->GetSubcircuitName() + ":" + id);
}

// Destructor
Component::~Component () {
    // Do Nothing
}

// Returns the body of this circuit.
Subcircuit* Component::body() {
    return bodyRef;
}
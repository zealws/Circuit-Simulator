#include "Component.h"
#include "CustomComponent.h"
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
Component::Component(CustomComponent* c)
    : bodyRef(c) {
    // Do Nothing
}

Component::Component(const string& id, CustomComponent* c)
    : bodyRef(c) {
    bodyRef->SetName(bodyRef->GetName() + ":" + id);
}

// Destructor
Component::~Component () {
    // Do Nothing
}

// Returns the body of this circuit.
CustomComponent* Component::body() {
    return bodyRef;
}

#include "CustomComponent.h"
#include "ComponentError.h"

// Creates an Error, with a given message and the offending wire.
ComponentError::ComponentError(string msg, CustomComponent* c)
    : CircuitEvalError(msg), offendingCircuit(c) {
}

// Returns the offending wire of the error.
CustomComponent* ComponentError::Offender() {
    return offendingCircuit;
}

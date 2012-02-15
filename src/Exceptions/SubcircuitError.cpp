#include "Subcircuit.h"
#include "SubcircuitError.h"

// Creates an Error, with a given message and the offending wire.
SubcircuitError::SubcircuitError(string msg, Subcircuit* c)
    : CircuitEvalError(msg), offendingCircuit(c) {
}

// Returns the offending wire of the error.
Subcircuit* SubcircuitError::Offender() {
    return offendingCircuit;
}

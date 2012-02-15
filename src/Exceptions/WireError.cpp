#include "WireError.h"

// Creates an Error, with a given message and the offending wire.
WireError::WireError(string msg, Wire* w)
    : CircuitEvalError(msg), offendingWire(w) {
    // Do Nothing
}

// Returns the offending wire of the error.
Wire* WireError::Offender() {
    return offendingWire;
}

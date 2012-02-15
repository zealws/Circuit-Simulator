#ifndef __SUBCIRCUIT_ERROR_H__
#define __SUBCIRCUIT_ERROR_H__

#include "CircuitEvalError.h"
#include "Subcircuit.h"

class SubcircuitError : public CircuitEvalError {
private:

    Subcircuit* offendingCircuit;

public:

    // Creates an Error, with a given message and the offending wire.
    SubcircuitError(string, Subcircuit*);

    // Returns the offending wire of the error.
    Subcircuit* Offender();

};

#endif

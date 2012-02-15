#ifndef __WIRE_ERROR_H__
#define __WIRE_ERROR_H__

#include "CircuitEvalError.h"
#include "Wire.h"

class WireError : public CircuitEvalError {
private:

    Wire* offendingWire;

public:

    // Creates an Error, with a given message and the offending wire.
    WireError(string, Wire*);

    // Returns the offending wire of the error.
    Wire* Offender();

};

#endif

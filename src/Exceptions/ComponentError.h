#ifndef __Component_ERROR_H__
#define __Component_ERROR_H__

#include "CircuitEvalError.h"
#include "CustomComponent.h"

class ComponentError : public CircuitEvalError {
private:

    CustomComponent* offendingCircuit;

public:

    // Creates an Error, with a given message and the offending wire.
    ComponentError(string, CustomComponent*);

    // Returns the offending wire of the error.
    CustomComponent* Offender();

};

#endif

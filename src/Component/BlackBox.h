#ifndef __BLACK_BOX_H__
#define __BLACK_BOX_H__

#include "CustomComponent.h"
#include "Circuit.h"
#include <string>

////
//// BlackBox Class Definition
////

class BlackBox : public CustomComponent {

private:

    // The internal circuit.
    Circuit internalCircuit;

protected:

    // Returns the internal circuit.
    Circuit& internal();

    // Evaluates the Subcircuit with certain states.
    void Evaluate(const vector<State::Boolean>& inputStates, vector<State::Boolean>& outputStates);

public:

    // Constructor
    BlackBox(string, int, int);

};

#endif

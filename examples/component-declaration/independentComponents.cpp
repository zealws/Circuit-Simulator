#include <iostream>
#include "CircuitSimulator.h"

////
//// Example of the circuit simulator that uses
//// Components and does not link them into the circuit.
////

int main() {

    // Create the top-level circuit.
    Circuit topLevel;

    // In this example, the top level circuit does nothing except
    // store the input and output components for the circuit for later use during evaluation.

    // Create the components.
    Component in(new BitVectorInput(2));
    Component SR(new SRlatch());
    Component out(new BitVectorOutput(2));

    // Link the components.
    topLevel.Connect(in,0,SR,0);
    topLevel.Connect(in,1,SR,1);
    topLevel.Connect(SR,0,out,0);
    topLevel.Connect(SR,1,out,1);

    // Specify the input (and output) components.
    topLevel.AddInput(in);
    topLevel.AddOutput(out);

    // Evaluate the circuit.
    topLevel.Evaluate();

    return 0;
}

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
    Component in1(new Button());
    Component in2(new Button());
    Component SR(new SRlatch());
    Component out1(new LED());
    Component out2(new LED());

    // Link the components.
    topLevel.Connect(in1,0,SR,0);
    topLevel.Connect(in2,1,SR,1);
    topLevel.Connect(SR,0,out1,0);
    topLevel.Connect(SR,1,out2,1);

    // Specify the input (and output) components.
    topLevel.AddInput(in1);
    topLevel.AddInput(in2);
    topLevel.AddOutput(out1);
    topLevel.AddOutput(out2);

    // Evaluate the circuit.
    topLevel.Evaluate();

    return 0;
}

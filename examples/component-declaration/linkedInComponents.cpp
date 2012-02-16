#include <iostream>
#include "CircuitSimulator.h"

////
//// Example of the circuit simulator that uses
//// Subcircuit*s and  links them into the hash of the top-level circuit.
////

int main() {

    // Create the top-level circuit
    Circuit topLevel;

    // In this example, we use this to store information about the components that
    // are in the circuit, rather than just the input and output components.

    // Create the components.
    topLevel.AddComponent("in", new BitVectorInput(2));
    topLevel.AddComponent("SR", new SRlatch());
    topLevel.AddComponent("out", new BitVectorOutput(2));

    // Link the components.
    topLevel.Connect("in",0,"SR",0);
    topLevel.Connect("in",1,"SR",1);
    topLevel.Connect("SR",0,"out",0);
    topLevel.Connect("SR",1,"out",1);

    // Specify the input (and output) components.
    topLevel.AddInput("in");
    topLevel.AddOutput("out");

    // Evaluate the circuit.
    topLevel.Evaluate();

    return 0;
}

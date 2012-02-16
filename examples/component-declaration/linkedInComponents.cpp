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
    topLevel.Link("in", new BitVectorInput(2));
    topLevel.Link("SR", new SRlatch());
    topLevel.Link("out", new BitVectorOutput(2));

    // Link the components.
    topLevel.LinkWithWire("in",0,"SR",0);
    topLevel.LinkWithWire("in",1,"SR",1);
    topLevel.LinkWithWire("SR",0,"out",0);
    topLevel.LinkWithWire("SR",1,"out",1);

    // Specify the input (and output) components.
    topLevel.LinkInput("in");
    topLevel.LinkOutput("out");

    // Evaluate the circuit.
    topLevel.Evaluate();

    return 0;
}

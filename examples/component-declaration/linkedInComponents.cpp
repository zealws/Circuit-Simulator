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
    topLevel.AddComponent("in1", new Button());
    topLevel.AddComponent("in2", new Button());
    topLevel.AddComponent("SR", new SRlatch());
    topLevel.AddComponent("out1", new LED());
    topLevel.AddComponent("out2", new LED());

    // Link the components.
    topLevel.Connect("in1",0,"SR",0);
    topLevel.Connect("in2",1,"SR",1);
    topLevel.Connect("SR",0,"out1",0);
    topLevel.Connect("SR",1,"out2",1);

    // Specify the input (and output) components.
    topLevel.AddInput("in1");
    topLevel.AddInput("in2");
    topLevel.AddOutput("out1");
    topLevel.AddOutput("out2");

    // Evaluate the circuit.
    topLevel.Evaluate();

    return 0;
}

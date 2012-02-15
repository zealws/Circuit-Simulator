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
    topLevel.Link("circuitInput", new Button());
    topLevel.Link("orGate", new Or());
    topLevel.Link("notGate", new Not());
    topLevel.Link("orGateSplitter", new Splitter(2));
    topLevel.Link("circuitOutput", new LED());

    // Link the components.
    topLevel.LinkWithWire("circuitInput",0,"orGate",0);
    topLevel.LinkWithWire("orGate",0,"orGateSplitter",0,true);
    topLevel.LinkWithWire("orGateSplitter",0,"circuitOutput",0,true);
    topLevel.LinkWithWire("orGateSplitter",1,"notGate",0,true);
    topLevel.LinkWithWire("notGate",0,"orGate",1,false);

    // Specify the input (and output) components.
    topLevel.LinkInput("circuitInput");
    topLevel.LinkOutput("circuitOutput");

    // Evaluate the circuit.
    topLevel.Evaluate();

    return 0;
}
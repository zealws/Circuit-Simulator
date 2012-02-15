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
    Component in(new Button());
    Component _or(new Or());
    Component _not(new Not());
    Component spl(new Splitter(2));
    Component out(new LED());

    // Link the components.
    topLevel.LinkWithWire(in,0,_or,0);
    topLevel.LinkWithWire(_or,0,spl,0,true);
    topLevel.LinkWithWire(spl,0,out,0,true);
    topLevel.LinkWithWire(spl,1,_not,0,true);
    topLevel.LinkWithWire(_not,0,_or,1,false);

    // Specify the input (and output) components.
    topLevel.LinkInput(in);
    topLevel.LinkOutput(out);

    // Evaluate the circuit.
    topLevel.Evaluate();

    return 0;
}

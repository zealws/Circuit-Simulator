#include <iostream>
#include "CircuitSimulator.h"

////
//// Example of the circuit simulator that links components
//// into the hash of the top-level circuit.
////

int main() {

    // Create the top-level circuit
    Circuit topLevel;

    // In this example, we use this to store information about the components that
    // are in the circuit, rather than just the input and output components.

    // Create the components.
    topLevel.Link("in1", new Button());
    topLevel.Link("in2", new Button());
    topLevel.Link("or1", new Or());
    topLevel.Link("or2", new Or());
    topLevel.Link("not1", new Not());
    topLevel.Link("not2", new Not());
    topLevel.Link("spl1", new Splitter(2));
    topLevel.Link("spl2", new Splitter(2));
    topLevel.Link("out1", new LED());
    topLevel.Link("out2", new LED());

    // Connect the buttons
    topLevel.LinkWithWire("in1",0,"or1",0);
    topLevel.LinkWithWire("in2",0,"or1",1);

    // Connect the or's to the splitters
    topLevel.LinkWithWire("or1",0,"spl1",0);
    topLevel.LinkWithWire("or2",0,"spl2",0);

    // Connect Splitter1
    topLevel.LinkWithWire("spl1",0,"out1",0);
    topLevel.LinkWithWire("spl1",1,"not1",0);

    // Connect Splitter2
    topLevel.LinkWithWire("spl2",0,"out2",0);
    topLevel.LinkWithWire("spl2",1,"not2",0);

    // Connect the not's
    topLevel.LinkWithWire("not1",0,"or2",0);
    topLevel.LinkWithWire("not2",0,"or2",1);

    // Notify the circuit of it's input gates.
    topLevel.LinkInput("in1");
    topLevel.LinkInput("in2");
    topLevel.LinkOutput("out1");
    topLevel.LinkOutput("out2");

    // Evaluate the circuit.
    topLevel.Evaluate();

    return 0;
}

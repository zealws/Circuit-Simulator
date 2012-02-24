#include "CircuitSimulator.h"

////
//// Example an edge trigger using linked-in components.
////

int main() {

    // Create the top-level circuit
    Circuit topLevel;

    // Create the components.
    topLevel.AddComponent("in", new Button());
    topLevel.AddComponent("spl", new Splitter(2));
    topLevel.AddComponent("and", new And());
    topLevel.AddComponent("not", new Not());
    topLevel.AddComponent("out", new LED());

    // Link the components.
    topLevel.Connect("in",0,"spl",0);
    topLevel.Connect("spl",0,"and",0);
    topLevel.Connect("spl",1,"not",0);
    topLevel.Connect("not",0,"and",1);
    topLevel.Connect("and",0,"out",0);

    // Specify the input and output components.
    topLevel.AddInput("in");
    topLevel.AddOutput("out");

    // Evaluate the circuit.
    topLevel.Evaluate();

    return 0;
}

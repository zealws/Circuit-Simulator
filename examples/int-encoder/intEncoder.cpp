#include "CircuitSimulator.h"

////
//// Example an input encoder
////

int main() {

    // Create the top-level circuit
    Circuit topLevel;

    // Create the components.
    topLevel.AddComponent("in", new InputEncoder<int>());
    topLevel.AddComponent("out", new BitVectorOutput(sizeof(int)*8));

    // Link the components.
    topLevel.ConnectBus("in",0,"out",0, sizeof(int)*8);

    // Specify the input and output components.
    topLevel.AddInput("in");
    topLevel.AddOutput("out");

    // Evaluate the circuit.
    topLevel.Evaluate();

    return 0;
}

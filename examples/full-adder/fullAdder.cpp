#include "CircuitSimulator.h"

////
//// Example a full adder
////

int main() {

    Circuit topLevel;

    try {

        topLevel.AddComponent("in", new BitVectorInput(5));
        topLevel.AddComponent("out", new BitVectorOutput(5));

        topLevel.Connect("in", 0, "out", 0);

        topLevel.AddInput("in");
        topLevel.AddOutput("out");

        topLevel.Evaluate();

    }

    catch (ComponentError e) {
        cout << e.text() << endl;
    }

    return 0;
}

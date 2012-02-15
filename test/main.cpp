#include <iostream>
#include "CircuitSimulator.h"

int main() {

    Circuit topLevel;
    topLevel.LinkInput("in", new BitVectorInput(2));
    topLevel.Link("SR", new SRlatch());
    topLevel.LinkOutput("out", new BitVectorOutput(2));

    topLevel.LinkWithWire("in",0,"SR",0);
    topLevel.LinkWithWire("in",1,"SR",1);
    topLevel.LinkWithWire("SR",0,"out",0);
    topLevel.LinkWithWire("SR",1,"out",1);

    EvaluateCircuit(topLevel);

    return 0;
}

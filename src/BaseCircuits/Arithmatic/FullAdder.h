#ifndef __FullAdder_H__
#define __FullAdder_H__

#include "CircuitSimulator.h"

////
//// FullAdder
////

class FullAdder : public BlackBox {

protected:

    // Returns the delay of the component
    State::Timestamp Delay() {
        return 10;
    }

public:

    // Q's initial output state is false.
    // q's initial output state is true.

    // Constructor
    FullAdder()
        : BlackBox("FullAdder", 3, 2)
        {

        // Create the components.
        internal().AddComponent("A", new Button());
        internal().AddComponent("B", new Button());
        internal().AddComponent("Cin", new Button());
        internal().AddComponent("Cout", new LED());
        internal().AddComponent("S", new LED());
        internal().AddComponent("Xor1", new Xor());
        internal().AddComponent("Xor2", new Xor());
        internal().AddComponent("Or", new Or());
        internal().AddComponent("And1", new And());
        internal().AddComponent("And2", new And());
        internal().AddComponent("S1", new Splitter(2));
        internal().AddComponent("S2", new Splitter(2));
        internal().AddComponent("S3", new Splitter(2));
        internal().AddComponent("S4", new Splitter(2));

        // Specify the input and output components.
        internal().AddInput("A");
        internal().AddInput("B");
        internal().AddInput("Cin");
        internal().AddOutput("S");
        internal().AddOutput("Cout");

        // Link the components.

        // Link the splitters
        internal().Connect("A", 0, "S1", 0);
        internal().Connect("B", 0, "S2", 0);
        internal().Connect("Xor1", 0, "S3", 0);
        internal().Connect("Cin", 0, "S4", 0);

        // Link the Xors
        internal().Connect("S1", 0, "Xor1", 0);
        internal().Connect("S2", 0, "Xor1", 1);
        internal().Connect("S3", 0, "Xor2", 0);
        internal().Connect("S4", 0, "Xor2", 1);

        // Link the Ands
        internal().Connect("S1", 1, "And2", 1);
        internal().Connect("S2", 1, "And2", 0);
        internal().Connect("S3", 1, "And1", 1);
        internal().Connect("S4", 1, "And1", 0);

        // Link the Or
        internal().Connect("And1", 0, "Or", 0);
        internal().Connect("And2", 0, "Or", 1);

        // Link the outputs
        internal().Connect("Or", 0, "Cout", 0);
        internal().Connect("Xor2", 0, "S", 0);

    }

};

#endif

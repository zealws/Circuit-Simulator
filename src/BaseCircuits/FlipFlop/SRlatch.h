#ifndef __SRlatch_H__
#define __SRlatch_H__

#include "CircuitSimulator.h"

////
//// SRlatch
////

class SRlatch : public BlackBox {

protected:

    // Returns the delay of the component
    State::Timestamp Delay() {
        return 10;
    }

public:

    // Q's initial output state is false.
    // q's initial output state is true.

    // Constructor
    SRlatch()
        : BlackBox("SRlatch", 2, 2)
        {

        // We actually create the SR latch internals.
        internal().AddComponent("R", new CircuitInput());
        internal().AddComponent("S", new CircuitInput());
        internal().AddComponent("NorS", new Nor());
        internal().AddComponent("NorR", new Nor());
        internal().AddComponent("NorSsplit", new Splitter(2));
        internal().AddComponent("NorRsplit", new Splitter(2));
        internal().AddComponent("Q", new CircuitOutput());
        internal().AddComponent("q", new CircuitOutput());

        internal().AddInput("R"); // Input 0
        internal().AddInput("S"); // Input 1
        internal().AddOutput("Q"); // Output 0
        internal().AddOutput("q"); // Output 1

        internal().Connect("S", 0, "NorS", 0);
        internal().Connect("R", 0, "NorR", 0);
        internal().Connect("NorS", 0, "NorSsplit", 0, true);
        internal().Connect("NorR", 0, "NorRsplit", 0, false);
        internal().Connect("NorSsplit", 0, "q", 0, true);
        internal().Connect("NorRsplit", 0, "Q", 0, false);
        internal().Connect("NorSsplit", 1, "NorR", 1, true);
        internal().Connect("NorRsplit", 1, "NorS", 1, false);
    }

};

#endif

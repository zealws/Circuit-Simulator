#ifndef __SRlatch_H__
#define __SRlatch_H__

#include "CircuitSimulator.h"

////
//// SRlatch
////

class SRlatch : public CustomComponent {

protected:

    Circuit c;

    // Evaluates the Subcircuit with certain states.
    // Returns the amount of time it takes to run.
    // If not simulating gate delays, a 0 should be returned.
    void Evaluate(const vector<State>& inputStates, vector<State>& outputStates) {

        // Actually Do Stuff:

        c.PullInput(inputStates);

        c.Evaluate();

        c.PushOutput(outputStates);

    }

    // Returns the delay of the component
    Timestamp Delay() {
        return 10;
    }

public:

    // Q's initial output state is false.
    // q's initial output state is true.

    // Constructor
    SRlatch()
        : CustomComponent("SRlatch", 2, 2)
        {

        // We actually create the SR latch internals.
        c.AddComponent("R", new CircuitInput());
        c.AddComponent("S", new CircuitInput());
        c.AddComponent("NorS", new Nor());
        c.AddComponent("NorR", new Nor());
        c.AddComponent("NorSsplit", new Splitter(2));
        c.AddComponent("NorRsplit", new Splitter(2));
        c.AddComponent("Q", new CircuitOutput());
        c.AddComponent("q", new CircuitOutput());

        c.AddInput("R"); // Input 0
        c.AddInput("S"); // Input 1
        c.AddOutput("Q"); // Output 0
        c.AddOutput("q"); // Output 1

        c.Connect("S", 0, "NorS", 0);
        c.Connect("R", 0, "NorR", 0);
        c.Connect("NorS", 0, "NorSsplit", 0, true);
        c.Connect("NorR", 0, "NorRsplit", 0, false);
        c.Connect("NorSsplit", 0, "q", 0, true);
        c.Connect("NorRsplit", 0, "Q", 0, false);
        c.Connect("NorSsplit", 1, "NorR", 1, true);
        c.Connect("NorRsplit", 1, "NorS", 1, false);
    }

};

#endif

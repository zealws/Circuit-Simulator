#ifndef __SRlatch_H__
#define __SRlatch_H__

#include "CircuitSimulator.h"

////
//// SRlatch
////

class SRlatch : public Subcircuit {

protected:

    Circuit c;

    // Evaluates the Subcircuit with certain states.
    // Returns the amount of time it takes to run.
    // If not simulating gate delays, a 0 should be returned.
    TimeStamp Evaluate(const vector<State>& inputStates, vector<State>& outputStates) {

        // Actually Do Stuff:

        // This is bad, but I don't know another way around it.
        ((CircuitInput*)(c.Lookup("R").body()))->SetState(inputStates[0]);
        ((CircuitInput*)(c.Lookup("S").body()))->SetState(inputStates[1]);

        c.Evaluate();

        outputStates[0] = ((CircuitOutput*)(c.Lookup("Q").body()))->GetState();
        outputStates[1] = ((CircuitOutput*)(c.Lookup("q").body()))->GetState();

        // Timestamp:

        return 0;
    }

public:

    // Q's initial output state is false.
    // q's initial output state is true.

    // Constructor
    SRlatch()
        : Subcircuit("SRlatch", 2, 2)
        {

        // We actually create the SR latch internals.
        c.Link("R", new CircuitInput());
        c.Link("S", new CircuitInput());
        c.Link("NorS", new Nor());
        c.Link("NorR", new Nor());
        c.Link("NorSsplit", new Splitter(2));
        c.Link("NorRsplit", new Splitter(2));
        c.Link("Q", new CircuitOutput());
        c.Link("q", new CircuitOutput());

        c.LinkInput("R"); // Input 0
        c.LinkInput("S"); // Input 1
        c.LinkOutput("Q"); // Output 0
        c.LinkOutput("q"); // Output 1

        c.LinkWithWire("S", 0, "NorS", 0);
        c.LinkWithWire("R", 0, "NorR", 0);
        c.LinkWithWire("NorS", 0, "NorSsplit", 0, true);
        c.LinkWithWire("NorR", 0, "NorRsplit", 0, false);
        c.LinkWithWire("NorSsplit", 0, "q", 0, true);
        c.LinkWithWire("NorRsplit", 0, "Q", 0, false);
        c.LinkWithWire("NorSsplit", 1, "NorR", 1, true);
        c.LinkWithWire("NorRsplit", 1, "NorS", 1, false);
    }

};

#endif
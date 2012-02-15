#ifndef __JKflipflop_H__
#define __JKflipflop_H__

#include "CircuitSimulator.h"

////
//// JKflipflop
////

class JKflipflop : public Subcircuit {

protected:

    Circuit c:

    // Evaluates the Subcircuit with certain states.
    // Returns the amount of time it takes to run.
    // If not simulating gate delays, a 0 should be returned.
    TimeStamp Evaluate(const vector<State>& inputStates, vector<State>& outputStates) {

        // Actually Do Stuff:


        // Timestamp:

        return 0;
    }

public:

    // Q's initial output state is false.
    // q's initial output state is true.

    // Constructor
    JKflipflop()
        : Subcircuit("JKflipflop", 2, 2)
        {

        // Uses an internal SR latch.
        c.LinkInput("J", new CircuitInput()); // Input 0
        c.LinkInput("K", new CircuitInput()); // Input 1
        c.Link("AndJ", new And());
        c.Link("AndK", new And());
        c.Link("SR", new SRlatch());
        c.Link("Qsplit", new Splitter(2));
        c.Link("qsplit", new Splitter(2));
        c.LinkOutput("Q", new CircuitOutput());
        c.LinkOutput("q", new CircuitOutput());

        c.LinkWithWire("J", 0, "AndJ", 0);
        c.LinkWithWire("K", 0, "AndK", 0);
        c.LinkWithWire("AndJ", 0, "SR", 0);
        c.LinkWithWire("AndK", 0, "SR", 1);
        c.LinkWithWire("SR", 0, "Qsplit", 0, false);
        c.LinkWithWire("SR", 1, "qsplit", 0, true);
        c.LinkWithWire("Qsplit", 0, "Q", 0, false);
        c.LinkWithWire("qsplit", 0, "q", 0, true);
        c.LinkWithWire("Qsplit", 1, "AndJ", 1, false);
        c.LinkWithWire("qsplit", 1, "AndK", 1, true);
    }

};

#endif
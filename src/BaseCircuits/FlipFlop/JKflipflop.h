#ifndef __JKflipflop_H__
#define __JKflipflop_H__

#include "CircuitSimulator.h"

////
//// JKflipflop
////

class JKflipflop : public BlackBox {

protected:

    // Returns the delay of the component
    Timestamp Delay() {
        return 10;
    }

public:

    // Q's initial output state is false.
    // q's initial output state is true.

    // Constructor
    JKflipflop()
        : BlackBox("JKflipflop", 2, 2)
        {

        // Uses an internal SR latch.
        internal().Link("J", new CircuitInput());
        internal().Link("K", new CircuitInput());
        internal().Link("AndJ", new And());
        internal().Link("AndK", new And());
        internal().Link("SR", new SRlatch());
        internal().Link("Qsplit", new Splitter(2));
        internal().Link("qsplit", new Splitter(2));

        internal().Link("Q", new CircuitOutput());
        internal().Link("q", new CircuitOutput());

        internal().LinkInput("J"); // Input 0
        internal().LinkInput("K"); // Input 1
        internal().LinkOutput("Q"); // Output 0
        internal().LinkOutput("q"); // Output 1

        internal().LinkWithWire("J", 0, "AndJ", 0);
        internal().LinkWithWire("K", 0, "AndK", 0);
        internal().LinkWithWire("AndJ", 0, "SR", 0);
        internal().LinkWithWire("AndK", 0, "SR", 1);
        internal().LinkWithWire("SR", 0, "Qsplit", 0, false);
        internal().LinkWithWire("SR", 1, "qsplit", 0, true);
        internal().LinkWithWire("Qsplit", 0, "Q", 0, false);
        internal().LinkWithWire("qsplit", 0, "q", 0, true);
        internal().LinkWithWire("Qsplit", 1, "AndJ", 1, false);
        internal().LinkWithWire("qsplit", 1, "AndK", 1, true);

    }

};

#endif

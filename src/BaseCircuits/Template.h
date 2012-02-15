////
//// In order to write circuit:
////
//// 1)  Copy everything below this block comment to a new header file.
//// 2)  Change all instances of "NAME" to the name of your circuit.
//// 3)  Change Evaluate so it calculates the outputs and returns the timestamp.
//// 3a) If you are not simulating gate delays, you can return 0 as the timestamp.
//// 4)  Include the file in your cpp file.
//// 5)  Create it with any of these syntaxes:
////
////     Component myCircuit(new NAME());
////
////     topLevelCircuit.Link("myCircuit", new NAME());
////

#ifndef __NAME_H__
#define __NAME_H__

#include "CircuitSimulator.h"

////
//// NAME
////

class NAME : public CustomComponent {

protected:

    // Evaluates the Subcircuit with certain states.
    // Returns the amount of time it takes to run.
    // If not simulating gate delays, a 0 should be returned.
    TimeStamp Evaluate(const vector<State>& inputStates, vector<State>& outputStates) {

        // Actually Do Stuff:


        // Timestamp:

        return 0;
    }

public:

    // Constructor
    NAME()
        : Subcircuit("NAME", 0, 0)
        {
        // There are no internal mechanisms for our gate that need to be
        // created or initialized, so nothing goes here.
    }

};

#endif

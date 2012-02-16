////
//// In order to write circuit:
////
//// 1)  Copy everything below this block comment to a new header file.
//// 2)  Change all instances of "NAME" to the name of your circuit.
//// 3)  Change Evaluate so it calculates the outputs
//// 4)  Change the Delay function so it returns the gate delay of the gate.
//// 4a) If you are not simulating gate delays, you can return 0 as the timestamp.
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
    void Evaluate(const vector<State>& inputStates, vector<State>& outputStates) {

        // Actually Do Stuff:

    }

    // Returns the gate delay
    // If not simulating gate delays, a 0 should be returned.
    Timestamp Delay() {
        return 0;
    }

public:

    // Constructor
    NAME()
        : CustomComponent("NAME", 0, 0) {
        // There are no internal mechanisms for our gate that need to be
        // created or initialized, so nothing goes here.
    }

};

#endif

#ifndef __CircuitOutput_H__
#define __CircuitOutput_H__

#include "CircuitSimulator.h"

////
//// CircuitOutput
////

class CircuitOutput : public Subcircuit {

protected:

    // Internal State of the CircuitOutput
    bool state;

    // Evaluates the Subcircuit with certain states.
    // Returns the amount of time it takes to run.
    // If not simulating gate delays, a 0 should be returned.
    TimeStamp Evaluate(const vector<State>& inputStates, vector<State>& outputStates) {

        // Actually Do Stuff:

        state = inputStates[0];

        // Timestamp:

        return 0;
    }

public:

    // Constructor
    CircuitOutput()
        : state(false), Subcircuit("CircuitOutput", 1, 0)
        {
        // There are no internal mechanisms for our gate that need to be
        // created or initialized, so nothing goes here.
    }

    bool GetState() {
        return state;
    }

};

#endif


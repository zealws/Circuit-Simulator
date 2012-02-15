#ifndef __CircuitInput_H__
#define __CircuitInput_H__

#include "CircuitSimulator.h"

////
//// CircuitInput
////

class CircuitInput : public Subcircuit {

protected:

    // Internal State of the CircuitInput
    bool state;

    // Evaluates the Subcircuit with certain states.
    // Returns the amount of time it takes to run.
    // If not simulating gate delays, a 0 should be returned.
    TimeStamp Evaluate(const vector<State>& inputStates, vector<State>& outputStates) {

        // Actually Do Stuff:

        outputStates[0] = state;

        // Timestamp:

        return 1;
    }

public:

    // Constructor
    CircuitInput(bool initState = false)
        : state(initState), Subcircuit("CircuitInput", 0, 1)
        {
        // There are no internal mechanisms for our gate that need to be
        // created or initialized, so nothing goes here.
    }

    void SetState(bool newState) {
        state = newState;
    }

};

#endif

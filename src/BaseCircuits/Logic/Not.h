#ifndef __NOT_H__
#define __NOT_H__

#include "CircuitSimulator.h"

////
//// Not Gate
////

class Not : public Subcircuit {

protected:

    // Evaluates the Subcircuit with certain states.
    // Returns the amount of time it takes to run.
    // If not simulating gate delays, a 0 should be returned.
    TimeStamp Evaluate(const vector<State>& inputStates, vector<State>& outputStates) {

        // Actually Do Stuff:

        outputStates[0] = State(not inputStates[0]);

        // Timestamp:

        return 1;
    }

public:

    // Constructor
    Not()
        : Subcircuit("NotGate", 1, 1) // 2 inputs and 1 output
        {
        // There are no internal mechanisms for our gate that need to be
        // created or initialized, so nothing goes here.
    }

};

#endif

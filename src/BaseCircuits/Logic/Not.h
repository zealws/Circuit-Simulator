#ifndef __NOT_H__
#define __NOT_H__

#include "CircuitSimulator.h"

////
//// Not Gate
////

class Not : public CustomComponent {

protected:

    // Evaluates the Subcircuit with certain states.
    // Returns the amount of time it takes to run.
    // If not simulating gate delays, a 0 should be returned.
    void Evaluate(const vector<State::Boolean>& inputStates, vector<State::Boolean>& outputStates) {

        // Actually Do Stuff:

        outputStates[0] = State::Boolean(not inputStates[0]);

    }
    
    // Returns the delay of the component
    State::Timestamp Delay() {
        return 1;
    }

public:

    // Constructor
    Not()
        : CustomComponent("NotGate", 1, 1) // 2 inputs and 1 output
        {
        // There are no internal mechanisms for our gate that need to be
        // created or initialized, so nothing goes here.
    }

};

#endif

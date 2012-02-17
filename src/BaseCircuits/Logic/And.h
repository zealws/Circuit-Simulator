#ifndef __AND_H__
#define __AND_H__

#include "CircuitSimulator.h"
#include <iostream>
using namespace std;

////
//// And Gate
////

class And : public CustomComponent {

protected:

    // Evaluates the Subcircuit with certain states.
    // Returns the amount of time it takes to run.
    // If not simulating gate delays, a 0 should be returned.
    void Evaluate(const vector<State::Boolean>& inputStates, vector<State::Boolean>& outputStates) {

        // Actually Do Stuff:

        outputStates[0] = State::Boolean(inputStates[0] and inputStates[1]);

    }

    // Returns the delay of the component
    State::Timestamp Delay() {
        return 2;
    }

public:

    // Constructor
    And()
        : CustomComponent("AndGate", 2, 1) // 2 inputs and 1 output
        {
        // There are no internal mechanisms for our gate that need to be
        // created or initialized, so nothing goes here.
    }

};

#endif

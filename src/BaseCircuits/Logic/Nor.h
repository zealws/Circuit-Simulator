#ifndef __Nor_H__
#define __Nor_H__

#include "CircuitSimulator.h"

////
//// Nor Gate
////

class Nor : public CustomComponent {

protected:

    // Evaluates the Subcircuit with certain states.
    // Returns the amount of time it takes to run.
    // If not simulating gate delays, a 0 should be returned.
    void Evaluate(const vector<State>& inputStates, vector<State>& outputStates) {

        // Actually Do Stuff:

        outputStates[0] = not(inputStates[0] or inputStates[1]);

    }
    
    // Returns the delay of the component
    Timestamp Delay() {
        return 2;
    }

public:

    // Constructor
    Nor()
        : CustomComponent("Nor", 2, 1) // 2 inputs and 1 output
        {
        // There are no internal mechanisms for our gate that need to be
        // created or initialized, so nothing goes here.
    }

};

#endif

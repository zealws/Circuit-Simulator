#ifndef __Or_H__
#define __Or_H__

#include "CircuitSimulator.h"

////
//// Or Gate
////

class Or : public CustomComponent {

protected:

    // Evaluates the Subcircuit with certain states.
    // Returns the amount of time it takes to run.
    // If not simulating gate delays, a 0 should be returned.
    void Evaluate(const vector<State>& inputStates, vector<State>& outputStates) {

        // Actually Do Stuff:

        outputStates[0] = State(inputStates[0] or inputStates[1]);

    }
    
    // Returns the delay of the component
    Timestamp Delay() {
        return 2;
    }

public:

    // Constructor
    Or()
        : CustomComponent("Or", 2, 1) // 2 inputs and 1 output
        {
        // There are no internal mechanisms for our gate that need to be
        // created or initialized, so nothing goes here.
    }

};

#endif

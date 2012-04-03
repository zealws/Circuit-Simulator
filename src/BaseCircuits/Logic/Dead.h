#ifndef __Dead_H__
#define __Dead_H__

#include "CircuitSimulator.h"

////
//// Dead
////

class Dead : public CustomComponent {

protected:

    // Evaluates the Subcircuit with certain states.
    // Returns the amount of time it takes to run.
    // If not simulating gate delays, a 0 should be returned.
    void Evaluate(const vector<State::Boolean>& inputStates, vector<State::Boolean>& outputStates) {

        // DO NOTHING!!!

    }

    // Returns the delay of the component
    State::Timestamp Delay() {
        return 0;
    }

public:

    // Constructor
    Dead(int size)
        : CustomComponent("Dead", size, 0)
        {
        // Do Nothing
    }

};

#endif

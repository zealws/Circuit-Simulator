#ifndef __Splitter_H__
#define __Splitter_H__

#include "CircuitSimulator.h"

////
//// Splitter
////

class Splitter : public CustomComponent {

protected:

    // Evaluates the Subcircuit with certain states.
    // Returns the amount of time it takes to run.
    // If not simulating gate delays, a 0 should be returned.
    void Evaluate(const vector<State::Boolean>& inputStates, vector<State::Boolean>& outputStates) {

        // Actually Do Stuff:

        for(int i = 0; i < outputStates.size(); i++) {
            outputStates[i] = inputStates[0];
        }
    }

    // Returns the delay of the component
    State::Timestamp Delay() {
        return 0;
    }

public:

    // Constructor
    Splitter(int size)
        : CustomComponent("Splitter", 1, size)
        {
        // There are no internal mechanisms for our gate that need to be
        // created or initialized, so nothing goes here.
    }

};

#endif

#ifndef __CircuitOutput_H__
#define __CircuitOutput_H__

#include "CircuitSimulator.h"

////
//// CircuitOutput
////

class CircuitOutput : public CustomComponent {

protected:

    // Internal State of the CircuitOutput
    bool state;

    // Evaluates the Subcircuit with certain states.
    // Returns the amount of time it takes to run.
    // If not simulating gate delays, a 0 should be returned.
    virtual void Evaluate(const vector<State::Boolean>& inputStates, vector<State::Boolean>& outputStates) {

        // Actually Do Stuff:

        state = inputStates[0];

    }

    // Returns the delay of the component
    State::Timestamp Delay() {
        return 0;
    }

public:

    // Constructor
    CircuitOutput()
        : state(false), CustomComponent("CircuitOutput", 1, 0)
        {
        // There are no internal mechanisms for our gate that need to be
        // created or initialized, so nothing goes here.
    }

    // Pass-through constructor
    // Specifically for creating instances of derived classes from CircuitOutput
    CircuitOutput(string name)
        : state(false), CustomComponent(name, 1, 0)
        {
        // Do Nothing
    }

    bool GetState() {
        return state;
    }

};

#endif


#ifndef __CircuitInput_H__
#define __CircuitInput_H__

#include "CircuitSimulator.h"

////
//// CircuitInput
////

class CircuitInput : public CustomComponent {

protected:

    // Internal State of the CircuitInput
    bool state;

    // Evaluates the Subcircuit with certain states.
    // Returns the amount of time it takes to run.
    // If not simulating gate delays, a 0 should be returned.
    virtual void Evaluate(const vector<State::Boolean>& inputStates, vector<State::Boolean>& outputStates) {

        // Actually Do Stuff:

        outputStates[0] = state;

    }

    // Returns the delay of the component
    State::Timestamp Delay() {
        return 1;
    }

    // Return the state of the input.
    bool GetState() {
        return state;
    }

public:

    // Constructor
    CircuitInput(bool initState = false)
        : state(initState), CustomComponent("CircuitInput", 0, 1)
        {
        // There are no internal mechanisms for our gate that need to be
        // created or initialized, so nothing goes here.
    }

    // Pass-through constructor
    // Specifically for creating instances of derived classes from CircuitInput
    CircuitInput(string name)
        : state(false), CustomComponent(name, 0, 1) {
        // Do Nothing
    }

    void SetState(bool newState) {
        state = newState;
    }

};

#endif

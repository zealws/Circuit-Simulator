#ifndef __BitVectorInput_H__
#define __BitVectorInput_H__

#include "CircuitSimulator.h"

////
//// BitVectorInput
////

class BitVectorInput : public CustomComponent {

protected:

    // Evaluates the Subcircuit with certain states.
    // Returns the amount of time it takes to run.
    // If not simulating gate delays, a 0 should be returned.
    void Evaluate(const vector<State::Boolean>& inputStates, vector<State::Boolean>& outputStates) {

        // Actually Do Stuff:

        cout << "[" << GetName() << "(" << outputStates.size() << ")] ";
        for(int i = 0; i < outputStates.size(); i++) {
            char c;
            cin >> c;
            bool temp =
                c == 'Y' ||
                c == 'y' ||
                c == 't' ||
                c == 'T' ||
                c == '1';
            outputStates[i] = temp;
        }
    }

    // Returns the delay of the component
    State::Timestamp Delay() {
        return 0;
    }

public:

    // Constructor
    BitVectorInput(int size)
        : CustomComponent("BitVectorInput", 0, size)
        {
        // Do Nothing
    }

};

#endif

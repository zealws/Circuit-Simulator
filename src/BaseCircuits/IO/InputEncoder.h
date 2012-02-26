#ifndef __Encoder_H__
#define __Encoder_H__

#include <iostream>
#include "CircuitInput.h"
using namespace std;

////
//// Encoder
////

template<typename encodedType>
class InputEncoder : public CustomComponent {

protected:

    // Evaluates the Subcircuit with certain states.
    // Returns the amount of time it takes to run.
    // If not simulating gate delays, a 0 should be returned.
    void Evaluate(const vector<State::Boolean>& inputStates, vector<State::Boolean>& outputStates) {

        // Actually Do Stuff:

        encodedType c;
        cout << "[encoder:] ";
        cin >> c;
        unsigned mask = 1;
        for(int i = 0; i < outputStates.size(); i++) {
            State::Boolean out(false);
            if((c & (1<<i)) != 0) {
                out = State::Boolean(true);
            }
            outputStates[outputStates.size()-i-1] = out;
        }

    }

    State::Timestamp Delay() {
        return 0;
    }

public:

    // Constructor
    InputEncoder()
        : CustomComponent("InputEncoder", 0, sizeof(encodedType))
        {
        // Do Nothing
    }

};

#endif

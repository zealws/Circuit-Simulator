#ifndef __LED_H__
#define __LED_H__

#include "CircuitSimulator.h"

////
//// LED
////

class LED : public Subcircuit {

protected:

    // Evaluates the Subcircuit with certain states.
    // Returns the amount of time it takes to run.
    // If not simulating gate delays, a 0 should be returned.
    TimeStamp Evaluate(const vector<State>& inputStates, vector<State>& outputStates) {

        // Actually Do Stuff:

        cout << "[LED:] " << boolalpha << bool(inputStates[0]) << "\n";

        // Timestamp:

        return 1;
    }

public:

    // Constructor
    LED()
        : Subcircuit("LED", 1, 0)
        {
        // There are no internal mechanisms for our gate that need to be
        // created or initialized, so nothing goes here.
    }

};

#endif

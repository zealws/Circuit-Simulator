#ifndef __Button_H__
#define __Button_H__

#include "CircuitSimulator.h"

////
//// Button
////

class Button : public Subcircuit {

protected:

    // Evaluates the Subcircuit with certain states.
    // Returns the amount of time it takes to run.
    // If not simulating gate delays, a 0 should be returned.
    TimeStamp Evaluate(const vector<State>& inputStates, vector<State>& outputStates) {

        // Actually Do Stuff:

        char c;
        cout << "[button:] ";
        cin >> c;
        bool temp =
            c == 'Y' ||
            c == 'y' ||
            c == 't' ||
            c == 'T' ||
            c == '1';
        outputStates[0] = temp;

        // Timestamp:

        return 0;
    }

public:

    // Constructor
    Button()
        : Subcircuit("Button", 0, 1)
        {
        // There are no internal mechanisms for our gate that need to be
        // created or initialized, so nothing goes here.
    }

};

#endif
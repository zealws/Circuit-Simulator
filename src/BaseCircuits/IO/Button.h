#ifndef __Button_H__
#define __Button_H__

#include "CircuitInput.h"

////
//// Button
////

class Button : public CircuitInput {

protected:

    // Evaluates the Subcircuit with certain states.
    // Returns the amount of time it takes to run.
    // If not simulating gate delays, a 0 should be returned.
    void Evaluate(const vector<State::Boolean>& inputStates, vector<State::Boolean>& outputStates) {

        // Actually Do Stuff:

        char c;
        cout << "[" << GetName() << ":] ";
        cin >> c;
        bool temp =
            c == 'Y' ||
            c == 'y' ||
            c == 't' ||
            c == 'T' ||
            c == '1';
        outputStates[0] = temp;

    }

public:

    // Constructor
    Button()
        : CircuitInput("Button")
        {
        // There are no internal mechanisms for our gate that need to be
        // created or initialized, so nothing goes here.
    }

};

#endif

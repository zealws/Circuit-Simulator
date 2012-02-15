#ifndef __StreamInput_H__
#define __StreamInput_H__

#include "CircuitInput.h"
#include <istream>
using namespace std;

////
//// StreamInput
////

class StreamInput : private CircuitInput {

private:

    // The stream to read input from
    istream& sin;

protected:

    // Evaluates the Subcircuit with certain states.
    // Returns the amount of time it takes to run.
    // If not simulating gate delays, a 0 should be returned.
    void Evaluate(const vector<State>& inputStates, vector<State>& outputStates) {

        // Actually Do Stuff:

        char c;
        sin >> c;
        outputStates[0] =
            c == 'Y' ||
            c == 'y' ||
            c == 't' ||
            c == 'T' ||
            c == '1';

    }

public:

    // Constructor
    StreamInput(istream& input)
        : CircuitInput("StreamInput"), sin(input) {
        // Do Nothing
    }

};

#endif

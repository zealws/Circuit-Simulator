#ifndef __StreamOutput_H__
#define __StreamOutput_H__

#include "CircuitOutput.h"
#include <ostream>
using namespace std;

////
//// StreamOutput
////

class StreamOutput : public CircuitOutput {

private:

    ostream& sout;

protected:

    // Evaluates the Subcircuit with certain states.
    // Returns the amount of time it takes to run.
    // If not simulating gate delays, a 0 should be returned.
    void Evaluate(const vector<State>& inputStates, vector<State>& outputStates) {

        // Actually Do Stuff:

        sout << bool(inputStates[0]);

    }

public:

    // Constructor
    StreamOutput(ostream& output)
        : CircuitOutput("StreamOutput"), sout(output) {
        // There are no internal mechanisms for our gate that need to be
        // created or initialized, so nothing goes here.
    }

};

#endif

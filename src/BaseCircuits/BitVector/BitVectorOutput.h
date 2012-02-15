#ifndef __BitVectorOutput_H__
#define __BitVectorOutput_H__

#include "CircuitSimulator.h"

////
//// BitVectorOutput
////

class BitVectorOutput : public Subcircuit {

protected:

    // Evaluates the Subcircuit with certain states.
    // Returns the amount of time it takes to run.
    // If not simulating gate delays, a 0 should be returned.
    TimeStamp Evaluate(const vector<State>& inputStates, vector<State>& outputStates) {

        // Actually Do Stuff:

        cout << "[" << GetSubcircuitName() << "] ";
        for(int i = 0; i < inputStates.size(); i++) {
            cout << boolalpha << bool(inputStates[i]) << " ";
        }
        cout << endl;

        // Timestamp:

        return 0;
    }

public:

    // Constructor
    BitVectorOutput(int size)
        : Subcircuit("BVout", size, 0)
        {
        // There are no internal mechanisms for our gate that need to be
        // created or initialized, so nothing goes here.
    }

};

#endif

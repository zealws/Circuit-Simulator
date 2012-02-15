#ifndef __SUBCIRCUIT_H__
#define __SUBCIRCUIT_H__

#include "CircuitWireDecs.h"
#include "Observable.h"
#include "Wire.h"
#include <vector>
#include <string>
#include <list>
#include "gc_cpp.h"
using namespace std;

////
//// Subcircuit Class Definition
////

class Subcircuit : public gc
{

private:

    // List of wires that are inputs to this Subcircuit.
    vector<Wire*> inputWireList;

    // List of wires that are output to this Subcircuit.
    vector<Wire*> outputWireList;

    // The Name of the Subcircuit
    string identifier;

public:

    // Constructor
    Subcircuit();

    // Specifies the identifier for the subcircuit as well as
    // the sizes of the input and output list, respectively
    Subcircuit(string, int, int);

    // Destructor
    virtual ~Subcircuit();

    // Evaluate the Subcircuit
    // Creates the state vectors for input/output
    // Then calls Evaluate
    // Then copies the output state vector to the output wires.
    // Returns a list of all the Subcircuits whos should be updated
    virtual list<Subcircuit*> EvaluateSubcircuit();

    // Get Input Wires to this Subcircuit.
    vector<Wire*> getInputWires();

    // Get Output Wires to this Subcircuit.
    vector<Wire*> getOutputWires();

    // Sets an Input Wire
    // Does not change the wire at all
    void SetInputWire(Wire*, int);

    // Sets an Output Wire
    // Does not change the wire at all
    void SetOutputWire(Wire*, int);

    // Gets the name of the circuit
    string GetSubcircuitName() const;

    // Sets the name of the circuit
    void SetSubcircuitName(const string&);

    // Evaluates the Subcircuit with certain states.
    // Returns the amount of time it takes to run.
    // If not simulating gate delays, a 0 should be returned.
    virtual TimeStamp Evaluate(const vector<State>& inputStates, vector<State>& outputStates) = 0;

};

#endif /* __SUBCIRCUIT_H__ */

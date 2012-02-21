#ifndef __CustomComponent_H__
#define __CustomComponent_H__

#include "Observable.h"
#include "Wire.h"
#include <vector>
#include <string>
#include <list>
#include "gc_cpp.h"
using namespace std;

////
//// CustomComponent Class Definition
////

class CustomComponent : public gc
{

private:

    // List of wires that are inputs to this CustomComponent.
    vector<Wire*> inputWireList;

    // List of wires that are output to this CustomComponent.
    vector<Wire*> outputWireList;

    // The Name of the CustomComponent
    string identifier;

protected:

    // Evaluates the CustomComponent with certain states.
    // If not simulating gate delays, a 0 should be returned.
    virtual void Evaluate(const vector<State::Boolean>& inputStates, vector<State::Boolean>& outputStates) = 0;

    // Returns the delay of the circuit.
    virtual State::Timestamp Delay() = 0;

public:

    // Specifies the identifier for the CustomComponent as well as
    // the sizes of the input and output list, respectively
    CustomComponent(string id, int inSize, int outSize);

    // Destructor
    virtual ~CustomComponent();

    // Evaluate the CustomComponent
    // Creates the state vectors for input/output
    // Then calls Evaluate
    // Then copies the output state vector to the output wires.
    // Returns a list of all the CustomComponents whos should be updated
    virtual list<Wire*> EvaluateCustomComponent();

    // Get Input Wires to this CustomComponent.
    vector<Wire*> getInputWires();

    // Get Output Wires to this CustomComponent.
    vector<Wire*> getOutputWires();

    // Sets an Input Wire
    // Does not change the wire at all
    void SetInputWire(Wire*, int);

    // Sets an Output Wire
    // Does not change the wire at all
    void SetOutputWire(Wire*, int);

    // Gets the name of the circuit
    string GetName() const;

    // Sets the name of the circuit
    void SetName(const string&);

};

#endif

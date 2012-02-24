#ifndef __CustomComponent_H__
#define __CustomComponent_H__

#include "Observable.h"
#include "Wire.h"
#include <vector>
#include <string>
#include <list>
#include <utility>
#include "gc_cpp.h"
using namespace std;

////
//// CustomComponent Class Definition
////

class CustomComponent : public gc
{

private:

    // The Name of the CustomComponent
    string identifier;

protected:

    // List of wires that are inputs to this CustomComponent.
    vector<Wire*> inputWireList;

    // List of wires that are output to this CustomComponent.
    vector<Wire*> outputWireList;

    // Evaluates the CustomComponent with certain states.
    // If not simulating gate delays, a 0 should be returned.
    virtual void Evaluate(const vector<State::Boolean>& inputStates, vector<State::Boolean>& outputStates) = 0;

    // Returns the delay of the circuit.
    virtual State::Timestamp Delay() = 0;

    // Resizes the circuit's inputs/outputs
    virtual void ResizeInputs(int);
    virtual void ResizeOutputs(int);

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
    virtual vector<Wire*> GetInputWires();

    // Get Output Wires to this CustomComponent.
    virtual vector<Wire*> GetOutputWires();

    // Returns the input/output size of the component.
    virtual unsigned int InputSize();
    virtual unsigned int OutputSize();

    // Creates an output wire between this component and the next one.
    virtual void ConnectOutput(int, CustomComponent*, int, State::Boolean = false);

    // Gets the name of the circuit
    string GetName() const;

    // Sets the name of the circuit
    void SetName(const string&);

};

#endif

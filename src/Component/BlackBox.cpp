#include "BlackBox.h"
#include "WireState.h"
#include "Circuit.h"

using namespace std;

// Returns the internal circuit.
Circuit& BlackBox::internal() {
    return internalCircuit;
}

// Evaluates the Subcircuit with certain states.
void BlackBox::Evaluate(const vector<State::Boolean>& inputStates, vector<State::Boolean>& outputStates) {

    internal().PullInput(inputStates);

    internal().Evaluate();

    internal().PushOutput(outputStates);

}

// Constructor
BlackBox::BlackBox(string name, int inSize, int outSize)
    : CustomComponent(name, inSize, outSize) {
    // Do Nothing
}

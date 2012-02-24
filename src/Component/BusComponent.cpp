#include "BusComponent.h"
#include "CircuitSimulator.h"
#include <sstream>
using namespace std;

// Returns the actual reference number for a virtual input interface
int BusComponent::GetActualInput(int j) {
    int s = 0;
    for(int i = 0; i < j; i++) {
        s += vInputs[i];
    }
    return s;
}

// Returns the actual reference number for a virtual output interface
int BusComponent::GetActualOutput(int j) {
    int s = 0;
    for(int i = 0; i < j; i++) {
        s += vOutputs[i];
    }
    return s;
}

// Create a bus component with some number of virtual inputs and outputs
BusComponent::BusComponent()
    : CustomComponent("BusComponent",0,0) {
    // Do Nothing
}

// Creates an output wire between this component and the next one.
void BusComponent::ConnectOutput(int out, CustomComponent* other, int in, State::Boolean init) {
    BusComponent* actual = dynamic_cast<BusComponent*>(other);
    int busSize = vOutputs[out];
    int outRef = GetActualOutput(out);
    int inRef = actual->GetActualInput(in);
    for(int i = 0; i < busSize; i++) {
        if(out + i >= OutputSize()) {
            ostringstream s;
            s << GetName() << " has no output port " << out;
            throw ComponentError(s.str(), this);
        }
        else if(in + i >= actual->InputSize()) {
            ostringstream s;
            s << actual->GetName() << " has no input port " << out;
            throw ComponentError(s.str(), actual);
        }
        else {
            Wire* p = new Wire();
            outputWireList[outRef+i] = p;
            actual->inputWireList[inRef+i] = p;
            p->SetOutputCircuit(other, inRef+i);
            p->SetInputCircuit(other, outRef+i);
            p->SetState(State(init, 0));
            p->AttachObserver(new UpdateCounter());
        }
    }
}

// Creates virtual inputs and outputs
void BusComponent::CreateVInput(int i) {
    vInputs.push_back(i);
}

void BusComponent::CreateVOutput(int i) {
    vOutputs.push_back(i);
}

// Creates the wires
void BusComponent::CreateWires() {
    int inputs = 0;
    for(int i = 0; i < vInputs.size(); i++) {
        inputs += vInputs[i];
    }
    if(inputs > 0)
        ResizeInputs(inputs);
    int outputs = 0;
    for(int i = 0; i < vOutputs.size(); i++) {
        inputs += vOutputs[i];
    }
    if(outputs > 0)
        ResizeOutputs(inputs);
}

#ifndef __BUS_COMPONENT__
#define __BUS_COMPONENT__

#include "CustomComponent.h"
using namespace std;

class BusComponent : public CustomComponent {

private:

    // Virtual inputs
    vector<int> vInputs;
    // Virtual outputs
    vector<int> vOutputs;

protected:

    // Returns the actual reference number for a virtual input interface
    int GetActualInput(int);

    // Returns the actual reference number for a virtual output interface
    int GetActualOutput(int);

public:

    // Create a bus component with some number of virtual inputs and outputs
    BusComponent();

    // Creates an output wire between this component and the next one.
    virtual void ConnectOutput(int, CustomComponent*, int, State::Boolean = false);

    // Creates virtual inputs and outputs
    virtual void CreateVInput(int);
    virtual void CreateVOutput(int);

    // Creates the wires
    virtual void CreateWires();

};

#endif

#include "CircuitSimulator.h"

////
//// Example an edge trigger using linked-in components.
////

int main() {

    // Create the top-level circuit
    Circuit topLevel;

    // Create the components
    topLevel.AddComponent("Select", new Button());
    topLevel.AddComponent("In0", new Button());
    topLevel.AddComponent("In1", new Button());
    topLevel.AddComponent("Out", new LED());
	topLevel.AddComponent("Split", new Splitter(2));
	topLevel.AddComponent("And0", new And());
	topLevel.AddComponent("And1", new And());
	topLevel.AddComponent("Not", new Not());
	topLevel.AddComponent("Or", new Or());

    // Link the components.
	topLevel.Connect("Select",0,"Split",0);
	topLevel.Connect("Split",0,"And0",0);
	topLevel.Connect("Split",1,"And1",0);
	topLevel.Connect("In0",0,"And0",1);
	topLevel.Connect("In1",0,"And1",1);
	topLevel.Connect("And0",0,"Or",0);
	topLevel.Connect("And1",0,"Or",1);
	topLevel.Connect("Or",0,"Out",0);

    // Specify the input and output components.
    topLevel.AddInput("Select");
    topLevel.AddInput("In0");
    topLevel.AddInput("In1");
    topLevel.AddOutput("Out");

	// Attach Probes
	topLevel.AttachProbe("Not",0);

    // Start Evaluating the Circuit
    topLevel.Evaluate();

    return 0;
}

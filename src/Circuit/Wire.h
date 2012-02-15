#ifndef __WIRE_H__
#define __WIRE_H__

#include "CircuitWireDecs.h"
#include "Observable.h"
#include "WireState.h"

////
//// Wire Class Definition
////

class Wire : public Observable
{

private:

    WireState myState;

    Subcircuit* outputCircuit;

    Subcircuit* inputCircuit;

    bool beenUpdated;

public:

    // Constructor
    // Create a wire with no output gate.
    Wire();

    // Destructor
    virtual ~Wire ();

    // Updates the state of the wire.
    // Returns true if the wire's state was changed.
    bool Update(WireState);

    // Sets the state without modifying beenUpdated or notifying observers.
    bool SetState(WireState);

    // The output circuit of this wire.
    Subcircuit* Next();

    // The input circuit of this wire.
    Subcircuit* Prev();

    // Gets the state of the wire.
    WireState State() const;

    // Sets the output of this wire.
    void SetOutputCircuit(Subcircuit*);

    // Sets the input of this wire.
    void SetInputCircuit(Subcircuit*);

    // Refreshes the wire, so it will be freshly evaluated.
    void Refresh();

};

#endif /* __WIRE_H__ */


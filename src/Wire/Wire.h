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

    State myState;

    CustomComponent* outputCircuit;
    int outputPin;

    CustomComponent* inputCircuit;
    int inputPin;

    bool beenUpdated;

    bool evaluationForced;

public:

    // Constructor
    // Create a wire with no output gate.
    Wire();

    // Destructor
    virtual ~Wire ();

    // Updates the state of the wire.
    // Returns true if the wire's state was changed.
    bool Update(State);

    // Sets the state without modifying beenUpdated or notifying observers.
    bool SetState(State);

    // The output circuit of this wire.
    CustomComponent* Next();

    // The input circuit of this wire.
    CustomComponent* Prev();

    // Gets the state of the wire.
    State GetState() const;

    // Sets the output of this wire. (on a particular pin)
    void SetOutputCircuit(CustomComponent*, int);

    // Sets the input of this wire. (on a particular pin)
    void SetInputCircuit(CustomComponent*, int);

    // Evaluation of this wire does not cause re-evaluation of it's output
    // component. Used for busses.
    void DoNotForceEvaluation();

    // Does this wire force evaluation of it's output component?
    bool ForcesEvaluation();

    // Refreshes the wire, so it will be freshly evaluated.
    void Refresh();

};

#endif /* __WIRE_H__ */


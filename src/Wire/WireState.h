#ifndef __WIRE_STATE_H__
#define __WIRE_STATE_H__

#include "gc_cpp.h"

////
//// STATE_CHANGE Enum Declaration
////

enum STATE_CHANGE { DownShift = 0 , UpShift = 1 };

////
//// Timestamp Declaration
////

// This class's main purpose is to restrict the opertions
// available to timestamps.
// It's essentially a wrapper for an integer type with only
// certain operations defined.
class Timestamp : public gc
{

private:

    // Long long is always 64 bits, whereas long is only 64 bits on a x64 system.
    // I wanted something REALLY long.

    // Internal timestamp
    unsigned long long stamp;

public:

    // Default Constructor
    Timestamp(unsigned long long = 0);

    // Incremental copy constructor
    // Copies the value, then adds the specified amount.
    Timestamp(const Timestamp&, const unsigned long long&);

    // Copy Constructor
    Timestamp(const Timestamp&);

    // Addition
    Timestamp operator+(const Timestamp&) const;

    // Subtraction
    Timestamp operator-(const Timestamp&) const;

    unsigned long long value() const;

};

////
//// State Declaration
//// Along with associated constants.
////

//typedef State bool;

class State : public gc
{

private:

    // The state of the State (ba dum cha)
    bool intern_state;

public:

    // Constructor
    State(bool init_state);

    // Alternate Constructor
    State(const State& other);

    // Leave destructor unimplemented

    // Comparison Operators
    bool operator ==(const State&) const;
    bool operator !=(const State&) const;

    // Or Operators
    State operator or(const State&) const;

    // And Operators
    State operator and(const State&) const;

    // Exclusive Or
    State operator xor(const State&) const;

    // Not Operators
    State operator not() const;

    // Convert to a bool
    operator bool() const;

};


////
//// Wire State
////

class WireState : public gc
{

private:

    // Most Recent State Change
    STATE_CHANGE change;

    // Timestamp of the most recent change.
    Timestamp changeTime;

public:

    static const State Up;
    static const State High;
    static const State Down;
    static const State Low;

    // Creates a Wire State with a State Change and Timestamp.
    // Uses (0->1, 0) as default.
    WireState (STATE_CHANGE = DownShift, Timestamp = 0);

    // Creates a Wire State with a particular initial state.
    WireState (const State&, const Timestamp);

    // Copy Constructor
    // Leave unimplemented.
    // WireState(const WireState&);

    // Destructor
    // Leave unimplemented.
    // virtual ~WireState ();

    // Returns the last state of the wire.
    State LastState() const;

    // Returns the current state of the wire.
    State CurrentState() const;

    // Convert to a bool
    operator bool() const;

    operator State() const;

};

#endif /* __WIRE_STATE_H__ */


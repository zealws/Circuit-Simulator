#include "WireState.h"

////
//// Timestamp Class
////

// Default Constructor
Timestamp::Timestamp(unsigned long long initStamp) : stamp(initStamp) {
    // Do Nothing
}

// Incremental copy constructor
// Copies the value, then adds the specified amount.
Timestamp::Timestamp(const Timestamp& other, const unsigned long long& incr)
    : stamp(other.value() + incr) {
    // Do Nothing
}

// Copy Constructor
Timestamp::Timestamp(const Timestamp& other)
    : stamp(other.value()) {
    // Do Nothing
}

// Addition
Timestamp Timestamp::operator+(const Timestamp& other) const {
    return Timestamp(value()+other.value());
}

// Subtraction
Timestamp Timestamp::operator-(const Timestamp& other) const {
    return Timestamp(value()-other.value());
}

unsigned long long Timestamp::value() const {
    return stamp;
}

////
//// State Class
////

bool intern_state;

// Constructor
State::State(bool init_state)
    : intern_state(init_state) {
    // Do Nothing
}

// Alternate Constructor
State::State(const State& other)
    : intern_state(bool(other)) {
    // Do Nothing
}

// Leave destructor unimplemented

// Comparison Operators
bool State::operator ==(const State& other) const {
    return (bool(other) == intern_state);
}

bool State::operator !=(const State& other) const {
    return (bool(other) != intern_state);
}

// Or Operator
State State::operator or(const State& other) const {
    bool newState = intern_state or bool(other);
    return State(newState);
}

// And Operator
State State::operator and(const State& other) const {
    bool newState = intern_state and bool(other);
    return State(newState);
}

// Exclusive Or
State State::operator xor(const State& other) const {
    bool newState = intern_state xor bool(other);
    return State(newState);
}

// Not Operators
State State::operator not() const {
    return State(not(intern_state));
}

// Convert to a bool
State::operator bool() const {
    return intern_state;
}

////
//// Wire State
////

const State WireState::Up = State(true);
const State WireState::High = State(true);
const State WireState::Down = State(false);
const State WireState::Low = State(false);

// Creates a Wire State with a State Change and Timestamp.
// Uses (0->1, 0) as default.
WireState::WireState (STATE_CHANGE initChange, Timestamp time)
    : change(initChange), changeTime(time) {
    // Do Nothing
}

// Creates a Wire State with a particular initial state.
WireState::WireState (const State& other, const Timestamp time)
    : change(other == Up ? UpShift : DownShift) {
    // Do Nothing
}

// Copy Constructor
// Leave unimplemented.
// WireState(const WireState&);

// Destructor
// Leave unimplemented.
// virtual ~WireState ();

// Returns the last state of the wire.
State WireState::LastState() const {
    return State(change != UpShift);
}

// Returns the current state of the wire.
State WireState::CurrentState() const {
    return State(change == UpShift);
}

// Convert to a bool
WireState::operator bool() const {
    return (change == UpShift);
}

WireState::operator State() const {
    return CurrentState();
}

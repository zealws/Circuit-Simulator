#include "State.h"

////
//// Timestamp Class
////

// Default Constructor
State::Timestamp::Timestamp(unsigned long long initStamp) : stamp(initStamp) {
    // Do Nothing
}

// Incremental copy constructor
// Copies the value, then adds the specified amount.
State::Timestamp::Timestamp(const Timestamp& other, const unsigned long long& incr)
    : stamp(other.value() + incr) {
    // Do Nothing
}

// Copy Constructor
State::Timestamp::Timestamp(const Timestamp& other)
    : stamp(other.value()) {
    // Do Nothing
}

// Addition
State::Timestamp State::Timestamp::operator+(const Timestamp& other) const {
    return Timestamp(value()+other.value());
}

// Subtraction
State::Timestamp State::Timestamp::operator-(const Timestamp& other) const {
    return Timestamp(value()-other.value());
}

// Greater than
bool State::Timestamp::operator>(const Timestamp& other) const {
    return value() > other.value();
}

// Less than
bool State::Timestamp::operator<(const Timestamp& other) const {
    return value() < other.value();
}

unsigned long long State::Timestamp::value() const {
    return stamp;
}

////
//// State Class
////

// Constructor
State::Boolean::Boolean(bool init_state)
    : intern_state(init_state) {
    // Do Nothing
}

// Destructor
State::Boolean::~Boolean() {
    // Do Nothing
}

// Comparison Operators
bool State::Boolean::operator ==(const State::Boolean& other) const {
    return (bool(other) == intern_state);
}

bool State::Boolean::operator !=(const State::Boolean& other) const {
    return (bool(other) != intern_state);
}

// Or Operator
State::Boolean State::Boolean::operator or(const State::Boolean& other) const {
    bool newState = intern_state or bool(other);
    return Boolean(newState);
}

// And Operator
State::Boolean State::Boolean::operator and(const Boolean& other) const {
    bool newState = intern_state and bool(other);
    return Boolean(newState);
}

// Exclusive Or
State::Boolean State::Boolean::operator xor(const Boolean& other) const {
    bool newState = intern_state xor bool(other);
    return Boolean(newState);
}

// Not Operators
State::Boolean State::Boolean::operator not() const {
    return Boolean(not(intern_state));
}

// Convert to a bool
State::Boolean::operator bool() const {
    return intern_state;
}

////
//// Wire State
////

const State::Boolean State::Up = State::Boolean(true);
const State::Boolean State::High = State::Boolean(true);
const State::Boolean State::Down = State::Boolean(false);
const State::Boolean State::Low = State::Boolean(false);

// Creates a Wire State with a State Change and Timestamp.
State::State (const Boolean& other, const Timestamp time)
    : change(other), changeTime(time) {
    // Do Nothing
}

// Destructor
State::~State () {
    // Do Nothing
}

// Returns the last state of the wire.
State::Boolean State::LastValue() const {
    return !(change);
}

// Returns the current state of the wire.
State::Boolean State::CurrentValue() const {
    return change;
}

// Returns the timestamp of the wire state.
State::Timestamp State::Time() const {
    return changeTime;
}

// Convert to a bool
State::operator bool() const {
    return bool(change);
}

State::operator Boolean() const {
    return CurrentValue();
}

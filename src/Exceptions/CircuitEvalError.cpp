#include "Exceptions.h"
#include <string>
using namespace std;

////
//// Run-time Exception ABT
////

// Creates an Error, with a given message
CircuitEvalError::CircuitEvalError(string msg)
    : message(msg) {

}

// Returns the message of the error.
string CircuitEvalError::text() {
    return message;
}

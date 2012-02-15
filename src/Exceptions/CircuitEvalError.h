#ifndef __CIRCUIT_EVAL_ERROR_H__
#define __CIRCUIT_EVAL_ERROR_H__

#include <string>
#include "gc_cpp.h"
using namespace std;

////
//// Run-time Exception ABT
////

class CircuitEvalError : public gc {
private:

    string message;

public:

    // Creates an Error, with a given message
    CircuitEvalError(string);

    // Returns the message of the error.
    string text();

};

#endif

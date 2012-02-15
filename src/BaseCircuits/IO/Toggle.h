#ifndef __Toggle_H__
#define __Toggle_H__

#include "CircuitInput.h"

////
//// Toggle
////

class Toggle : public CircuitInput {

public:

    // Constructor
    Toggle()
        : CircuitInput("Toggle")
        {
        // There are no internal mechanisms for our gate that need to be
        // created or initialized, so nothing goes here.
    }

    void ToggleState() {
        SetState(GetState() xor true);
    }

};

#endif

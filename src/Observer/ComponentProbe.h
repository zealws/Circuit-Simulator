#ifndef __COMPONENT_PROBE_H__
#define __COMPONENT_PROBE_H__

#include "Observer.h"
#include "Wire.h"
#include "gc.h"

////
//// ComponentProbe Class
////
//// Observes a particular component's output wire and prints a message when it's state changes.

class ComponentProbe : public Observer {

public:

    // Destructor
    virtual ~ComponentProbe();

    virtual void Observe();

};

#endif

#ifndef __OBSERVER_H__
#define __OBSERVER_H__

#include "ObserverDecs.h"
#include "gc_cpp.h"

////
//// Observer Class
////

class Observer : public gc {

protected:

    Observable* Observed;

public:

    // Default Constructor
    Observer ();

    // Destructor
    virtual ~Observer();

    // Attaches this observer to a subject.
    void Attach(Observable*);

    // Detaches this observer from its subject.
    void Detach();

    virtual void Observe() = 0;

};

#endif /* __OBSERVER_H__ */


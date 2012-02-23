#ifndef __CIRCUIT_REFRESHER__
#define __CIRCUIT_REFRESHER__

#include "CircuitIterator.h"
#include "BFSIterator.h"

////
//// CircuitRefresher class
////

class CircuitRefresher : public BFSIterator {

private:

    list<CustomComponent*> beenVisited;

protected:

    // Evaluate the current item
    virtual void Evaluate();

public:

    // Destructor
    virtual ~CircuitRefresher();

};

#endif

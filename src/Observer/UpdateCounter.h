#ifndef __UPDATE_COUNTER_H__
#define __UPDATE_COUNTER_H__

#include "Observer.h"
#include "Wire.h"
#include "gc.h"

////
//// UpdateCounter Class
////
//// Observes a wire until it has had so many updates, then kicks it out by throwing an exception.

const long long MaxUpdatesBeforeFail = 20;

class UpdateCounter : public Observer {

protected:

    // Ensure 64-bits
    long long NumUpdates;

public:

    // Default Constructor
    UpdateCounter();

    // Destructor
    virtual ~UpdateCounter();

    virtual void Observe();

};

#endif /* __OBSERVER_H__ */


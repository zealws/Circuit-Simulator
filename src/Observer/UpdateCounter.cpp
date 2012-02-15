#include "Observer.h"
#include "UpdateCounter.h"
#include "Exceptions.h"

////
//// UpdateCounter Class
////

// Default Constructor
UpdateCounter::UpdateCounter()
    : NumUpdates(0) {

}

// Destructor
UpdateCounter::~UpdateCounter() {
    // Do Nothing, really.
}

void UpdateCounter::Observe() {
    NumUpdates++;
    if(NumUpdates > MaxUpdatesBeforeFail) {
        throw WireError("Update Count Maxed", Observed);
    }
}

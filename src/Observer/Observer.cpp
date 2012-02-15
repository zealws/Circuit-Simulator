#include "Observer.h"
#include "Observable.h"
#include <cstdlib>
using namespace std;

////
//// Observer Class
////

// Default Constructor
Observer::Observer() {
    // Do Nothing
}

Observer::~Observer() {

}

// Attaches this observer to a subject.
void Observer::Attach(Observable* subject) {
    Observed = subject;
}

// Detaches this observer from its subject.
void Observer::Detach() {
    Observed = NULL;
}

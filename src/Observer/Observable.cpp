#include <list>
#include "Observer.h"
#include "Observable.h"
using namespace std;

////
//// Observable Class
////

// Notifies the observers of a change in state.
void Observable::NotifyObservers() {
    list<Observer*>::iterator it = ObserverList.begin();
    while(it != ObserverList.end()) {
        (*it)->Observe();
        it++;
    }
}

// Constructor
Observable::Observable () {
    // Do Nothing
}

Observable::~Observable () {
    // Do Nothing
}

// Attaches the Observer to this subject.
void Observable::AttachObserver(Observer* o) {
    ObserverList.push_back(o);
    o->Attach(this);
}

// Detaches an Observer from this subject.
void Observable::DetachObserver(Observer* o) {
    list<Observer*>::iterator it = ObserverList.begin();
    while(it != ObserverList.end()) {
        if((*it) == o) {
            ObserverList.erase(it);
            break;
        }
        it++;
    }
}

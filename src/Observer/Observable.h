#ifndef __OBSERVABLE_H__
#define __OBSERVABLE_H__

#include <list>
#include "gc_cpp.h"
#include "ObserverDecs.h"
using namespace std;

////
//// Observable Class
////

class Observable : public gc {

private:

    // List of all observers observering this subject.
    list<Observer*> ObserverList;

protected:

    // Notifies the observers of a change in state.
    void NotifyObservers();

public:

    // Constructor
    Observable ();

    // Destructor
    virtual ~Observable ();

    // Attaches the Observer to this subject.
    void AttachObserver(Observer*);

    // Detaches an Observer from this subject.
    void DetachObserver(Observer*);

};

#endif /* __OBSERVABLE_H__ */


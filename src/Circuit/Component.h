#ifndef __COMPONENT_H__
#define __COMPONENT_H__

#include "CircuitWireDecs.h"
#include <list>
#include <string>
#include "gc_cpp.h"
#include <utility>
#include <sparsehash/sparse_hash_map>
using namespace std;

////
//// Component Class Definition
////

class Component : public gc {

private:

    // A pointer to the body of the component.
    Subcircuit* bodyRef;

public:

    // Constructor
    Component();

    // Creates a top-level circuit from a Subcircuit
    Component(Subcircuit*);
    Component(const string&, Subcircuit*);

    // Destructor
    virtual ~Component();

    // Returns the body of this circuit.
    Subcircuit* body();

};

#endif


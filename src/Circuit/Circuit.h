#ifndef __CIRCUIT_H__
#define __CIRCUIT_H__

#include "CircuitWireDecs.h"
#include <list>
#include <string>
#include "gc_cpp.h"
#include <utility>
#include "sparse_hash_map.h"
using namespace std;

//
// eqstr Structure
//
// Used for string comparison in the dictionary.
//

struct eqstr {
    bool operator()(const string& s1, const string& s2) const {
        return s1 == s2;
    }
};

////
//// Circuit Class Definition
////

class Circuit : public gc {

private:

    // Inputs to the Circuit
    list<CustomComponent*> inputSubcircuits;

    // Outputs to the Circuit
    list<CustomComponent*> outputComponents;

    // Hash table for all the linked components
    google::sparse_hash_map<string, Component, tr1::hash<string>, eqstr> components;

    // Helper Function to add a component pair
    void AddComponent(string, Component);

public:

    // Constructor
    Circuit();

    // Destructor
    virtual ~Circuit ();

    // Links a circuit as an input gate of this circuit, with an optional identifier
    void LinkInput(Component);
    void LinkInput(CustomComponent*);
    void LinkInput(string);

    // Links a subcircuit as an output gate of this circuit, with an optional identifier
    void LinkOutput(Component);
    void LinkOutput(CustomComponent*);
    void LinkOutput(string);

    // Links an arbitrary component with an identifier.
    void Link(string, Component);

    // Returns the input subcircuits
    list<CustomComponent*> GetInputComponents() const;

    // Returns the output subcircuits
    list<CustomComponent*> GetOutputComponents() const;

    // Returns the component with the given identifier.
    Component Lookup(string);

    // Links two circuits with a wire.
    // Uses the specified input and output wire numbers.

    // This function does all the work
    static void LinkWithWire(Component in, int inNo, Component out, int outNo, bool initWireState = true);

    // Links two components in this circuit.
    void LinkWithWire(string inId, int inNo, string outId, int outNo, bool initWireState = true);

    // Evaluates the circuit
    void Evaluate();

};

#endif /* __CIRCUIT_H__ */


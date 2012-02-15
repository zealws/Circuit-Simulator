#ifndef __CIRCUIT_H__
#define __CIRCUIT_H__

#include "CircuitWireDecs.h"
#include <list>
#include <string>
#include "gc_cpp.h"
#include <utility>
#include <sparsehash/sparse_hash_map>
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

    // For comparing pairs, so I can use std::list's built-in sort operation.
    static bool compare_subcircuit_pairs(pair<string,Subcircuit*>,pair<string,Subcircuit*>);

    Subcircuit* bodyRef;

    // Inputs to the Circuit
    list<Subcircuit*> inputSubcircuits;

    // Outputs to the Circuit
    list<Subcircuit*> outputSubcircuits;

    // Hash table for all the linked components
    google::sparse_hash_map<string, Subcircuit*, tr1::hash<string>, eqstr> components;

    // Helper functions to link input/output
    void LinkOutput(Subcircuit*);
    void LinkInput(Subcircuit*);

    // Helper Function to add a component pair
    void AddComponent(string,Subcircuit*);

public:

    // Constructor
    Circuit();

    // Creates a top-level circuit from a Subcircuit
    Circuit(Subcircuit&);
    Circuit(const string&, Subcircuit*);

    // Destructor
    virtual ~Circuit ();

    // Returns the body of this circuit.
    Subcircuit* body();

    // Links a circuit as an input gate of this circuit, with an optional identifier
    //void LinkInput(Circuit&); // deprecated
    void LinkInput(string,Subcircuit*);

    // Links a subcircuit as an output gate of this circuit, with an optional identifier
    //void LinkOutput(Circuit&); // deprecated
    void LinkOutput(string,Subcircuit*);

    // Links an arbitrary component with an identifier.
    void Link(string, Subcircuit*);

    // Returns the input subcircuits
    list<Subcircuit*> GetInputSubcircuits() const;

    // Returns the output subcircuits
    list<Subcircuit*> GetOutputSubcircuits() const;

    // Returns the component with the given identifier.
    Subcircuit* Lookup(const string&);

    // Links two circuits with a wire.
    // Uses the specified input and output wire numbers.

    // This function does all the work
    void LinkWithWire(Subcircuit* in, int inNo, Subcircuit* out, int outNo, bool initWireState = true);

    // All of these are variations on a theme:
    void LinkWithWire(Subcircuit& in, int inNo, Subcircuit& out, int outNo, bool initWireState = true);
    void LinkWithWire(Circuit& in, int inNo, Circuit& out, int outNo, bool initWireState = true);

    // Links two components in this circuit.
    void LinkWithWire(string inId, int inNo, string outId, int outNo, bool initWireState = true);

};

#endif /* __CIRCUIT_H__ */


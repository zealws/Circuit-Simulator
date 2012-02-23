#include "Debugger.h"
#include "CircuitSimulator.h"
#include <list>
#include <vector>
using namespace std;

// Evaluate the current item
void Debugger::Evaluate() {

    cout << CurrentItem()->GetName() << " > ";
    char c;
    cin >> c;

    list<Wire*> updated = CurrentItem()->EvaluateCustomComponent();

    while(not(updated.empty())) {
        Wire* p = updated.front();
        enqueue(p);
        updated.pop_front();
    }
}

// Destructor
Debugger::~Debugger() {
    // Do Nothing
}
#include "NormalEvaluator.h"
#include "CircuitSimulator.h"
#include <list>
using namespace std;

// Evaluate the current item
void NormalEvaluator::EvaluateCurrentItem() {

    list<Wire*> updated = CurrentItem()->EvaluateCustomComponent();

    while(not(updated.empty())) {
        Wire* p = updated.front();
        AddComponent(p->Next());
        updated.pop_front();
    }
}

// Destructor
NormalEvaluator::~NormalEvaluator() {
    // Do Nothing
}
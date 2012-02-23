#include "DelayEvaluator.h"
#include "CircuitSimulator.h"
#include <list>
#include <vector>
using namespace std;

// Evaluate the current item
void DelayEvaluator::Evaluate() {

    list<Wire*> updated = CurrentItem()->EvaluateCustomComponent();

    while(not(updated.empty())) {
        Wire* p = updated.front();
        enqueue(p);
        updated.pop_front();
    }
}

// Destructor
DelayEvaluator::~DelayEvaluator() {
    // Do Nothing
}
#include "Observer.h"
#include "ComponentProbe.h"
#include "Exceptions.h"
#include <iostream>
using namespace std;

////
//// ComponentProbe Class
////

// Destructor
ComponentProbe::~ComponentProbe() {
    // Do Nothing, really.
}

void ComponentProbe::Observe() {
	cout << "probe[" << dynamic_cast<Wire*>(Observed)->Prev()->GetName() << "] " << dynamic_cast<Wire*>(Observed)->GetState() << endl;
}

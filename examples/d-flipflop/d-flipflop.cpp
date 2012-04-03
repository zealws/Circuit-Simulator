#include "CircuitSimulator.h"

////
//// Example an edge trigger using linked-in components.
////

int main() {

    // Create the top-level circuit
    Circuit topLevel;

    // Create the components
    topLevel.AddComponent("D", new CircuitInput());
    topLevel.AddComponent("CLK", new CircuitInput());
    topLevel.AddComponent("Top", new SRlatch());
    topLevel.AddComponent("Bottom", new SRlatch());
    topLevel.AddComponent("Out", new SRlatch());
    topLevel.AddComponent("clk_splitter", new Splitter(2));
    topLevel.AddComponent("bottom_splitter", new Splitter(2));
    topLevel.AddComponent("end", new Dead(1));
    topLevel.AddComponent("orGate", new Or());
    topLevel.AddComponent("Q", new LED());
    topLevel.AddComponent("Qbar", new LED());

    // Link the components.
    topLevel.Connect("D",0,"Top",1); // D -- Top::S
    topLevel.Connect("CLK",0,"clk_splitter",0); // CLK -- clk_splitter
    topLevel.Connect("clk_splitter",0,"orGate",0); // clk_splitter::0 -- orGate::0
    topLevel.Connect("clk_splitter",1,"Bottom",0); // clk_splitter::1 -- Bottom::R
    topLevel.Connect("orGate",0,"Top",0); // orGate -- Top::R
    topLevel.Connect("Top",0,"Out",1); // Top::Q -- Out::S
    topLevel.Connect("Top",1,"Bottom",1); // Top::Qbar -- Bottom::S
    topLevel.Connect("Bottom",0,"bottom_splitter",0); // Bottom::Q -- bottom_splitter
    topLevel.Connect("Bottom",1,"end",0); // Bottom::Qbar -- x_x
    topLevel.Connect("bottom_splitter",0,"orGate",1); // bottom_splitter::0 -- orGate::1
    topLevel.Connect("bottom_splitter",1,"Out",0); // bottom_splitter::1 -- Out::R
    topLevel.Connect("Out",0,"Q",0); // Out::0 -- Q
    topLevel.Connect("Out",1,"Qbar",0); // Out::1 -- Qbar

    // Specify the input and output components.
    topLevel.AddInput("D");
    topLevel.AddInput("CLK");
    topLevel.AddOutput("Q");
    topLevel.AddOutput("Qbar");

    // Start Evaluating the Circuit

    topLevel.Evaluate();

    dynamic_cast<CircuitInput*>(topLevel.Lookup("CLK").body())->SetState(false);
    dynamic_cast<CircuitInput*>(topLevel.Lookup("D").body())->SetState(false);

    cout << "----------\n";
    cout << "CLK: 0\n";
    cout << "D:   0\n";

    topLevel.Evaluate();

    dynamic_cast<CircuitInput*>(topLevel.Lookup("CLK").body())->SetState(false);
    dynamic_cast<CircuitInput*>(topLevel.Lookup("D").body())->SetState(true);

    cout << "----------\n";
    cout << "CLK: 0\n";
    cout << "D:   1\n";

    topLevel.Evaluate();

    dynamic_cast<CircuitInput*>(topLevel.Lookup("CLK").body())->SetState(true);
    dynamic_cast<CircuitInput*>(topLevel.Lookup("D").body())->SetState(true);

    cout << "----------\n";
    cout << "CLK: 1\n";
    cout << "D:   1\n";

    topLevel.Evaluate();

    dynamic_cast<CircuitInput*>(topLevel.Lookup("CLK").body())->SetState(false);
    dynamic_cast<CircuitInput*>(topLevel.Lookup("D").body())->SetState(true);

    cout << "----------\n";
    cout << "CLK: 0\n";
    cout << "D:   1\n";

    topLevel.Evaluate();

    dynamic_cast<CircuitInput*>(topLevel.Lookup("CLK").body())->SetState(true);
    dynamic_cast<CircuitInput*>(topLevel.Lookup("D").body())->SetState(true);

    cout << "----------\n";
    cout << "CLK: 1\n";
    cout << "D:   1\n";

    topLevel.Evaluate();

    dynamic_cast<CircuitInput*>(topLevel.Lookup("CLK").body())->SetState(true);
    dynamic_cast<CircuitInput*>(topLevel.Lookup("D").body())->SetState(false);

    cout << "----------\n";
    cout << "CLK: 1\n";
    cout << "D:   0\n";

    topLevel.Evaluate();

    dynamic_cast<CircuitInput*>(topLevel.Lookup("CLK").body())->SetState(false);
    dynamic_cast<CircuitInput*>(topLevel.Lookup("D").body())->SetState(false);

    cout << "----------\n";
    cout << "CLK: 0\n";
    cout << "D:   0\n";

    topLevel.Evaluate();

    dynamic_cast<CircuitInput*>(topLevel.Lookup("CLK").body())->SetState(false);
    dynamic_cast<CircuitInput*>(topLevel.Lookup("D").body())->SetState(true);

    cout << "----------\n";
    cout << "CLK: 0\n";
    cout << "D:   1\n";

    topLevel.Evaluate();

    dynamic_cast<CircuitInput*>(topLevel.Lookup("CLK").body())->SetState(true);
    dynamic_cast<CircuitInput*>(topLevel.Lookup("D").body())->SetState(true);

    cout << "----------\n";
    cout << "CLK: 1\n";
    cout << "D:   1\n";

    topLevel.Evaluate();

    dynamic_cast<CircuitInput*>(topLevel.Lookup("CLK").body())->SetState(false);
    dynamic_cast<CircuitInput*>(topLevel.Lookup("D").body())->SetState(false);

    cout << "----------\n";
    cout << "CLK: 0\n";
    cout << "D:   0\n";

    topLevel.Evaluate();

    return 0;
}

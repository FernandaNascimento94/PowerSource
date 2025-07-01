#include "POWER_SOURCE.hpp"
#include <vector>

int main() {
    srand(time(0));

    std::vector<PowerSource*> sources = {
        new Solar(), new Solar(), new Solar(),
        new Geo(), new Geo(), new Geo(),
        new Nuclear(), new Nuclear(),
        new Hydro(), new Hydro(), new Hydro(),
        new Wind(), new Wind(), new Wind()
    };

    double totalOut = 0, totalSet = 0, totalMain = 0;

    std::cout << std::left << std::setw(25) << "Power Source"
        << std::right << std::setw(12) << "Output"
        << std::setw(18) << "Setup"
        << std::setw(16) << "Maintenance\n";
    std::cout << std::string(70, '-') << "\n";

    for (auto p : sources) {
        p->print();
        totalOut += p->getOutput();
        totalSet += p->getSetup();
        totalMain += p->getMaint();
        delete p;
    }

    std::cout << "\nTotal output: " << totalOut << " MW/h per year\n";
    std::cout << "Total setup cost: USD " << totalSet << "\n";
    std::cout << "Total monthly maintenance: USD " << totalMain << "\n";

    return 0;
}
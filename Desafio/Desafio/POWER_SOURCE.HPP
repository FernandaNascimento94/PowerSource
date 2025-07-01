#ifndef ENERGY_SYSTEM_HPP
#define ENERGY_SYSTEM_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <vector>

class PowerSource {
protected:
    std::string name;
    double output;
    double setupCost;
    double maintenance;

public:
    PowerSource(std::string n, double o, double s, double m)
        : name(n) {
        double var = (rand() % 21 - 10) / 100.0;
        output = o * (1 + var);
        setupCost = s * (1 + var);
        maintenance = m * (1 + var);
    }

    void print() const {
        std::cout << std::left << std::setw(25) << name
            << std::right << std::setw(12) << std::fixed << std::setprecision(2) << output
            << std::setw(18) << setupCost
            << std::setw(16) << maintenance << "\n";
    }

    double getOutput() const { return output; }
    double getSetup() const { return setupCost; }
    double getMaint() const { return maintenance; }
};

class Solar : public PowerSource {
public:
    Solar() : PowerSource("Solar Panel Farm", 13000, 23500000, 140) {}
};

class Geo : public PowerSource {
public:
    Geo() : PowerSource("Geothermal Plant", 71000, 32000000, 130) {}
};

class Nuclear : public PowerSource {
public:
    Nuclear() : PowerSource("Nuclear Plant", 80000, 85000000, 300) {}
};

class Hydro : public PowerSource {
public:
    Hydro() : PowerSource("Hydro Plant", 50000, 50000000, 100) {}
};

class Wind : public PowerSource {
public:
    Wind() : PowerSource("Wind Farm", 35000, 20000000, 180) {}
};

#endif
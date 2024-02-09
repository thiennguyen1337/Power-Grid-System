#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

// Class representing a Power Plant
class PowerPlant {
private:
    string type;
    double capacity;
public:
    PowerPlant(string t, double c) : type(t), capacity(c) {}

    void displayInfo() {
        cout << "Type: " << type << ", Capacity: " << capacity << " MW" << endl;
    }

    double getCapacity() const {
        return capacity;
    }
};

// Class representing a Transmission Line
class TransmissionLine {
private:
    double capacity;
    double length;
    bool status;
public:
    TransmissionLine(double cap, double len) : capacity(cap), length(len), status(true) {}

    bool getStatus() {
        return status;
    }

    void setStatus(bool s) {
        status = s;
    }

    double getCapacity() const {
        return capacity;
    }
};

// Class representing a Substation
class Substation {
private:
    double load;
    double voltage;
public:
    Substation() : load(0), voltage(0) {}

    void updateLoad(double l) {
        load += l;
    }

    void updateVoltage(double v) {
        voltage = v;
    }

    void displayStatus() {
        cout << "Load: " << load << " MW, Voltage: " << voltage << " kV" << endl;
    }

    double getLoad() const {
        return load;
    }

    double getVoltage() const {
        return voltage;
    }
};

// Main Power Grid Management System class
class PowerGridManagementSystem {
private:
    vector<PowerPlant> powerPlants;
    vector<TransmissionLine> transmissionLines;
    vector<Substation> substations;

    // Fault detection function
    bool detectFault() {
        // Simulate a fault randomly for demonstration purposes
        return rand() % 10 == 0; // Simulate 10% chance of fault occurrence
    }

    // Load balancing function
    void balanceLoad() {
        double totalCapacity = 0;
        for (const auto& plant : powerPlants) {
            totalCapacity += plant.getCapacity();
        }

        double totalLoad = 0;
        for (const auto& substation : substations) {
            totalLoad += substation.getLoad();
        }

        double avgLoad = totalLoad / substations.size();
        double excessLoad = totalLoad - totalCapacity;

        // Redistribute excess load evenly among substations
        if (excessLoad > 0) {
            for (auto& substation : substations) {
                substation.updateLoad(-excessLoad / substations.size());
            }
        }
    }

    // Voltage regulation function
    void regulateVoltage() {
        double totalVoltage = 0;
        for (const auto& substation : substations) {
            totalVoltage += substation.getVoltage();
        }

        double avgVoltage = totalVoltage / substations.size();

        // Adjust voltage levels in substations
        for (auto& substation : substations) {
            substation.updateVoltage(avgVoltage);
        }
    }

public:
    void addPowerPlant(string type, double capacity) {
        powerPlants.push_back(PowerPlant(type, capacity));
    }

    void addTransmissionLine(double capacity, double length) {
        transmissionLines.push_back(TransmissionLine(capacity, length));
    }

    void addSubstation() {
        substations.push_back(Substation());
    }

    void simulateFaultDetection() {
        if (detectFault()) {
            cout << "Fault detected! Taking necessary actions..." << endl;
            // Handle fault here
        }
    }

    void monitorPowerPlants() {
        cout << "===== Power Plants =====" << endl;
        for (auto& plant : powerPlants) {
            plant.displayInfo();
        }
    }

    void monitorSubstations() {
        cout << "===== Substations =====" << endl;
        for (auto& substation : substations) {
            substation.displayStatus();
        }
    }

    void optimizeGrid() {
        simulateFaultDetection();
        balanceLoad();
        regulateVoltage();
    }
};

int main() {
    PowerGridManagementSystem grid;

    // Adding Power Plants
    grid.addPowerPlant("Coal", 100);
    grid.addPowerPlant("Nuclear", 200);
    grid.addPowerPlant("Solar", 50);

    // Adding Transmission Lines
    grid.addTransmissionLine(150, 50);
    grid.addTransmissionLine(300, 100);

    // Adding Substations
    grid.addSubstation();
    grid.addSubstation();
    grid.addSubstation();

    // Monitoring Power Plants and Substations
    grid.monitorPowerPlants();
    grid.monitorSubstations();

    // Optimize the grid (including fault detection, load balancing, and voltage regulation)
    grid.optimizeGrid();

    cout << "After optimization:" << endl;
    grid.monitorSubstations();

    return 0;
}

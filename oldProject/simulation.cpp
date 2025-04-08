#include "simulation.h"
#include <iostream>

Simulation::Simulation() : currProfile(0), timestepSinceUpdate(0) {}

bool Simulation::updateSimulation(int currentTimeStep) {
    return currentTimeStep - timestepSinceUpdate < 10;
}

void Simulation::switchProfile(int profileIndex) {
    if (profileIndex >= 0 && profileIndex < profiles.size()) {
        currProfile = profileIndex;
        std::cout << "Switched to profile " << profileIndex << "." << std::endl;
    } else {
        std::cout << "Invalid profile index." << std::endl;
    }
}

void Simulation::createProfile(std::string name, int basalRate, int carbRatio, int correctionFactor, int targetGlucose) {
    profiles.emplace_back(name);
    profiles.back().setBasalRates(basalRate);
    profiles.back().setCarbRatio(carbRatio);
    profiles.back().setCorrectionFactors(correctionFactor);
    profiles.back().setTargetGlucoseLvl(targetGlucose);

    std::cout << "Profile " << name << " created." << std::endl;
}

void Simulation::updateProfile(int profileIndex, int basalRate, int carbRatio, int correctionFactor, int targetGlucose) {
    if (profileIndex >= 0 && profileIndex < profiles.size()) {
        profiles[profileIndex].setBasalRates(basalRate);
        profiles[profileIndex].setCarbRatio(carbRatio);
        profiles[profileIndex].setCorrectionFactors(correctionFactor);
        profiles[profileIndex].setTargetGlucoseLvl(targetGlucose);

        std::cout << "Profile " << profileIndex << " updated." << std::endl;
    } else {
        std::cout << "Invalid profile index." << std::endl;
    }
}

void Simulation::deleteProfile(int profileIndex) {
    if (profileIndex >= 0 && profileIndex < profiles.size()) {
        profiles.erase(profiles.begin() + profileIndex);
        std::cout << "Profile " << profileIndex << " deleted." << std::endl;
    } else {
        std::cout << "Invalid profile index." << std::endl;
    }
}
/*
void Simulation::printAllProfiles() {
    if (profiles.empty()) {
        std::cout << "No profiles available." << std::endl;
        return;
    }

    for (size_t i = 0; i < profiles.size(); ++i) {
        std::cout << "Profile " << i << ":\n" << profiles[i].printRecords() << std::endl;
    }
}*/

// Stores the current profile's records in the Simulation log
void Simulation::storeCurrentProfileRecords() {
    if (currProfile >= 0 && currProfile < profiles.size()) {
        std::string records = profiles[currProfile].printRecords();
        simulationLogs.push_back(records);
        std::cout << "Records stored for current profile." << std::endl;
    } else {
        std::cout << "No profile selected!" << std::endl;
    }
}

// Prints all stored Simulation logs
void Simulation::printAllLogs() {
    if (simulationLogs.empty()) {
        std::cout << "No logs recorded yet." << std::endl;
        return;
    }
    std::cout << "=== Simulation Logs ===" << std::endl;
    for (const std::string& log : simulationLogs) {
        std::cout << log << std::endl;
    }
}

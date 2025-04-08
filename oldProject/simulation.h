#ifndef SIMULATION_H
#define SIMULATION_H

#include "insulinpump.h"
#include <vector>

class Simulation {
private:
    std::vector<InsulinPump> profiles;
    int currProfile;
    int timestepSinceUpdate;
    std::vector<std::string> simulationLogs;


public:
    Simulation();

    bool updateSimulation(int currentTimeStep);
    void switchProfile(int profileIndex);

    void createProfile(std::string name, int basalRate, int carbRatio, int correctionFactor, int targetGlucose);
    void updateProfile(int profileIndex, int basalRate, int carbRatio, int correctionFactor, int targetGlucose);
    void deleteProfile(int profileIndex);
    void storeCurrentProfileRecords();
    void printAllLogs();
    void printAllProfiles();
};

#endif

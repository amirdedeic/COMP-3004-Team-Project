#include "insulinpump.h"
#include <iostream>
#include <sstream>

// Constructor: Initializes an insulin pump profile with default settings
InsulinPump::InsulinPump(std::string name)
    : remainingInsulin(300), basalRates(0), carbRatio(1), correctionFactors(1),
      targetGlucoseLvl(5), pwd(0), insulinSuspended(false), batteryLevel(100) {
    std::cout << "Profile " << name << " created with default settings." << std::endl;
}

// Destructor: Called when an insulin pump profile is deleted
InsulinPump::~InsulinPump() {
    std::cout << "Profile deleted." << std::endl;
}

// Checks if the input PIN matches the stored password
bool InsulinPump::password(int PIN) {
    return PIN == pwd;
}

// Sets a new PIN, ensuring it is a valid 4-digit number
bool InsulinPump::setPIN(int PIN) {
    if (PIN > 999 && PIN < 10000) {
        pwd = PIN;
        return true;
    }
    return false;
}

// Sets the basal insulin rate
void InsulinPump::setBasalRates(int basalRate) {
    basalRates = basalRate;
}

// Sets the carbohydrate ratio (units of insulin per gram of carbs)
void InsulinPump::setCarbRatio(int ratio) {
    carbRatio = ratio;
}

// Sets the correction factor (how much one unit of insulin lowers glucose)
void InsulinPump::setCorrectionFactors(int factor) {
    correctionFactors = factor;
}

// Sets the target glucose level
void InsulinPump::setTargetGlucoseLvl(int level) {
    targetGlucoseLvl = level;
}

// Delivers a standard bolus (single dose of insulin)
void InsulinPump::deliverBolus(int bolusAmount) {
    if (insulinSuspended) {
        std::cout << "Insulin delivery is suspended!" << std::endl;
        return;
    }

    if (remainingInsulin >= bolusAmount) {
        remainingInsulin -= bolusAmount;
        logBolusEvent(bolusAmount, "Standard Bolus");
        std::cout << "Delivered " << bolusAmount << " units of insulin." << std::endl;
    } else {
        logError("Not enough insulin available.");
        std::cout << "Not enough insulin available." << std::endl;
    }
}

// Calculates and delivers a bolus based on current glucose and carb intake
int InsulinPump::manualBolus(int currentGlucose, int carboIntake) {
    if (insulinSuspended) {
        std::cout << "Insulin delivery is suspended!" << std::endl;
        return 0;
    }

    int foodBolus = carboIntake / carbRatio;
    int correctionBolus = (currentGlucose - targetGlucoseLvl) / correctionFactors;
    int totalBolus = foodBolus + correctionBolus;

    deliverBolus(totalBolus);
    return totalBolus;
}

// Suspends insulin delivery
void InsulinPump::suspendInsulinDelivery() {
    insulinSuspended = true;
    std::cout << "Insulin delivery suspended." << std::endl;
}

// Resumes insulin delivery
void InsulinPump::resumeInsulinDelivery() {
    insulinSuspended = false;
    std::cout << "Insulin delivery resumed." << std::endl;
}

// Logs bolus delivery events for record-keeping
void InsulinPump::logBolusEvent(int amount, std::string type) {
    history.push_back("Bolus: " + type + " - " + std::to_string(amount) + " units");
}

// Logs errors (e.g., insufficient insulin) for troubleshooting
void InsulinPump::logError(std::string errorMessage) {
    history.push_back("ERROR: " + errorMessage);
}

// Retrieves the insulin pump's log history
std::vector<std::string> InsulinPump::getHistory() {
    return history;
}

// Prints all stored settings and history logs.
std::string InsulinPump::printRecords() {
    std::ostringstream log;
    log << "Basal Rate: " << basalRates << "\n"
        << "Carb Ratio: " << carbRatio << "\n"
        << "Correction Factor: " << correctionFactors << "\n"
        << "Target Glucose: " << targetGlucoseLvl << "\n"
        << "Remaining Insulin: " << remainingInsulin << " units\n"
        << "Battery Level: " << batteryLevel << "%\n"
        << "Suspended: " << (insulinSuspended ? "Yes" : "No") << "\n";

    log << "History Log:\n";
    for (const auto& entry : history) {
        log << entry << "\n";
    }

    std::string logString = log.str();
    std::cout << logString; // Print log to console
    return logString; // Return log as a string
}

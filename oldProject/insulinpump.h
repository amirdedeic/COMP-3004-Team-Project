#ifndef INSULINPUMP_H
#define INSULINPUMP_H

#include <string>
#include <vector>

class InsulinPump {
private:
    int remainingInsulin;
    int basalRates;
    int carbRatio;
    int correctionFactors;
    int targetGlucoseLvl;
    int pwd;
    bool insulinSuspended;
    int batteryLevel;
    std::vector<std::string> history;

public:
    InsulinPump(std::string name);
    ~InsulinPump();

    bool password(int PIN);
    bool setPIN(int PIN);

    void setBasalRates(int basalRate);
    void setCarbRatio(int ratio);
    void setCorrectionFactors(int factor);
    void setTargetGlucoseLvl(int level);

    void deliverBolus(int bolusAmount);
    void deliverExtendedBolus(int totalBolus, float immediateFraction, int durationHours);
    int manualBolus(int currentGlucose, int carboIntake);

    void suspendInsulinDelivery();
    void resumeInsulinDelivery();

    void logBolusEvent(int amount, std::string type);
    void logError(std::string errorMessage);
    std::vector<std::string> getHistory();

    void integrateCGM(int currentGlucose);
    void checkBatteryStatus();
    void checkInsulinLevel();

    std::string printRecords();
};

#endif

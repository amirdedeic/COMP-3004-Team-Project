#include "simulation.h"
#include <QDebug>
#include <ctime>
#include <QRandomGenerator>
#include <cmath>

Simulation::Simulation(QObject* parent)
    : QObject(parent),
      simulationTimer(new QTimer(this)),
      simulationRunning(false),
      currentGlucoseLevel(100),
      currentProfileIndex(-1),
      controlIQEnabled(false),
      currentMode("Normal"),
      hypoPreventionThreshold(70),
      hyperPreventionThreshold(180),
      batteryLevel(1.0),
      insulinOnBoard(0.0),
      insulinLevel(1.0),
      cgmActive(true),
      glucoseTrend("→"),
      lastUpdateTime(QDateTime::currentDateTime())
{
    // Initialize the logs vector
    simulationLogs = QVector<QString>();
    
    // Connect the timer to update simulation
    connect(simulationTimer, &QTimer::timeout, this, &Simulation::updateSimulation);
    
    // Log initialization
    logSimulationEvent("Simulation initialized");
}

Simulation::~Simulation()
{
    // Clean up profiles
    for (int i = 0; i < profiles.size(); ++i) {
        delete profiles.at(i);
    }
    profiles.clear();
}

void Simulation::logSimulationEvent(const QString &message)
{
    // Use C++ standard library for time instead of QDateTime
    time_t now = time(nullptr);
    char buffer[80];
    
#ifdef _WIN32
    struct tm timeinfo;
    localtime_s(&timeinfo, &now);
    strftime(buffer, sizeof(buffer), "[%Y-%m-%d %H:%M:%S]", &timeinfo);
#else
    struct tm* timeinfo = localtime(&now);
    strftime(buffer, sizeof(buffer), "[%Y-%m-%d %H:%M:%S]", timeinfo);
#endif
    
    // Create log entry with timestamp
    QString logEntry = QString("%1 %2").arg(buffer).arg(message);
    simulationLogs.append(logEntry);
    
    qDebug() << "Log:" << logEntry;
}

QVector<QString> Simulation::getSimulationLogs() const
{
    return simulationLogs;
}

void Simulation::clearSimulationLogs()
{
    simulationLogs.clear();
    logSimulationEvent("Event logs cleared");
}

void Simulation::startSimulation(int intervalMs)
{
    if (!simulationRunning) {
        simulationTimer->start(intervalMs);
        simulationRunning = true;
        logSimulationEvent("Simulation started");
    }
}

void Simulation::stopSimulation()
{
    if (simulationRunning) {
        simulationTimer->stop();
        simulationRunning = false;
        logSimulationEvent("Simulation stopped");
    }
}

int Simulation::getGlucoseLevel() const
{
    return currentGlucoseLevel;
}

void Simulation::setGlucoseLevel(int level)
{
    if (level >= 40 && level <= 400) {
        currentGlucoseLevel = level;
        logSimulationEvent("Glucose level set to: " + QString::number(level) + " mg/dL");
        emit glucoseLevelChanged(level);
        
        // Notify the active profile about the glucose level
        if (InsulinPump* profile = getCurrentProfile()) {
            profile->integrateCGM(level);
        }
    } else {
        logSimulationEvent("Error: Invalid glucose level: " + QString::number(level));
    }
}

bool Simulation::isSimulationRunning() const
{
    return simulationRunning;
}

// Profile management methods
void Simulation::createProfile(const QString &name, int basalRate, int carbRatio, int correctionFactor, int targetGlucoseLevel)
{
    // Create a new insulin pump profile
    InsulinPump* newProfile = new InsulinPump(name);
    
    // Configure the profile
    newProfile->setBasalRate(basalRate);
    newProfile->setCarbRatio(carbRatio);
    newProfile->setCorrectionFactor(correctionFactor);
    newProfile->setTargetGlucoseLevel(targetGlucoseLevel);
    
    // Add to profiles
    profiles.append(newProfile);
    
    // If this is the first profile, make it active
    if (currentProfileIndex == -1) {
        currentProfileIndex = 0;
    }
    
    logSimulationEvent("Created profile: " + name);
    emit profilesChanged();
}

void Simulation::updateCurrentProfile(int basalRate, int carbRatio, int correctionFactor, int targetGlucoseLevel)
{
    if (currentProfileIndex >= 0 && currentProfileIndex < profiles.size()) {
        InsulinPump* profile = profiles[currentProfileIndex];
        profile->setBasalRate(basalRate);
        profile->setCarbRatio(carbRatio);
        profile->setCorrectionFactor(correctionFactor);
        profile->setTargetGlucoseLevel(targetGlucoseLevel);
        
        logSimulationEvent("Updated profile: " + profile->getProfileName());
        emit profilesChanged();
    } else {
        logSimulationEvent("Error: No active profile to update");
    }
}

void Simulation::deleteProfile(int profileIndex)
{
    if (profileIndex >= 0 && profileIndex < profiles.size()) {
        QString profileName = profiles[profileIndex]->getProfileName();
        delete profiles[profileIndex];
        profiles.remove(profileIndex);
        
        // Update current profile index if needed
        if (profiles.isEmpty()) {
            currentProfileIndex = -1;
        } else if (currentProfileIndex >= profileIndex) {
            currentProfileIndex = qMax(0, currentProfileIndex - 1);
        }
        
        logSimulationEvent("Deleted profile: " + profileName);
        emit profilesChanged();
    } else {
        logSimulationEvent("Error: Invalid profile index for deletion");
    }
}

void Simulation::switchProfile(int profileIndex)
{
    if (profileIndex >= 0 && profileIndex < profiles.size() && profileIndex != currentProfileIndex) {
        currentProfileIndex = profileIndex;
        logSimulationEvent("Switched to profile: " + profiles[currentProfileIndex]->getProfileName());
        emit profilesChanged();
    } else if (profileIndex < 0 || profileIndex >= profiles.size()) {
        logSimulationEvent("Error: Invalid profile index for switching");
    }
}

InsulinPump* Simulation::getCurrentProfile() const
{
    if (currentProfileIndex >= 0 && currentProfileIndex < profiles.size()) {
        return profiles[currentProfileIndex];
    }
    return nullptr;
}

QVector<InsulinPump*> Simulation::getAllProfiles() const
{
    return profiles;
}

int Simulation::getCurrentProfileIndex() const
{
    return currentProfileIndex;
}

int Simulation::getProfileCount() const
{
    return profiles.size();
}

// Control-IQ technology methods
void Simulation::enableControlIQ(bool enable)
{
    controlIQEnabled = enable;
    logSimulationEvent("Control-IQ technology " + QString(enable ? "enabled" : "disabled"));
    emit controlIQStateChanged(enable);
}

bool Simulation::isControlIQEnabled() const
{
    return controlIQEnabled;
}

void Simulation::setControlIQMode(const QString &mode)
{
    if (mode == "Normal" || mode == "Sleep" || mode == "Exercise") {
        currentMode = mode;
        logSimulationEvent("Control-IQ mode set to: " + mode);
        emit controlIQModeChanged(mode);
    } else {
        logSimulationEvent("Error: Invalid Control-IQ mode: " + mode);
    }
}

QString Simulation::getControlIQMode() const
{
    return currentMode;
}

void Simulation::setHypoPreventionThreshold(int threshold)
{
    if (threshold >= 60 && threshold <= 90) {
        hypoPreventionThreshold = threshold;
        logSimulationEvent("Hypo prevention threshold set to: " + QString::number(threshold) + " mg/dL");
    } else {
        logSimulationEvent("Error: Invalid hypo prevention threshold: " + QString::number(threshold));
    }
}

void Simulation::setHyperPreventionThreshold(int threshold)
{
    if (threshold >= 140 && threshold <= 200) {
        hyperPreventionThreshold = threshold;
        logSimulationEvent("Hyper prevention threshold set to: " + QString::number(threshold) + " mg/dL");
    } else {
        logSimulationEvent("Error: Invalid hyper prevention threshold: " + QString::number(threshold));
    }
}

int Simulation::getHypoPreventionThreshold() const
{
    return hypoPreventionThreshold;
}

int Simulation::getHyperPreventionThreshold() const
{
    return hyperPreventionThreshold;
}

int Simulation::calculateControlIQBasalAdjustment() const
{
    if (!controlIQEnabled) {
        return 0;
    }
    
    // Adjustment logic based on glucose levels and active mode
    int adjustment = 0;
    
    // Handle low glucose - reduce insulin
    if (currentGlucoseLevel < hypoPreventionThreshold + 20) {
        adjustment = -1; // Reduce by 1 unit/hour
    }
    // Handle high glucose - increase insulin
    else if (currentGlucoseLevel > hyperPreventionThreshold - 20) {
        adjustment = 1; // Increase by 1 unit/hour
    }
    
    // Mode-specific adjustments
    if (currentMode == "Sleep") {
        // More conservative during sleep
        adjustment = qMax(-1, qMin(1, adjustment)); // Limit to +/- 1 unit/hour
    } 
    else if (currentMode == "Exercise") {
        // More aggressive reduction during exercise
        if (adjustment < 0) {
            adjustment *= 2; // Double any reduction
        }
    }
    
    return adjustment;
}

bool Simulation::shouldSuspendInsulin() const
{
    if (!controlIQEnabled) {
        return false;
    }
    
    // Suspend if glucose is below the hypo prevention threshold or predicted to go below
    return (currentGlucoseLevel <= hypoPreventionThreshold);
}

void Simulation::updateSimulation()
{
    if (!simulationRunning) return;

    // Update home screen data
    updateHomeScreenData();

    // Update glucose level based on current trend
    if (glucoseTrend == "↑↑↑") {
        currentGlucoseLevel += 3;
    } else if (glucoseTrend == "↑↑") {
        currentGlucoseLevel += 2;
    } else if (glucoseTrend == "↑") {
        currentGlucoseLevel += 1;
    } else if (glucoseTrend == "↓↓↓") {
        currentGlucoseLevel -= 3;
    } else if (glucoseTrend == "↓↓") {
        currentGlucoseLevel -= 2;
    } else if (glucoseTrend == "↓") {
        currentGlucoseLevel -= 1;
    }

    // Ensure glucose level stays within reasonable bounds
    currentGlucoseLevel = qBound(40, currentGlucoseLevel, 400);

    // Emit signals
    emit glucoseLevelChanged(currentGlucoseLevel);
    emit simulationUpdated();

    // Log the update
    logSimulationEvent(QString("Glucose level: %1 mg/dL, Trend: %2")
                      .arg(currentGlucoseLevel)
                      .arg(glucoseTrend));
}

// Home Screen specific methods
double Simulation::getBatteryLevel() const
{
    return batteryLevel;
}

double Simulation::getInsulinOnBoard() const
{
    return insulinOnBoard;
}

double Simulation::getInsulinLevel() const
{
    return insulinLevel;
}

bool Simulation::isCGMActive() const
{
    return cgmActive;
}

QString Simulation::getGlucoseTrend() const
{
    return glucoseTrend;
}

QDateTime Simulation::getLastUpdateTime() const
{
    return lastUpdateTime;
}

void Simulation::updateHomeScreenData()
{
    // Update battery level (simulate slow discharge)
    batteryLevel = qMax(0.0, batteryLevel - 0.001);
    emit batteryLevelChanged(batteryLevel);

    // Update insulin on board (simulate decay)
    insulinOnBoard = qMax(0.0, insulinOnBoard - 0.1);
    emit insulinOnBoardChanged(insulinOnBoard);

    // Update insulin level (simulate usage)
    insulinLevel = qMax(0.0, insulinLevel - 0.005);
    emit insulinLevelChanged(insulinLevel);

    // Update CGM status (simulate occasional disconnections)
    if (QRandomGenerator::global()->bounded(1000) == 0) { // 0.1% chance of status change
        cgmActive = !cgmActive;
        emit cgmStatusChanged(cgmActive);
    }

    // Update glucose trend
    QString newTrend;
    if (currentGlucoseLevel > 180) {
        newTrend = "↑↑↑";
    } else if (currentGlucoseLevel > 140) {
        newTrend = "↑↑";
    } else if (currentGlucoseLevel > 100) {
        newTrend = "↑";
    } else if (currentGlucoseLevel < 70) {
        newTrend = "↓↓↓";
    } else if (currentGlucoseLevel < 90) {
        newTrend = "↓↓";
    } else if (currentGlucoseLevel < 100) {
        newTrend = "↓";
    } else {
        newTrend = "→";
    }

    if (newTrend != glucoseTrend) {
        glucoseTrend = newTrend;
        emit glucoseTrendChanged(glucoseTrend);
    }

    // Update last update time
    lastUpdateTime = QDateTime::currentDateTime();
} 
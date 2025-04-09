#ifndef SIMULATION_H
#define SIMULATION_H

#include <QObject>
#include <QVector>
#include <QString>
#include <QTimer>
#include <QDateTime>
#include "insulinpump.h"

class Simulation : public QObject
{
    Q_OBJECT

private:
    QVector<QString> simulationLogs;
    QTimer* simulationTimer;
    bool simulationRunning;
    int currentGlucoseLevel;
    
    // Profile management
    QVector<InsulinPump*> profiles;
    int currentProfileIndex;
    
    // Control-IQ technology
    bool controlIQEnabled;
    QString currentMode;  // "Sleep", "Exercise", or "Normal"
    int hypoPreventionThreshold;  // Default 70 mg/dL
    int hyperPreventionThreshold; // Default 180 mg/dL

    // Home Screen specific data
    double batteryLevel;
    double insulinOnBoard;
    double insulinLevel;
    bool cgmActive;
    QString glucoseTrend;
    QDateTime lastUpdateTime;

public:
    explicit Simulation(QObject* parent = nullptr);
    ~Simulation();
    
    // Core functionality
    void logSimulationEvent(const QString &message);
    QVector<QString> getSimulationLogs() const;
    void clearSimulationLogs();
    
    // Minimal simulation controls
    void startSimulation(int intervalMs = 1000);
    void stopSimulation();
    int getGlucoseLevel() const;
    void setGlucoseLevel(int level);
    bool isSimulationRunning() const;
    
    // Profile management
    void createProfile(const QString &name, int basalRate = 1, int carbRatio = 15, 
                      int correctionFactor = 50, int targetGlucoseLevel = 100);
    void updateCurrentProfile(int basalRate, int carbRatio, int correctionFactor, int targetGlucoseLevel);
    void deleteProfile(int profileIndex);
    void switchProfile(int profileIndex);
    InsulinPump* getCurrentProfile() const;
    QVector<InsulinPump*> getAllProfiles() const;
    int getCurrentProfileIndex() const;
    int getProfileCount() const;
    
    // Control-IQ technology
    void enableControlIQ(bool enable);
    bool isControlIQEnabled() const;
    void setControlIQMode(const QString &mode);
    QString getControlIQMode() const;
    void setHypoPreventionThreshold(int threshold);
    void setHyperPreventionThreshold(int threshold);
    int getHypoPreventionThreshold() const;
    int getHyperPreventionThreshold() const;

    // Home Screen specific methods
    double getBatteryLevel() const;
    double getInsulinOnBoard() const;
    double getInsulinLevel() const;
    bool isCGMActive() const;
    QString getGlucoseTrend() const;
    QDateTime getLastUpdateTime() const;
    void updateHomeScreenData();

signals:
    void simulationUpdated();
    void glucoseLevelChanged(int newLevel);
    void profilesChanged();
    void controlIQStateChanged(bool enabled);
    void controlIQModeChanged(const QString &mode);
    void batteryLevelChanged(double level);
    void insulinOnBoardChanged(double iob);
    void insulinLevelChanged(double level);
    void cgmStatusChanged(bool active);
    void glucoseTrendChanged(const QString &trend);

private slots:
    void updateSimulation();
    
private:
    // Control-IQ helper methods
    int calculateControlIQBasalAdjustment() const; // Return adjustment in units per hour
    bool shouldSuspendInsulin() const;  // Check if insulin should be suspended
};

#endif // SIMULATION_H 
#ifndef INSULINPUMP_H
#define INSULINPUMP_H

#include <QString>
#include <QVector>

class InsulinPump
{
private:
    QString profileName;
    int basalRate;
    int carbRatio;
    int correctionFactor;
    int targetGlucoseLevel;
    int remainingInsulin;
    bool insulinSuspended;
    QVector<QString> events;

public:
    InsulinPump(const QString &name = "Default Profile");
    ~InsulinPump();
    
    // Basic profile management
    QString getProfileName() const;
    void setProfileName(const QString &name);
    
    // Insulin pump settings
    int getBasalRate() const;
    void setBasalRate(int rate);
    
    int getCarbRatio() const;
    void setCarbRatio(int ratio);
    
    int getCorrectionFactor() const;
    void setCorrectionFactor(int factor);
    
    int getTargetGlucoseLevel() const;
    void setTargetGlucoseLevel(int level);
    
    // Insulin management
    bool isInsulinSuspended() const;
    void suspendInsulinDelivery();
    void resumeInsulinDelivery();
    
    int getRemainingInsulin() const;
    void refillInsulin(int units);
    
    // Bolus calculation and delivery
    int calculateBolus(int currentGlucose, int carbIntake);
    void deliverBolus(int units);
    
    // CGM integration
    void integrateCGM(int glucoseLevel);
    
    // Event logging
    void logEvent(const QString &event);
    QVector<QString> getEvents() const;
};

#endif // INSULINPUMP_H 
#include "insulinpump.h"
#include <QDebug>

InsulinPump::InsulinPump(const QString &name)
    : profileName(name),
      basalRate(1),                 // Default: 1 unit per hour
      carbRatio(15),                // Default: 1 unit per 15g of carbs
      correctionFactor(50),         // Default: 1 unit reduces glucose by 50 mg/dL
      targetGlucoseLevel(100),      // Default: 100 mg/dL
      remainingInsulin(300),        // Default: 300 units in reservoir
      insulinSuspended(false)
{
    logEvent("Profile created");
}

InsulinPump::~InsulinPump()
{
    // No dynamic allocations to clean up
}

// Basic profile management
QString InsulinPump::getProfileName() const
{
    return profileName;
}

void InsulinPump::setProfileName(const QString &name)
{
    profileName = name;
    logEvent("Profile name changed to: " + name);
}

// Insulin pump settings
int InsulinPump::getBasalRate() const
{
    return basalRate;
}

void InsulinPump::setBasalRate(int rate)
{
    if (rate >= 0 && rate <= 5) {
        basalRate = rate;
        logEvent("Basal rate set to: " + QString::number(rate) + " U/hr");
    } else {
        qDebug() << "Invalid basal rate: " << rate;
    }
}

int InsulinPump::getCarbRatio() const
{
    return carbRatio;
}

void InsulinPump::setCarbRatio(int ratio)
{
    if (ratio > 0 && ratio <= 50) {
        carbRatio = ratio;
        logEvent("Carb ratio set to: " + QString::number(ratio) + " g/U");
    } else {
        qDebug() << "Invalid carb ratio: " << ratio;
    }
}

int InsulinPump::getCorrectionFactor() const
{
    return correctionFactor;
}

void InsulinPump::setCorrectionFactor(int factor)
{
    if (factor > 0 && factor <= 100) {
        correctionFactor = factor;
        logEvent("Correction factor set to: " + QString::number(factor) + " mg/dL/U");
    } else {
        qDebug() << "Invalid correction factor: " << factor;
    }
}

int InsulinPump::getTargetGlucoseLevel() const
{
    return targetGlucoseLevel;
}

void InsulinPump::setTargetGlucoseLevel(int level)
{
    if (level >= 80 && level <= 150) {
        targetGlucoseLevel = level;
        logEvent("Target glucose level set to: " + QString::number(level) + " mg/dL");
    } else {
        qDebug() << "Invalid target glucose level: " << level;
    }
}

// Insulin management
bool InsulinPump::isInsulinSuspended() const
{
    return insulinSuspended;
}

void InsulinPump::suspendInsulinDelivery()
{
    insulinSuspended = true;
    logEvent("Insulin delivery suspended");
}

void InsulinPump::resumeInsulinDelivery()
{
    insulinSuspended = false;
    logEvent("Insulin delivery resumed");
}

int InsulinPump::getRemainingInsulin() const
{
    return remainingInsulin;
}

void InsulinPump::refillInsulin(int units)
{
    if (units >= 0 && units <= 300) {
        remainingInsulin = units;
        if (units == 300) {
            logEvent("Insulin reservoir refilled to maximum capacity");
        } else {
            logEvent("Insulin reservoir set to: " + QString::number(units) + " units");
        }
    } else {
        qDebug() << "Invalid insulin amount: " << units;
    }
}

// Bolus calculation and delivery
int InsulinPump::calculateBolus(int currentGlucose, int carbIntake)
{
    if (insulinSuspended) {
        logEvent("Bolus calculation failed: Insulin delivery suspended");
        return 0;
    }
    
    // Calculate food bolus
    int foodBolus = carbIntake / carbRatio;
    
    // Calculate correction bolus
    int glucoseDiff = currentGlucose - targetGlucoseLevel;
    int correctionBolus = 0;
    
    if (glucoseDiff > 0) {
        correctionBolus = glucoseDiff / correctionFactor;
    }
    
    // Total bolus
    int totalBolus = foodBolus + correctionBolus;
    
    // Cap to remaining insulin
    if (totalBolus > remainingInsulin) {
        totalBolus = remainingInsulin;
    }
    
    logEvent("Bolus calculated: " + QString::number(totalBolus) + " U (Food: " + 
             QString::number(foodBolus) + " U, Correction: " + QString::number(correctionBolus) + " U)");
    
    return totalBolus;
}

void InsulinPump::deliverBolus(int units)
{
    if (insulinSuspended) {
        logEvent("Bolus delivery failed: Insulin delivery suspended");
        return;
    }
    
    if (units <= 0) {
        logEvent("Bolus delivery failed: Invalid amount");
        return;
    }
    
    if (units > remainingInsulin) {
        int delivered = remainingInsulin;
        remainingInsulin = 0;
        logEvent("Delivered " + QString::number(delivered) + " U bolus (partial - reservoir empty)");
    } else {
        remainingInsulin -= units;
        logEvent("Delivered " + QString::number(units) + " U bolus");
    }
}

// CGM integration
void InsulinPump::integrateCGM(int glucoseLevel)
{
    logEvent("CGM reading: " + QString::number(glucoseLevel) + " mg/dL");
    
    // In a real implementation, this might do more with the glucose reading
}

// Event logging
void InsulinPump::logEvent(const QString &event)
{
    events.append(event);
    qDebug() << "Pump event:" << event;
}

QVector<QString> InsulinPump::getEvents() const
{
    return events;
} 
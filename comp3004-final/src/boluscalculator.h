#ifndef BOLUSCALCULATOR_H
#define BOLUSCALCULATOR_H

#include <QWidget>
#include "simulation.h"

namespace Ui {
class BolusCalculator;
}

class BolusCalculator : public QWidget
{
    Q_OBJECT

public:
    explicit BolusCalculator(QWidget *parent = nullptr);
    ~BolusCalculator();

    void setSimulation(Simulation *sim);
    void updateDisplay();

signals:
    // Signal to navigate back
    void navigateBack();
    
    // Signal to navigate to home
    void navigateToHome();
    
    // Signal to emit when bolus is delivered
    void bolusDelivered(double units);

private slots:
    // Navigation slots
    void on_backButton_clicked();
    void on_nextButton_clicked();
    void on_homeButton_clicked();
    
    // Input slots
    void on_carbsButton_clicked();
    void on_bgButton_clicked();
    void on_viewCalculationButton_clicked();

private:
    Ui::BolusCalculator *ui;
    Simulation *simulation;
    
    // Bolus calculation state
    double carbAmount;
    double bgAmount;
    double bolusAmount;
    
    // Calculate bolus based on inputs
    void calculateBolus();
    
    // Show different stages of the wizard
    void showBolusConfirmation();
    void showDeliveryOptions();
};

#endif // BOLUSCALCULATOR_H 
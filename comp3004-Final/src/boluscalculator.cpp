#include "boluscalculator.h"
#include "ui_boluscalculator.h"
#include <QInputDialog>
#include <QMessageBox>

BolusCalculator::BolusCalculator(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BolusCalculator),
    simulation(nullptr),
    carbAmount(0),
    bgAmount(0),
    bolusAmount(0)
{
    ui->setupUi(this);
    
    // Connect signals and slots
    connect(ui->backButton, &QPushButton::clicked, this, &BolusCalculator::on_backButton_clicked);
    connect(ui->nextButton, &QPushButton::clicked, this, &BolusCalculator::on_nextButton_clicked);
    connect(ui->homeButton, &QPushButton::clicked, this, &BolusCalculator::on_homeButton_clicked);
    connect(ui->carbsButton, &QPushButton::clicked, this, &BolusCalculator::on_carbsButton_clicked);
    connect(ui->bgButton, &QPushButton::clicked, this, &BolusCalculator::on_bgButton_clicked);
    connect(ui->viewCalculationButton, &QPushButton::clicked, this, &BolusCalculator::on_viewCalculationButton_clicked);
    
    // Initialize UI
    ui->wizardStack->setVisible(false);
    updateDisplay();
}

BolusCalculator::~BolusCalculator()
{
    delete ui;
}

void BolusCalculator::setSimulation(Simulation *sim)
{
    simulation = sim;
}

void BolusCalculator::updateDisplay()
{
    // Update the bolus amount display
    ui->bolusAmountLabel->setText(QString::number(bolusAmount, 'f', 1) + " units");
    
    // Update carbs display
    if (carbAmount > 0) {
        ui->carbsButton->setText(QString::number(carbAmount, 'f', 0) + " grams");
    } else {
        ui->carbsButton->setText("0 grams");
    }
    
    // Update BG display
    if (bgAmount > 0) {
        ui->bgButton->setText(QString::number(bgAmount, 'f', 0) + " mg/dL");
    } else {
        ui->bgButton->setText("Add BG");
    }
}

void BolusCalculator::calculateBolus()
{
    if (!simulation) return;
    
    InsulinPump* currentProfile = simulation->getCurrentProfile();
    if (!currentProfile) return;
    
    double carbInsulin = 0;
    double correctionInsulin = 0;
    
    // Calculate insulin for carbs
    if (carbAmount > 0) {
        int carbRatio = currentProfile->getCarbRatio();
        if (carbRatio > 0) {
            carbInsulin = carbAmount / carbRatio;
        }
    }
    
    // Calculate correction insulin if BG is entered
    if (bgAmount > 0) {
        int targetBG = currentProfile->getTargetGlucoseLevel();
        int correctionFactor = currentProfile->getCorrectionFactor();
        
        if (bgAmount > targetBG && correctionFactor > 0) {
            correctionInsulin = (bgAmount - targetBG) / correctionFactor;
        }
    }
    
    // Calculate total bolus (ignoring IOB for now - would be subtracted in a real implementation)
    bolusAmount = carbInsulin + correctionInsulin;
    
    // Ensure bolus is not negative
    if (bolusAmount < 0) bolusAmount = 0;
    
    // Update display
    updateDisplay();
}

void BolusCalculator::on_backButton_clicked()
{
    // Navigate back to previous screen
    emit navigateBack();
}

void BolusCalculator::on_nextButton_clicked()
{
    // If we have a bolus calculated, show confirmation
    if (bolusAmount > 0) {
        showBolusConfirmation();
    } else {
        QMessageBox::information(this, "No Bolus", "Enter carbs or blood glucose to calculate a bolus.");
    }
}

void BolusCalculator::on_homeButton_clicked()
{
    // Navigate to home screen
    emit navigateToHome();
}

void BolusCalculator::on_carbsButton_clicked()
{
    // Show dialog to enter carbs
    bool ok;
    double carbs = QInputDialog::getDouble(this, "Enter Carbohydrates", 
                                         "Grams of carbs:", 
                                         carbAmount, 0, 999, 0, &ok);
    if (ok) {
        carbAmount = carbs;
        calculateBolus();
    }
}

void BolusCalculator::on_bgButton_clicked()
{
    // Show dialog to enter blood glucose
    bool ok;
    double bg = QInputDialog::getDouble(this, "Enter Blood Glucose", 
                                      "Blood glucose (mg/dL):", 
                                      bgAmount > 0 ? bgAmount : simulation ? simulation->getGlucoseLevel() : 100,
                                      40, 400, 0, &ok);
    if (ok) {
        bgAmount = bg;
        calculateBolus();
    }
}

void BolusCalculator::on_viewCalculationButton_clicked()
{
    if (!simulation) return;
    
    InsulinPump* currentProfile = simulation->getCurrentProfile();
    if (!currentProfile) return;
    
    // Calculate components for display
    double carbInsulin = 0;
    if (carbAmount > 0) {
        int carbRatio = currentProfile->getCarbRatio();
        if (carbRatio > 0) {
            carbInsulin = carbAmount / carbRatio;
        }
    }
    
    double correctionInsulin = 0;
    if (bgAmount > 0) {
        int targetBG = currentProfile->getTargetGlucoseLevel();
        int correctionFactor = currentProfile->getCorrectionFactor();
        
        if (bgAmount > targetBG && correctionFactor > 0) {
            correctionInsulin = (bgAmount - targetBG) / correctionFactor;
        }
    }
    
    // Format the calculation details
    QString details = "Bolus Calculation Details:\n\n";
    details += "Active Profile: " + currentProfile->getProfileName() + "\n\n";
    
    if (carbAmount > 0) {
        details += "Food Bolus:\n";
        details += QString::number(carbAmount) + " g ÷ " + 
                  QString::number(currentProfile->getCarbRatio()) + " g/u = " + 
                  QString::number(carbInsulin, 'f', 2) + " units\n\n";
    }
    
    if (bgAmount > 0) {
        details += "Correction Bolus:\n";
        details += "Current BG: " + QString::number(bgAmount) + " mg/dL\n";
        details += "Target BG: " + QString::number(currentProfile->getTargetGlucoseLevel()) + " mg/dL\n";
        details += "Correction Factor: " + QString::number(currentProfile->getCorrectionFactor()) + " mg/dL/u\n";
        details += "Correction: " + QString::number(correctionInsulin, 'f', 2) + " units\n\n";
    }
    
    details += "Total Bolus: " + QString::number(bolusAmount, 'f', 1) + " units";
    
    // Show calculation details
    QMessageBox::information(this, "Bolus Calculation", details);
}

void BolusCalculator::showBolusConfirmation()
{
    // In a complete implementation, this would show a confirmation screen
    // For now, we'll use a message box
    QString confirmMsg = "Confirm Bolus Request?\n\n";
    confirmMsg += "Carbs: " + QString::number(carbAmount, 'f', 0) + " g\n";
    confirmMsg += "BG: " + (bgAmount > 0 ? QString::number(bgAmount, 'f', 0) + " mg/dL" : "NA") + "\n";
    confirmMsg += "Units To Deliver: " + QString::number(bolusAmount, 'f', 1) + " u";
    
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirm Bolus", confirmMsg,
                                 QMessageBox::Yes | QMessageBox::No);
    
    if (reply == QMessageBox::Yes) {
        showDeliveryOptions();
    }
}

void BolusCalculator::showDeliveryOptions()
{
    // In a complete implementation, this would show a delivery options screen
    // For now, we'll use a message box
    QString deliveryMsg = "Deliver " + QString::number(bolusAmount, 'f', 1) + " u Bolus?\n\n";
    deliveryMsg += QString("Correction: %1\n").arg(bgAmount > 0 ? "Yes" : "NA");
    deliveryMsg += "EXTENDED: OFF\n";
    deliveryMsg += "Food: " + QString::number(bolusAmount, 'f', 1) + " u";
    
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Deliver Bolus", deliveryMsg,
                                 QMessageBox::Yes | QMessageBox::No);
    
    if (reply == QMessageBox::Yes) {
        // Log the bolus delivery
        if (simulation) {
            simulation->logSimulationEvent("Delivered bolus: " + QString::number(bolusAmount, 'f', 1) + " units");
        }
        
        // Emit signal that bolus was delivered
        emit bolusDelivered(bolusAmount);
        
        // Reset the calculator for next use
        carbAmount = 0;
        bgAmount = 0;
        bolusAmount = 0;
        updateDisplay();
        
        // Show confirmation
        QMessageBox::information(this, "Bolus Delivered", 
                                "Bolus of " + QString::number(bolusAmount, 'f', 1) + 
                                " units has been delivered.");
        
        // Navigate back to home
        emit navigateToHome();
    }
} 
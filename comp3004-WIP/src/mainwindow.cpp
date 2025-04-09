#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dbmanager.h"
#include "homescreen.h"
#include "boluscalculator.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    simulation(new Simulation(this)),
    screenManager(new ScreenManager(this)),
    screenStack(new QStackedWidget(this))
{
    ui->setupUi(this);
    
    // Basic window setup
    resize(800, 600);
    setWindowTitle("Insulin Pump Simulator");
    
    // Connect to database
    DBManager db;
    if (db.openDB()) {
        qDebug() << "Database: connection ok";
    } else {
        qDebug() << "Database: connection failed";
    }
    
    // Set up screen stack in the main window
    ui->verticalLayout->insertWidget(0, screenStack);
    
    // Initialize the screen manager
    screenManager->setStackedWidget(screenStack);
    screenManager->setSimulation(simulation);
    screenManager->initializeScreens();
    
    // Connect screen navigation signals
    connect(screenManager, &ScreenManager::screenChanged, this, &MainWindow::onScreenChanged);
    
    // Connect navigation signals from HomeScreen to ScreenManager
    HomeScreen* homeScreen = qobject_cast<HomeScreen*>(screenStack->widget(0));
    if (homeScreen) {
        connect(homeScreen, &HomeScreen::navigateToBolusCalculator, [this]() {
            screenManager->navigateTo(ScreenManager::BolusCalculatorType);
        });
    }
    
    // Connect navigation signals from BolusCalculator to ScreenManager
    BolusCalculator* bolusCalc = qobject_cast<BolusCalculator*>(screenStack->widget(1));
    if (bolusCalc) {
        connect(bolusCalc, &BolusCalculator::navigateBack, [this]() {
            screenManager->goBack();
        });
        
        connect(bolusCalc, &BolusCalculator::navigateToHome, [this]() {
            screenManager->goHome();
        });
        
        connect(bolusCalc, &BolusCalculator::bolusDelivered, [this](double units) {
            // Handle bolus delivery
            qDebug() << "Bolus delivered:" << units << "units";
        });
    }
    
    // First connect UI signals/slots
    connect(simulation, &Simulation::simulationUpdated, this, &MainWindow::updateUI);
    connect(simulation, &Simulation::profilesChanged, this, &MainWindow::populateProfileComboBox);
    connect(simulation, &Simulation::glucoseLevelChanged, [this](int level) {
        ui->statusBar->showMessage("Glucose level: " + QString::number(level) + " mg/dL", 3000);
    });
    
    // Connect home screen signals
    connect(simulation, &Simulation::batteryLevelChanged, homeScreen, &HomeScreen::updateDisplay);
    connect(simulation, &Simulation::insulinOnBoardChanged, homeScreen, &HomeScreen::updateDisplay);
    connect(simulation, &Simulation::insulinLevelChanged, homeScreen, &HomeScreen::updateDisplay);
    connect(simulation, &Simulation::cgmStatusChanged, homeScreen, &HomeScreen::updateDisplay);
    connect(simulation, &Simulation::glucoseTrendChanged, homeScreen, &HomeScreen::updateDisplay);
    
    // Block signals on profile combo box before creating the default profile
    ui->profileComboBox->blockSignals(true);
    
    // Create a default profile
    simulation->createProfile("Default Profile");
    
    // Initialize Control-IQ UI
    ui->controlIQCheckBox->setChecked(simulation->isControlIQEnabled());
    ui->modeComboBox->setCurrentText(simulation->getControlIQMode());
    ui->hypoThresholdSpinBox->setValue(simulation->getHypoPreventionThreshold());
    ui->hyperThresholdSpinBox->setValue(simulation->getHyperPreventionThreshold());
    
    // Initially disable Control-IQ settings if Control-IQ is disabled
    bool controlIQEnabled = simulation->isControlIQEnabled();
    ui->modeComboBox->setEnabled(controlIQEnabled);
    ui->hypoThresholdSpinBox->setEnabled(controlIQEnabled);
    ui->hyperThresholdSpinBox->setEnabled(controlIQEnabled);
    
    // Initialize UI
    updateUI();
    populateProfileComboBox();
    
    // Unblock signals after initialization is complete
    ui->profileComboBox->blockSignals(false);
    
    // Navigate to the home screen
    screenManager->goHome();
    
    // Log that we're ready
    simulation->logSimulationEvent("Application started");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateUI()
{
    // Update UI based on simulation state
    bool isRunning = simulation->isSimulationRunning();
    QString status = isRunning ? "Running" : "Stopped";
    ui->statusBar->showMessage("Simulation Status: " + status);
    
    // Enable/disable buttons based on state
    ui->startButton->setEnabled(!isRunning);
    ui->stopButton->setEnabled(isRunning);
    
    // Enable/disable profile controls based on simulation state
    ui->profileGroupBox->setEnabled(!isRunning);
    ui->controlIQGroupBox->setEnabled(true); // Control-IQ can be toggled anytime
    
    // Get the logs and display them
    QVector<QString> logs = simulation->getSimulationLogs();
    
    // Display logs in the text edit
    ui->logTextEdit->clear();
    for (const QString &logEntry : logs) {
        ui->logTextEdit->append(logEntry);
    }
    
    // Scroll to bottom
    QTextCursor cursor = ui->logTextEdit->textCursor();
    cursor.movePosition(QTextCursor::End);
    ui->logTextEdit->setTextCursor(cursor);
}

void MainWindow::on_startButton_clicked()
{
    simulation->startSimulation(1000); // Update every 1 second
    updateUI();
}

void MainWindow::on_stopButton_clicked()
{
    simulation->stopSimulation();
    updateUI();
}

// Profile management
void MainWindow::populateProfileComboBox()
{
    // Temporarily block signals to prevent infinite loop
    ui->profileComboBox->blockSignals(true);
    
    ui->profileComboBox->clear();
    
    QVector<InsulinPump*> profiles = simulation->getAllProfiles();
    for (int i = 0; i < profiles.size(); ++i) {
        ui->profileComboBox->addItem(profiles.at(i)->getProfileName());
    }
    
    // Set the current index to match the simulation's current profile
    ui->profileComboBox->setCurrentIndex(simulation->getCurrentProfileIndex());
    
    // Re-enable signals
    ui->profileComboBox->blockSignals(false);
}

void MainWindow::on_createProfileButton_clicked()
{
    // Get profile name from user
    bool ok;
    QString name = QInputDialog::getText(this, "Create Profile", 
                                        "Enter profile name:", 
                                        QLineEdit::Normal, 
                                        "New Profile", &ok);
    if (ok && !name.isEmpty()) {
        // Create the profile with default settings
        simulation->createProfile(name);
        
        // Update UI
        populateProfileComboBox();
    }
}

void MainWindow::on_deleteProfileButton_clicked()
{
    int currentIndex = ui->profileComboBox->currentIndex();
    if (currentIndex >= 0) {
        QString profileName = ui->profileComboBox->currentText();
        
        // Confirm deletion
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Delete Profile", 
                                    "Are you sure you want to delete profile '" + profileName + "'?",
                                    QMessageBox::Yes | QMessageBox::No);
        
        if (reply == QMessageBox::Yes) {
            // Delete the profile
            simulation->deleteProfile(currentIndex);
            
            // Update UI
            populateProfileComboBox();
        }
    } else {
        QMessageBox::warning(this, "Delete Profile", "No profile selected.");
    }
}

void MainWindow::on_profileComboBox_currentIndexChanged(int index)
{
    if (index >= 0 && index != simulation->getCurrentProfileIndex()) {
        // Only switch if the selected profile is different from the current one
        simulation->switchProfile(index);
    }
}

// Control-IQ slots
void MainWindow::on_controlIQCheckBox_toggled(bool checked)
{
    simulation->enableControlIQ(checked);
    
    // Enable/disable Control-IQ settings
    ui->modeComboBox->setEnabled(checked);
    ui->hypoThresholdSpinBox->setEnabled(checked);
    ui->hyperThresholdSpinBox->setEnabled(checked);
}

void MainWindow::on_modeComboBox_currentTextChanged(const QString &mode)
{
    simulation->setControlIQMode(mode);
}

void MainWindow::on_hypoThresholdSpinBox_valueChanged(int value)
{
    simulation->setHypoPreventionThreshold(value);
}

void MainWindow::on_hyperThresholdSpinBox_valueChanged(int value)
{
    simulation->setHyperPreventionThreshold(value);
}

void MainWindow::onScreenChanged(ScreenManager::ScreenType screenType)
{
    // Update UI based on current screen
    switch (screenType) {
        case ScreenManager::HomeScreenType:
            simulation->logSimulationEvent("Navigated to Home screen");
            break;
        case ScreenManager::BolusCalculatorType:
            simulation->logSimulationEvent("Navigated to Bolus Calculator screen");
            break;
    }
    
    // Additional UI updates specific to screen changes can be added here
} 
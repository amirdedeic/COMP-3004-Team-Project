#include "homescreen.h"
#include "ui_homescreen.h"
#include <QDateTime>

HomeScreen::HomeScreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HomeScreen),
    simulation(nullptr)
{
    ui->setupUi(this);
    
    // Connect UI buttons to slots
    connect(ui->bolusButton, &QPushButton::clicked, this, &HomeScreen::on_bolusButton_clicked);
    connect(ui->optionsButton, &QPushButton::clicked, this, &HomeScreen::on_optionsButton_clicked);
}

HomeScreen::~HomeScreen()
{
    delete ui;
}

void HomeScreen::setSimulation(Simulation *sim)
{
    simulation = sim;
    updateDisplay();
}

void HomeScreen::updateDisplay()
{
    if (!simulation) return;

    // Update glucose level and trend
    ui->glucoseValueLabel->setText(QString::number(simulation->getGlucoseLevel()) + " mg/dL");
    ui->trendValueLabel->setText(simulation->getGlucoseTrend());

    // Update battery level
    ui->batteryProgressBar->setValue(static_cast<int>(simulation->getBatteryLevel() * 100));

    // Update insulin level
    ui->insulinProgressBar->setValue(static_cast<int>(simulation->getInsulinLevel() * 100));

    // Update insulin on board
    ui->iobValueLabel->setText(QString::number(simulation->getInsulinOnBoard(), 'f', 1) + " units");

    // Update clock
    QDateTime currentTime = QDateTime::currentDateTime();
    ui->clockLabel->setText(currentTime.toString("h:mm AP | MMMM d"));
}

// Slot called when bolus button is clicked
void HomeScreen::on_bolusButton_clicked()
{
    // Emit signal to navigate to bolus calculator
    emit navigateToBolusCalculator();
}

// Slot called when options button is clicked
void HomeScreen::on_optionsButton_clicked()
{
    // Options functionality can be added later
    simulation->logSimulationEvent("Options button clicked");
} 
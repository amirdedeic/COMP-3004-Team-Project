#ifndef HOMESCREEN_H
#define HOMESCREEN_H

#include <QWidget>
#include "simulation.h"

namespace Ui {
class HomeScreen;
}

class HomeScreen : public QWidget
{
    Q_OBJECT

public:
    explicit HomeScreen(QWidget *parent = nullptr);
    ~HomeScreen();

    void setSimulation(Simulation *sim);
    void updateDisplay();

signals:
    // Signal to navigate to the bolus calculator screen
    void navigateToBolusCalculator();
    
    // Signal to navigate to home (could be used by other screens)
    void navigateToHome();

private slots:
    // Slot called when bolus button is clicked
    void on_bolusButton_clicked();
    
    // Slot called when options button is clicked
    void on_optionsButton_clicked();

private:
    Ui::HomeScreen *ui;
    Simulation *simulation;
};

#endif // HOMESCREEN_H 
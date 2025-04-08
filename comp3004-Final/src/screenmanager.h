#ifndef SCREENMANAGER_H
#define SCREENMANAGER_H

#include <QObject>
#include <QStackedWidget>
#include <QMap>
#include "simulation.h"

// Forward declarations
class HomeScreen;
class BolusCalculator;

class ScreenManager : public QObject
{
    Q_OBJECT

public:
    enum ScreenType {
        HomeScreenType,
        BolusCalculatorType,
        // Add more screens as needed
    };

    explicit ScreenManager(QObject *parent = nullptr);
    ~ScreenManager();

    // Sets the stacked widget that will contain all screens
    void setStackedWidget(QStackedWidget *stackedWidget);
    
    // Sets the simulation object to be used by all screens
    void setSimulation(Simulation *sim);
    
    // Navigate to a specific screen
    void navigateTo(ScreenType screenType);
    
    // Go back to the previous screen
    void goBack();
    
    // Go to the home screen
    void goHome();
    
    // Get the current screen
    ScreenType currentScreen() const;
    
    // Initialize the screens
    void initializeScreens();

signals:
    // Signal emitted when screen changes
    void screenChanged(ScreenType screenType);

private:
    QStackedWidget *stackedWidget;
    Simulation *simulation;
    QMap<ScreenType, QWidget*> screens;
    QList<ScreenType> screenHistory;
};

#endif // SCREENMANAGER_H 
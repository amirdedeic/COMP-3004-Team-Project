#include "screenmanager.h"
#include "homescreen.h"
#include "boluscalculator.h"

ScreenManager::ScreenManager(QObject *parent)
    : QObject(parent),
      stackedWidget(nullptr),
      simulation(nullptr)
{
}

ScreenManager::~ScreenManager()
{
    // Screens are owned by the stacked widget, so no need to delete them here
}

void ScreenManager::setStackedWidget(QStackedWidget *stackedWidget)
{
    this->stackedWidget = stackedWidget;
}

void ScreenManager::setSimulation(Simulation *sim)
{
    simulation = sim;
}

void ScreenManager::initializeScreens()
{
    if (!stackedWidget || !simulation) {
        return;
    }

    // Create Home Screen
    HomeScreen *home = new HomeScreen();
    home->setSimulation(simulation);
    screens[HomeScreenType] = home;
    stackedWidget->addWidget(home);

    // Create Bolus Calculator Screen
    BolusCalculator *bolus = new BolusCalculator();
    bolus->setSimulation(simulation);
    screens[BolusCalculatorType] = bolus;
    stackedWidget->addWidget(bolus);

    // Set initial screen
    screenHistory.append(HomeScreenType);
    stackedWidget->setCurrentWidget(screens[HomeScreenType]);
}

void ScreenManager::navigateTo(ScreenType screenType)
{
    if (!stackedWidget || !screens.contains(screenType)) {
        return;
    }

    // Add to history
    screenHistory.append(screenType);
    
    // Switch to the screen
    stackedWidget->setCurrentWidget(screens[screenType]);
    
    // Emit signal
    emit screenChanged(screenType);
}

void ScreenManager::goBack()
{
    if (screenHistory.size() <= 1) {
        // We're already at the first screen, so go to home
        goHome();
        return;
    }

    // Remove current screen from history
    screenHistory.removeLast();
    
    // Get the previous screen
    ScreenType prevScreen = screenHistory.last();
    
    // Switch to the previous screen
    stackedWidget->setCurrentWidget(screens[prevScreen]);
    
    // Emit signal
    emit screenChanged(prevScreen);
}

void ScreenManager::goHome()
{
    // Clear history and add home screen
    screenHistory.clear();
    screenHistory.append(HomeScreenType);
    
    // Switch to home screen
    stackedWidget->setCurrentWidget(screens[HomeScreenType]);
    
    // Emit signal
    emit screenChanged(HomeScreenType);
}

ScreenManager::ScreenType ScreenManager::currentScreen() const
{
    return screenHistory.isEmpty() ? HomeScreenType : screenHistory.last();
} 
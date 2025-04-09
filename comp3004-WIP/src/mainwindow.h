#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QInputDialog>
#include <QMessageBox>
#include <QStackedWidget>
#include "simulation.h"
#include "screenmanager.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void updateUI();
    void on_startButton_clicked();
    void on_stopButton_clicked();
    
    // Profile management slots
    void on_createProfileButton_clicked();
    void on_deleteProfileButton_clicked();
    void on_profileComboBox_currentIndexChanged(int index);
    
    // Control-IQ slots
    void on_controlIQCheckBox_toggled(bool checked);
    void on_modeComboBox_currentTextChanged(const QString &mode);
    void on_hypoThresholdSpinBox_valueChanged(int value);
    void on_hyperThresholdSpinBox_valueChanged(int value);
    
    void populateProfileComboBox();
    
    // Screen navigation slot
    void onScreenChanged(ScreenManager::ScreenType screenType);

private:
    Ui::MainWindow *ui;
    Simulation *simulation;
    ScreenManager *screenManager;
    QStackedWidget *screenStack;
};

#endif // MAINWINDOW_H 
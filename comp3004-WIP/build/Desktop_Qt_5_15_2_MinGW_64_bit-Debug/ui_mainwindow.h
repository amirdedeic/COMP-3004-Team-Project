/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *controlTab;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *startButton;
    QPushButton *stopButton;
    QGroupBox *profileGroupBox;
    QGridLayout *gridLayout;
    QLabel *label;
    QComboBox *profileComboBox;
    QPushButton *createProfileButton;
    QPushButton *deleteProfileButton;
    QGroupBox *controlIQGroupBox;
    QGridLayout *gridLayout_2;
    QCheckBox *controlIQCheckBox;
    QLabel *modeLabel;
    QComboBox *modeComboBox;
    QLabel *hypoThresholdLabel;
    QSpinBox *hypoThresholdSpinBox;
    QLabel *hyperThresholdLabel;
    QSpinBox *hyperThresholdSpinBox;
    QSpacerItem *verticalSpacer;
    QWidget *logTab;
    QVBoxLayout *verticalLayout_3;
    QTextEdit *logTextEdit;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        controlTab = new QWidget();
        controlTab->setObjectName(QString::fromUtf8("controlTab"));
        verticalLayout_2 = new QVBoxLayout(controlTab);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        startButton = new QPushButton(controlTab);
        startButton->setObjectName(QString::fromUtf8("startButton"));

        horizontalLayout->addWidget(startButton);

        stopButton = new QPushButton(controlTab);
        stopButton->setObjectName(QString::fromUtf8("stopButton"));

        horizontalLayout->addWidget(stopButton);


        verticalLayout_2->addLayout(horizontalLayout);

        profileGroupBox = new QGroupBox(controlTab);
        profileGroupBox->setObjectName(QString::fromUtf8("profileGroupBox"));
        gridLayout = new QGridLayout(profileGroupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(profileGroupBox);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        profileComboBox = new QComboBox(profileGroupBox);
        profileComboBox->setObjectName(QString::fromUtf8("profileComboBox"));

        gridLayout->addWidget(profileComboBox, 0, 1, 1, 1);

        createProfileButton = new QPushButton(profileGroupBox);
        createProfileButton->setObjectName(QString::fromUtf8("createProfileButton"));

        gridLayout->addWidget(createProfileButton, 0, 2, 1, 1);

        deleteProfileButton = new QPushButton(profileGroupBox);
        deleteProfileButton->setObjectName(QString::fromUtf8("deleteProfileButton"));

        gridLayout->addWidget(deleteProfileButton, 0, 3, 1, 1);


        verticalLayout_2->addWidget(profileGroupBox);

        controlIQGroupBox = new QGroupBox(controlTab);
        controlIQGroupBox->setObjectName(QString::fromUtf8("controlIQGroupBox"));
        gridLayout_2 = new QGridLayout(controlIQGroupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        controlIQCheckBox = new QCheckBox(controlIQGroupBox);
        controlIQCheckBox->setObjectName(QString::fromUtf8("controlIQCheckBox"));

        gridLayout_2->addWidget(controlIQCheckBox, 0, 0, 1, 1);

        modeLabel = new QLabel(controlIQGroupBox);
        modeLabel->setObjectName(QString::fromUtf8("modeLabel"));

        gridLayout_2->addWidget(modeLabel, 1, 0, 1, 1);

        modeComboBox = new QComboBox(controlIQGroupBox);
        modeComboBox->addItem(QString());
        modeComboBox->addItem(QString());
        modeComboBox->addItem(QString());
        modeComboBox->setObjectName(QString::fromUtf8("modeComboBox"));

        gridLayout_2->addWidget(modeComboBox, 1, 1, 1, 1);

        hypoThresholdLabel = new QLabel(controlIQGroupBox);
        hypoThresholdLabel->setObjectName(QString::fromUtf8("hypoThresholdLabel"));

        gridLayout_2->addWidget(hypoThresholdLabel, 2, 0, 1, 1);

        hypoThresholdSpinBox = new QSpinBox(controlIQGroupBox);
        hypoThresholdSpinBox->setObjectName(QString::fromUtf8("hypoThresholdSpinBox"));
        hypoThresholdSpinBox->setMinimum(60);
        hypoThresholdSpinBox->setMaximum(90);
        hypoThresholdSpinBox->setValue(70);

        gridLayout_2->addWidget(hypoThresholdSpinBox, 2, 1, 1, 1);

        hyperThresholdLabel = new QLabel(controlIQGroupBox);
        hyperThresholdLabel->setObjectName(QString::fromUtf8("hyperThresholdLabel"));

        gridLayout_2->addWidget(hyperThresholdLabel, 3, 0, 1, 1);

        hyperThresholdSpinBox = new QSpinBox(controlIQGroupBox);
        hyperThresholdSpinBox->setObjectName(QString::fromUtf8("hyperThresholdSpinBox"));
        hyperThresholdSpinBox->setMinimum(160);
        hyperThresholdSpinBox->setMaximum(200);
        hyperThresholdSpinBox->setValue(180);

        gridLayout_2->addWidget(hyperThresholdSpinBox, 3, 1, 1, 1);


        verticalLayout_2->addWidget(controlIQGroupBox);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        tabWidget->addTab(controlTab, QString());
        logTab = new QWidget();
        logTab->setObjectName(QString::fromUtf8("logTab"));
        verticalLayout_3 = new QVBoxLayout(logTab);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        logTextEdit = new QTextEdit(logTab);
        logTextEdit->setObjectName(QString::fromUtf8("logTextEdit"));
        logTextEdit->setReadOnly(true);

        verticalLayout_3->addWidget(logTextEdit);

        tabWidget->addTab(logTab, QString());

        verticalLayout->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Test Application", nullptr));
        startButton->setText(QCoreApplication::translate("MainWindow", "Start Simulation", nullptr));
        stopButton->setText(QCoreApplication::translate("MainWindow", "Stop Simulation", nullptr));
        profileGroupBox->setTitle(QCoreApplication::translate("MainWindow", "Profile Management", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Current Profile:", nullptr));
        createProfileButton->setText(QCoreApplication::translate("MainWindow", "Create Profile", nullptr));
        deleteProfileButton->setText(QCoreApplication::translate("MainWindow", "Delete Profile", nullptr));
        controlIQGroupBox->setTitle(QCoreApplication::translate("MainWindow", "Control-IQ Technology", nullptr));
        controlIQCheckBox->setText(QCoreApplication::translate("MainWindow", "Enable Control-IQ", nullptr));
        modeLabel->setText(QCoreApplication::translate("MainWindow", "Mode:", nullptr));
        modeComboBox->setItemText(0, QCoreApplication::translate("MainWindow", "Normal", nullptr));
        modeComboBox->setItemText(1, QCoreApplication::translate("MainWindow", "Sleep", nullptr));
        modeComboBox->setItemText(2, QCoreApplication::translate("MainWindow", "Exercise", nullptr));

        hypoThresholdLabel->setText(QCoreApplication::translate("MainWindow", "Hypo Prevention Threshold:", nullptr));
        hyperThresholdLabel->setText(QCoreApplication::translate("MainWindow", "Hyper Prevention Threshold:", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(controlTab), QCoreApplication::translate("MainWindow", "Simulation Controls", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(logTab), QCoreApplication::translate("MainWindow", "Simulation Log", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

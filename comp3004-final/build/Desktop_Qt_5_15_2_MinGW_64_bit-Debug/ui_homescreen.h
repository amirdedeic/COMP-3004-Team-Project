/********************************************************************************
** Form generated from reading UI file 'homescreen.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOMESCREEN_H
#define UI_HOMESCREEN_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HomeScreen
{
public:
    QGridLayout *gridLayout_2;
    QFrame *statusBar;
    QHBoxLayout *horizontalLayout;
    QProgressBar *batteryProgressBar;
    QLabel *clockLabel;
    QProgressBar *insulinProgressBar;
    QFrame *cgmGraphFrame;
    QVBoxLayout *verticalLayout;
    QLabel *glucoseValueLabel;
    QLabel *trendValueLabel;
    QFrame *graphFrame;
    QLabel *timeFrameLabel;
    QFrame *iobFrame;
    QHBoxLayout *horizontalLayout_2;
    QLabel *iobLabel;
    QLabel *iobValueLabel;
    QLabel *iobTimeLabel;
    QPushButton *tButton;
    QPushButton *optionsButton;
    QPushButton *bolusButton;

    void setupUi(QWidget *HomeScreen)
    {
        if (HomeScreen->objectName().isEmpty())
            HomeScreen->setObjectName(QString::fromUtf8("HomeScreen"));
        HomeScreen->resize(800, 600);
        HomeScreen->setStyleSheet(QString::fromUtf8("background-color: #333333; color: white;"));
        gridLayout_2 = new QGridLayout(HomeScreen);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        statusBar = new QFrame(HomeScreen);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        statusBar->setMaximumHeight(50);
        statusBar->setFrameShape(QFrame::StyledPanel);
        statusBar->setFrameShadow(QFrame::Raised);
        statusBar->setStyleSheet(QString::fromUtf8("background-color: #222222;"));
        horizontalLayout = new QHBoxLayout(statusBar);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        batteryProgressBar = new QProgressBar(statusBar);
        batteryProgressBar->setObjectName(QString::fromUtf8("batteryProgressBar"));
        batteryProgressBar->setMaximumWidth(100);
        batteryProgressBar->setValue(100);
        batteryProgressBar->setTextVisible(true);
        batteryProgressBar->setStyleSheet(QString::fromUtf8("QProgressBar {\n"
"   border: 1px solid #555;\n"
"   border-radius: 5px;\n"
"   text-align: center;\n"
"}\n"
"QProgressBar::chunk {\n"
"   background-color: #00aaff;\n"
"   width: 10px;\n"
"   margin: 0.5px;\n"
"}"));

        horizontalLayout->addWidget(batteryProgressBar);

        clockLabel = new QLabel(statusBar);
        clockLabel->setObjectName(QString::fromUtf8("clockLabel"));
        clockLabel->setAlignment(Qt::AlignCenter);
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        clockLabel->setFont(font);

        horizontalLayout->addWidget(clockLabel);

        insulinProgressBar = new QProgressBar(statusBar);
        insulinProgressBar->setObjectName(QString::fromUtf8("insulinProgressBar"));
        insulinProgressBar->setMaximumWidth(100);
        insulinProgressBar->setValue(100);
        insulinProgressBar->setStyleSheet(QString::fromUtf8("QProgressBar {\n"
"   border: 1px solid #555;\n"
"   border-radius: 5px;\n"
"   text-align: center;\n"
"}\n"
"QProgressBar::chunk {\n"
"   background-color: #00aaff;\n"
"   width: 10px;\n"
"   margin: 0.5px;\n"
"}"));

        horizontalLayout->addWidget(insulinProgressBar);


        gridLayout_2->addWidget(statusBar, 0, 0, 1, 3);

        cgmGraphFrame = new QFrame(HomeScreen);
        cgmGraphFrame->setObjectName(QString::fromUtf8("cgmGraphFrame"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(cgmGraphFrame->sizePolicy().hasHeightForWidth());
        cgmGraphFrame->setSizePolicy(sizePolicy);
        cgmGraphFrame->setFrameShape(QFrame::StyledPanel);
        cgmGraphFrame->setFrameShadow(QFrame::Raised);
        cgmGraphFrame->setStyleSheet(QString::fromUtf8("background-color: #222222;"));
        verticalLayout = new QVBoxLayout(cgmGraphFrame);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        glucoseValueLabel = new QLabel(cgmGraphFrame);
        glucoseValueLabel->setObjectName(QString::fromUtf8("glucoseValueLabel"));
        glucoseValueLabel->setAlignment(Qt::AlignCenter);
        QFont font1;
        font1.setPointSize(24);
        font1.setBold(true);
        font1.setWeight(75);
        glucoseValueLabel->setFont(font1);
        glucoseValueLabel->setStyleSheet(QString::fromUtf8("color: #00aaff;"));

        verticalLayout->addWidget(glucoseValueLabel);

        trendValueLabel = new QLabel(cgmGraphFrame);
        trendValueLabel->setObjectName(QString::fromUtf8("trendValueLabel"));
        trendValueLabel->setAlignment(Qt::AlignCenter);
        QFont font2;
        font2.setPointSize(18);
        font2.setBold(true);
        font2.setWeight(75);
        trendValueLabel->setFont(font2);
        trendValueLabel->setStyleSheet(QString::fromUtf8("color: #00aaff;"));

        verticalLayout->addWidget(trendValueLabel);

        graphFrame = new QFrame(cgmGraphFrame);
        graphFrame->setObjectName(QString::fromUtf8("graphFrame"));
        sizePolicy.setHeightForWidth(graphFrame->sizePolicy().hasHeightForWidth());
        graphFrame->setSizePolicy(sizePolicy);
        graphFrame->setMinimumSize(QSize(0, 200));
        graphFrame->setFrameShape(QFrame::NoFrame);
        graphFrame->setFrameShadow(QFrame::Raised);
        graphFrame->setStyleSheet(QString::fromUtf8("/* Graph will be drawn programmatically */"));

        verticalLayout->addWidget(graphFrame);

        timeFrameLabel = new QLabel(cgmGraphFrame);
        timeFrameLabel->setObjectName(QString::fromUtf8("timeFrameLabel"));
        timeFrameLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(timeFrameLabel);


        gridLayout_2->addWidget(cgmGraphFrame, 1, 0, 1, 3);

        iobFrame = new QFrame(HomeScreen);
        iobFrame->setObjectName(QString::fromUtf8("iobFrame"));
        iobFrame->setMaximumHeight(50);
        iobFrame->setFrameShape(QFrame::StyledPanel);
        iobFrame->setFrameShadow(QFrame::Raised);
        iobFrame->setStyleSheet(QString::fromUtf8("background-color: #222222;"));
        horizontalLayout_2 = new QHBoxLayout(iobFrame);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        iobLabel = new QLabel(iobFrame);
        iobLabel->setObjectName(QString::fromUtf8("iobLabel"));

        horizontalLayout_2->addWidget(iobLabel);

        iobValueLabel = new QLabel(iobFrame);
        iobValueLabel->setObjectName(QString::fromUtf8("iobValueLabel"));
        iobValueLabel->setFont(font);
        iobValueLabel->setStyleSheet(QString::fromUtf8("color: #00aaff;"));

        horizontalLayout_2->addWidget(iobValueLabel);

        iobTimeLabel = new QLabel(iobFrame);
        iobTimeLabel->setObjectName(QString::fromUtf8("iobTimeLabel"));

        horizontalLayout_2->addWidget(iobTimeLabel);


        gridLayout_2->addWidget(iobFrame, 2, 0, 1, 2);

        tButton = new QPushButton(HomeScreen);
        tButton->setObjectName(QString::fromUtf8("tButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tButton->sizePolicy().hasHeightForWidth());
        tButton->setSizePolicy(sizePolicy1);
        tButton->setMinimumSize(QSize(60, 120));
        tButton->setFont(font1);
        tButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"   background-color: #00aaff;\n"
"   color: white;\n"
"   border-radius: 10px;\n"
"}\n"
"QPushButton:pressed {\n"
"   background-color: #0088cc;\n"
"}"));

        gridLayout_2->addWidget(tButton, 2, 2, 2, 1);

        optionsButton = new QPushButton(HomeScreen);
        optionsButton->setObjectName(QString::fromUtf8("optionsButton"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(optionsButton->sizePolicy().hasHeightForWidth());
        optionsButton->setSizePolicy(sizePolicy2);
        optionsButton->setMinimumSize(QSize(0, 80));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/gear.png"), QSize(), QIcon::Normal, QIcon::Off);
        optionsButton->setIcon(icon);
        optionsButton->setIconSize(QSize(24, 24));
        QFont font3;
        font3.setPointSize(14);
        font3.setBold(true);
        font3.setWeight(75);
        optionsButton->setFont(font3);
        optionsButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"   background-color: #444444;\n"
"   color: white;\n"
"   border-radius: 5px;\n"
"}\n"
"QPushButton:pressed {\n"
"   background-color: #333333;\n"
"}"));

        gridLayout_2->addWidget(optionsButton, 3, 0, 1, 1);

        bolusButton = new QPushButton(HomeScreen);
        bolusButton->setObjectName(QString::fromUtf8("bolusButton"));
        sizePolicy2.setHeightForWidth(bolusButton->sizePolicy().hasHeightForWidth());
        bolusButton->setSizePolicy(sizePolicy2);
        bolusButton->setMinimumSize(QSize(0, 80));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/droplet.png"), QSize(), QIcon::Normal, QIcon::Off);
        bolusButton->setIcon(icon1);
        bolusButton->setIconSize(QSize(24, 24));
        bolusButton->setFont(font3);
        bolusButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"   background-color: #00aaff;\n"
"   color: white;\n"
"   border-radius: 5px;\n"
"}\n"
"QPushButton:pressed {\n"
"   background-color: #0088cc;\n"
"}"));

        gridLayout_2->addWidget(bolusButton, 3, 1, 1, 1);


        retranslateUi(HomeScreen);

        QMetaObject::connectSlotsByName(HomeScreen);
    } // setupUi

    void retranslateUi(QWidget *HomeScreen)
    {
        batteryProgressBar->setFormat(QCoreApplication::translate("HomeScreen", "%p%", nullptr));
        clockLabel->setText(QCoreApplication::translate("HomeScreen", "6:32 PM | November 14", nullptr));
        insulinProgressBar->setFormat(QCoreApplication::translate("HomeScreen", "%v u", nullptr));
        glucoseValueLabel->setText(QCoreApplication::translate("HomeScreen", "88 mg/dL", nullptr));
        trendValueLabel->setText(QCoreApplication::translate("HomeScreen", "\342\206\222", nullptr));
        timeFrameLabel->setText(QCoreApplication::translate("HomeScreen", "3 HRS", nullptr));
        iobLabel->setText(QCoreApplication::translate("HomeScreen", "IOB:", nullptr));
        iobValueLabel->setText(QCoreApplication::translate("HomeScreen", "1.1 units", nullptr));
        iobTimeLabel->setText(QCoreApplication::translate("HomeScreen", "1:09 hrs", nullptr));
        tButton->setText(QCoreApplication::translate("HomeScreen", "t", nullptr));
        optionsButton->setText(QCoreApplication::translate("HomeScreen", "OPTIONS", nullptr));
        bolusButton->setText(QCoreApplication::translate("HomeScreen", "BOLUS", nullptr));
        (void)HomeScreen;
    } // retranslateUi

};

namespace Ui {
    class HomeScreen: public Ui_HomeScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOMESCREEN_H

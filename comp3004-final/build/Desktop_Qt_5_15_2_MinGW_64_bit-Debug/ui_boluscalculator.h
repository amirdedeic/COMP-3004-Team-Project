/********************************************************************************
** Form generated from reading UI file 'boluscalculator.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOLUSCALCULATOR_H
#define UI_BOLUSCALCULATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BolusCalculator
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *navigationFrame;
    QHBoxLayout *horizontalLayout;
    QPushButton *backButton;
    QLabel *bolusAmountLabel;
    QPushButton *nextButton;
    QFrame *contentFrame;
    QVBoxLayout *verticalLayout_2;
    QFrame *inputFrame;
    QHBoxLayout *horizontalLayout_2;
    QFrame *carbFrame;
    QVBoxLayout *verticalLayout_3;
    QLabel *carbsLabel;
    QPushButton *carbsButton;
    QFrame *bgFrame;
    QVBoxLayout *verticalLayout_4;
    QLabel *bgLabel;
    QPushButton *bgButton;
    QPushButton *viewCalculationButton;
    QFrame *bottomFrame;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QLabel *tandemLogo;
    QPushButton *homeButton;
    QStackedWidget *wizardStack;
    QWidget *calculatorPage;
    QWidget *confirmationPage;
    QWidget *deliveryPage;

    void setupUi(QWidget *BolusCalculator)
    {
        if (BolusCalculator->objectName().isEmpty())
            BolusCalculator->setObjectName(QString::fromUtf8("BolusCalculator"));
        BolusCalculator->resize(800, 600);
        BolusCalculator->setStyleSheet(QString::fromUtf8("background-color: #333333; color: white;"));
        verticalLayout = new QVBoxLayout(BolusCalculator);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        navigationFrame = new QFrame(BolusCalculator);
        navigationFrame->setObjectName(QString::fromUtf8("navigationFrame"));
        navigationFrame->setMaximumHeight(80);
        navigationFrame->setFrameShape(QFrame::StyledPanel);
        navigationFrame->setFrameShadow(QFrame::Raised);
        navigationFrame->setStyleSheet(QString::fromUtf8("background-color: #222222;"));
        horizontalLayout = new QHBoxLayout(navigationFrame);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        backButton = new QPushButton(navigationFrame);
        backButton->setObjectName(QString::fromUtf8("backButton"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(backButton->sizePolicy().hasHeightForWidth());
        backButton->setSizePolicy(sizePolicy);
        backButton->setMinimumSize(QSize(60, 50));
        backButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #555555;\n"
"    color: white;\n"
"    border-radius: 5px;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #444444;\n"
"}"));

        horizontalLayout->addWidget(backButton);

        bolusAmountLabel = new QLabel(navigationFrame);
        bolusAmountLabel->setObjectName(QString::fromUtf8("bolusAmountLabel"));
        bolusAmountLabel->setAlignment(Qt::AlignCenter);
        QFont font;
        font.setPointSize(18);
        font.setBold(true);
        font.setWeight(75);
        bolusAmountLabel->setFont(font);
        bolusAmountLabel->setStyleSheet(QString::fromUtf8("color: #00aaff;"));

        horizontalLayout->addWidget(bolusAmountLabel);

        nextButton = new QPushButton(navigationFrame);
        nextButton->setObjectName(QString::fromUtf8("nextButton"));
        nextButton->setMinimumSize(QSize(60, 50));
        nextButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #00aaff;\n"
"    color: white;\n"
"    border-radius: 5px;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #0088cc;\n"
"}"));

        horizontalLayout->addWidget(nextButton);


        verticalLayout->addWidget(navigationFrame);

        contentFrame = new QFrame(BolusCalculator);
        contentFrame->setObjectName(QString::fromUtf8("contentFrame"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(contentFrame->sizePolicy().hasHeightForWidth());
        contentFrame->setSizePolicy(sizePolicy1);
        contentFrame->setFrameShape(QFrame::StyledPanel);
        contentFrame->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(contentFrame);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        inputFrame = new QFrame(contentFrame);
        inputFrame->setObjectName(QString::fromUtf8("inputFrame"));
        sizePolicy1.setHeightForWidth(inputFrame->sizePolicy().hasHeightForWidth());
        inputFrame->setSizePolicy(sizePolicy1);
        inputFrame->setFrameShape(QFrame::StyledPanel);
        inputFrame->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(inputFrame);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        carbFrame = new QFrame(inputFrame);
        carbFrame->setObjectName(QString::fromUtf8("carbFrame"));
        carbFrame->setFrameShape(QFrame::StyledPanel);
        carbFrame->setFrameShadow(QFrame::Raised);
        carbFrame->setStyleSheet(QString::fromUtf8("background-color: #444444; border-radius: 10px;"));
        verticalLayout_3 = new QVBoxLayout(carbFrame);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        carbsLabel = new QLabel(carbFrame);
        carbsLabel->setObjectName(QString::fromUtf8("carbsLabel"));
        carbsLabel->setAlignment(Qt::AlignCenter);
        QFont font1;
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setWeight(75);
        carbsLabel->setFont(font1);

        verticalLayout_3->addWidget(carbsLabel);

        carbsButton = new QPushButton(carbFrame);
        carbsButton->setObjectName(QString::fromUtf8("carbsButton"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(carbsButton->sizePolicy().hasHeightForWidth());
        carbsButton->setSizePolicy(sizePolicy2);
        carbsButton->setFont(font);
        carbsButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: transparent;\n"
"    color: #00aaff;\n"
"    border: none;\n"
"}\n"
"QPushButton:pressed {\n"
"    color: #0088cc;\n"
"}"));

        verticalLayout_3->addWidget(carbsButton);


        horizontalLayout_2->addWidget(carbFrame);

        bgFrame = new QFrame(inputFrame);
        bgFrame->setObjectName(QString::fromUtf8("bgFrame"));
        bgFrame->setFrameShape(QFrame::StyledPanel);
        bgFrame->setFrameShadow(QFrame::Raised);
        bgFrame->setStyleSheet(QString::fromUtf8("background-color: #444444; border-radius: 10px;"));
        verticalLayout_4 = new QVBoxLayout(bgFrame);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        bgLabel = new QLabel(bgFrame);
        bgLabel->setObjectName(QString::fromUtf8("bgLabel"));
        bgLabel->setAlignment(Qt::AlignCenter);
        bgLabel->setFont(font1);

        verticalLayout_4->addWidget(bgLabel);

        bgButton = new QPushButton(bgFrame);
        bgButton->setObjectName(QString::fromUtf8("bgButton"));
        sizePolicy2.setHeightForWidth(bgButton->sizePolicy().hasHeightForWidth());
        bgButton->setSizePolicy(sizePolicy2);
        bgButton->setFont(font);
        bgButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: transparent;\n"
"    color: #00aaff;\n"
"    border: none;\n"
"}\n"
"QPushButton:pressed {\n"
"    color: #0088cc;\n"
"}"));

        verticalLayout_4->addWidget(bgButton);


        horizontalLayout_2->addWidget(bgFrame);


        verticalLayout_2->addWidget(inputFrame);

        viewCalculationButton = new QPushButton(contentFrame);
        viewCalculationButton->setObjectName(QString::fromUtf8("viewCalculationButton"));
        viewCalculationButton->setMinimumSize(QSize(0, 50));
        QFont font2;
        font2.setPointSize(12);
        viewCalculationButton->setFont(font2);
        viewCalculationButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #555555;\n"
"    color: white;\n"
"    border-radius: 5px;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #444444;\n"
"}"));

        verticalLayout_2->addWidget(viewCalculationButton);


        verticalLayout->addWidget(contentFrame);

        bottomFrame = new QFrame(BolusCalculator);
        bottomFrame->setObjectName(QString::fromUtf8("bottomFrame"));
        bottomFrame->setMaximumHeight(100);
        bottomFrame->setFrameShape(QFrame::StyledPanel);
        bottomFrame->setFrameShadow(QFrame::Raised);
        horizontalLayout_3 = new QHBoxLayout(bottomFrame);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        tandemLogo = new QLabel(bottomFrame);
        tandemLogo->setObjectName(QString::fromUtf8("tandemLogo"));
        QFont font3;
        font3.setPointSize(12);
        font3.setBold(true);
        font3.setWeight(75);
        tandemLogo->setFont(font3);
        tandemLogo->setStyleSheet(QString::fromUtf8("color: #00aaff;"));

        horizontalLayout_3->addWidget(tandemLogo);

        homeButton = new QPushButton(bottomFrame);
        homeButton->setObjectName(QString::fromUtf8("homeButton"));
        homeButton->setMinimumSize(QSize(60, 60));
        homeButton->setFont(font);
        homeButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #00aaff;\n"
"    color: white;\n"
"    border-radius: 10px;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #0088cc;\n"
"}"));

        horizontalLayout_3->addWidget(homeButton);


        verticalLayout->addWidget(bottomFrame);

        wizardStack = new QStackedWidget(BolusCalculator);
        wizardStack->setObjectName(QString::fromUtf8("wizardStack"));
        calculatorPage = new QWidget();
        calculatorPage->setObjectName(QString::fromUtf8("calculatorPage"));
        wizardStack->addWidget(calculatorPage);
        confirmationPage = new QWidget();
        confirmationPage->setObjectName(QString::fromUtf8("confirmationPage"));
        wizardStack->addWidget(confirmationPage);
        deliveryPage = new QWidget();
        deliveryPage->setObjectName(QString::fromUtf8("deliveryPage"));
        wizardStack->addWidget(deliveryPage);

        verticalLayout->addWidget(wizardStack);


        retranslateUi(BolusCalculator);

        wizardStack->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(BolusCalculator);
    } // setupUi

    void retranslateUi(QWidget *BolusCalculator)
    {
        backButton->setText(QCoreApplication::translate("BolusCalculator", "\342\227\200 BACK", nullptr));
        bolusAmountLabel->setText(QCoreApplication::translate("BolusCalculator", "0 units", nullptr));
        nextButton->setText(QCoreApplication::translate("BolusCalculator", "NEXT \342\234\223", nullptr));
        carbsLabel->setText(QCoreApplication::translate("BolusCalculator", "CARBS", nullptr));
        carbsButton->setText(QCoreApplication::translate("BolusCalculator", "0 grams", nullptr));
        bgLabel->setText(QCoreApplication::translate("BolusCalculator", "GLUCOSE", nullptr));
        bgButton->setText(QCoreApplication::translate("BolusCalculator", "Add BG", nullptr));
        viewCalculationButton->setText(QCoreApplication::translate("BolusCalculator", "View Calculation", nullptr));
        tandemLogo->setText(QCoreApplication::translate("BolusCalculator", "Tandem", nullptr));
        homeButton->setText(QCoreApplication::translate("BolusCalculator", "t", nullptr));
        (void)BolusCalculator;
    } // retranslateUi

};

namespace Ui {
    class BolusCalculator: public Ui_BolusCalculator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOLUSCALCULATOR_H

/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *AddBankButton;
    QPushButton *GetBankButton;
    QPushButton *AddUserButton;
    QPushButton *GetUserButton;
    QPushButton *OpenBankAccountButton;
    QLineEdit *InputLine;
    QTextBrowser *OutputWindow;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(1247, 734);
        MainWindow->setTabletTracking(false);
        MainWindow->setAutoFillBackground(false);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        AddBankButton = new QPushButton(centralwidget);
        AddBankButton->setObjectName(QString::fromUtf8("AddBankButton"));
        AddBankButton->setGeometry(QRect(70, 570, 151, 81));
        GetBankButton = new QPushButton(centralwidget);
        GetBankButton->setObjectName(QString::fromUtf8("GetBankButton"));
        GetBankButton->setGeometry(QRect(300, 570, 151, 81));
        AddUserButton = new QPushButton(centralwidget);
        AddUserButton->setObjectName(QString::fromUtf8("AddUserButton"));
        AddUserButton->setGeometry(QRect(530, 570, 151, 81));
        GetUserButton = new QPushButton(centralwidget);
        GetUserButton->setObjectName(QString::fromUtf8("GetUserButton"));
        GetUserButton->setGeometry(QRect(770, 570, 151, 81));
        OpenBankAccountButton = new QPushButton(centralwidget);
        OpenBankAccountButton->setObjectName(QString::fromUtf8("OpenBankAccountButton"));
        OpenBankAccountButton->setGeometry(QRect(1020, 570, 151, 81));
        InputLine = new QLineEdit(centralwidget);
        InputLine->setObjectName(QString::fromUtf8("InputLine"));
        InputLine->setGeometry(QRect(360, 440, 491, 41));
        OutputWindow = new QTextBrowser(centralwidget);
        OutputWindow->setObjectName(QString::fromUtf8("OutputWindow"));
        OutputWindow->setGeometry(QRect(360, 90, 491, 321));
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        AddBankButton->setText(QCoreApplication::translate("MainWindow", "Add New Bank", nullptr));
        GetBankButton->setText(QCoreApplication::translate("MainWindow", "Get Banks List", nullptr));
        AddUserButton->setText(QCoreApplication::translate("MainWindow", "Add New User", nullptr));
        GetUserButton->setText(QCoreApplication::translate("MainWindow", "Get Users List", nullptr));
        OpenBankAccountButton->setText(QCoreApplication::translate("MainWindow", "Make Bank Account", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

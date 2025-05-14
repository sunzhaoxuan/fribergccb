/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *lineEdit;
    QPushButton *guessButton;
    QLabel *resultlabel;
    QListWidget *suggestionlist;
    QListWidget *historylist;
    QPushButton *restartButton;
    QPushButton *surrenderButton;
    QLabel *countlabel;
    QPushButton *statsButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(799, 638);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(50, 20, 441, 51));
        guessButton = new QPushButton(centralwidget);
        guessButton->setObjectName("guessButton");
        guessButton->setGeometry(QRect(550, 20, 191, 51));
        resultlabel = new QLabel(centralwidget);
        resultlabel->setObjectName("resultlabel");
        resultlabel->setGeometry(QRect(510, 140, 261, 111));
        suggestionlist = new QListWidget(centralwidget);
        suggestionlist->setObjectName("suggestionlist");
        suggestionlist->setGeometry(QRect(50, 70, 441, 121));
        suggestionlist->setProperty("showDropIndicator", QVariant(true));
        historylist = new QListWidget(centralwidget);
        historylist->setObjectName("historylist");
        historylist->setGeometry(QRect(50, 160, 701, 381));
        historylist->setSelectionMode(QAbstractItemView::SelectionMode::NoSelection);
        historylist->setWordWrap(true);
        restartButton = new QPushButton(centralwidget);
        restartButton->setObjectName("restartButton");
        restartButton->setGeometry(QRect(470, 100, 131, 41));
        surrenderButton = new QPushButton(centralwidget);
        surrenderButton->setObjectName("surrenderButton");
        surrenderButton->setGeometry(QRect(470, 100, 131, 41));
        countlabel = new QLabel(centralwidget);
        countlabel->setObjectName("countlabel");
        countlabel->setGeometry(QRect(190, 100, 241, 41));
        statsButton = new QPushButton(centralwidget);
        statsButton->setObjectName("statsButton");
        statsButton->setGeometry(QRect(680, 550, 93, 28));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 799, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        guessButton->setText(QCoreApplication::translate("MainWindow", "\347\241\256\345\256\232", nullptr));
        resultlabel->setText(QString());
        restartButton->setText(QCoreApplication::translate("MainWindow", "\351\207\215\346\226\260\345\274\200\345\247\213", nullptr));
        surrenderButton->setText(QCoreApplication::translate("MainWindow", "\346\212\225\351\231\215", nullptr));
        countlabel->setText(QString());
        statsButton->setText(QCoreApplication::translate("MainWindow", "\347\273\237\350\256\241\346\225\260\346\215\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

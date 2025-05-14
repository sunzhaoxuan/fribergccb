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
    QWidget *titlebar;
    QPushButton *minimizeButton;
    QPushButton *closeButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(799, 685);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(50, 60, 441, 51));
        guessButton = new QPushButton(centralwidget);
        guessButton->setObjectName("guessButton");
        guessButton->setGeometry(QRect(550, 60, 191, 51));
        guessButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #8BCF8B;  /* \346\233\264\351\262\234\350\211\263\347\232\204\347\273\277\350\211\262\357\274\214\344\273\213\344\272\216\346\267\241\347\273\277\344\270\216\344\272\256\347\273\277\344\271\213\351\227\264 */\n"
"    color: #ffffff;\n"
"    border: none;\n"
"    border-radius: 8px;\n"
"    padding: 8px 16px;\n"
"    font: 12pt \"Microsoft YaHei\";\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #71C871;  /* \346\233\264\346\267\261\344\270\200\345\261\202\357\274\214\347\252\201\345\207\272\346\202\254\345\201\234\346\225\210\346\236\234 */\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #5EBE5E;  /* \346\214\211\344\270\213\346\227\266\347\232\204\346\267\261\347\273\277\350\211\262 */\n"
"}"));
        resultlabel = new QLabel(centralwidget);
        resultlabel->setObjectName("resultlabel");
        resultlabel->setGeometry(QRect(510, 180, 261, 111));
        suggestionlist = new QListWidget(centralwidget);
        suggestionlist->setObjectName("suggestionlist");
        suggestionlist->setGeometry(QRect(50, 110, 441, 121));
        suggestionlist->setStyleSheet(QString::fromUtf8(""));
        suggestionlist->setProperty("showDropIndicator", QVariant(true));
        historylist = new QListWidget(centralwidget);
        historylist->setObjectName("historylist");
        historylist->setGeometry(QRect(50, 200, 701, 381));
        historylist->setStyleSheet(QString::fromUtf8(""));
        historylist->setSelectionMode(QAbstractItemView::SelectionMode::SingleSelection);
        historylist->setWordWrap(true);
        restartButton = new QPushButton(centralwidget);
        restartButton->setObjectName("restartButton");
        restartButton->setGeometry(QRect(490, 140, 131, 41));
        restartButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #42A5F5;\n"
"    color: #ffffff;\n"
"    border: none;\n"
"    border-radius: 8px;\n"
"    padding: 8px 16px;\n"
"    font: 12pt \"Microsoft YaHei\";\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #1E88E5;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #1976D2;\n"
"}"));
        surrenderButton = new QPushButton(centralwidget);
        surrenderButton->setObjectName("surrenderButton");
        surrenderButton->setGeometry(QRect(490, 140, 131, 41));
        surrenderButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #f44336;\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 8px;\n"
"    padding: 8px 16px;\n"
"    font: 12pt \"Microsoft YaHei\";\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #d32f2f;\n"
"}"));
        countlabel = new QLabel(centralwidget);
        countlabel->setObjectName("countlabel");
        countlabel->setGeometry(QRect(160, 140, 241, 41));
        countlabel->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font: bold 16pt \"Microsoft YaHei\";\n"
"    color: #333333;\n"
"    background-color: #f0f0f0;\n"
"    border: 2px solid #aaaaaa;\n"
"    border-radius: 10px;\n"
"    padding: 5px;\n"
"    qproperty-alignment: AlignCenter;\n"
"}"));
        statsButton = new QPushButton(centralwidget);
        statsButton->setObjectName("statsButton");
        statsButton->setGeometry(QRect(662, 590, 111, 41));
        statsButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #AB47BC;\n"
"    color: #ffffff;\n"
"    border: none;\n"
"    border-radius: 8px;\n"
"    padding: 6px 14px;\n"
"    font: 11pt \"Microsoft YaHei\";\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #9C27B0;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #7B1FA2;\n"
"}"));
        titlebar = new QWidget(centralwidget);
        titlebar->setObjectName("titlebar");
        titlebar->setGeometry(QRect(640, 10, 151, 41));
        minimizeButton = new QPushButton(titlebar);
        minimizeButton->setObjectName("minimizeButton");
        minimizeButton->setGeometry(QRect(10, 0, 41, 31));
        closeButton = new QPushButton(titlebar);
        closeButton->setObjectName("closeButton");
        closeButton->setGeometry(QRect(90, 0, 41, 31));
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
        minimizeButton->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        closeButton->setText(QCoreApplication::translate("MainWindow", "\303\227", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

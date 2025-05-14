/********************************************************************************
** Form generated from reading UI file 'statsdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATSDIALOG_H
#define UI_STATSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_StatsDialog
{
public:
    QPushButton *resetButton;
    QLabel *label;
    QLabel *label_2;
    QLabel *labelTotalGames;
    QLabel *labelWins;
    QLabel *label_5;
    QLabel *labelWinRate;
    QLabel *label_7;
    QLabel *labelAvgGuess;
    QLabel *label_9;
    QLabel *labelFastest;
    QLabel *label_11;
    QLabel *labelSlowest;
    QLabel *label_13;
    QLabel *labelCurrentStreak;
    QLabel *label_15;
    QLabel *labelBestStreak;
    QLabel *label_17;
    QProgressBar *progressWinRate;

    void setupUi(QDialog *StatsDialog)
    {
        if (StatsDialog->objectName().isEmpty())
            StatsDialog->setObjectName("StatsDialog");
        StatsDialog->resize(424, 375);
        resetButton = new QPushButton(StatsDialog);
        resetButton->setObjectName("resetButton");
        resetButton->setGeometry(QRect(300, 330, 93, 28));
        label = new QLabel(StatsDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(170, 10, 61, 21));
        label_2 = new QLabel(StatsDialog);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(30, 50, 69, 19));
        labelTotalGames = new QLabel(StatsDialog);
        labelTotalGames->setObjectName("labelTotalGames");
        labelTotalGames->setGeometry(QRect(130, 50, 101, 19));
        labelWins = new QLabel(StatsDialog);
        labelWins->setObjectName("labelWins");
        labelWins->setGeometry(QRect(130, 80, 101, 19));
        label_5 = new QLabel(StatsDialog);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(30, 80, 69, 19));
        labelWinRate = new QLabel(StatsDialog);
        labelWinRate->setObjectName("labelWinRate");
        labelWinRate->setGeometry(QRect(130, 110, 91, 19));
        label_7 = new QLabel(StatsDialog);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(30, 110, 69, 19));
        labelAvgGuess = new QLabel(StatsDialog);
        labelAvgGuess->setObjectName("labelAvgGuess");
        labelAvgGuess->setGeometry(QRect(130, 150, 141, 19));
        label_9 = new QLabel(StatsDialog);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(30, 150, 101, 19));
        labelFastest = new QLabel(StatsDialog);
        labelFastest->setObjectName("labelFastest");
        labelFastest->setGeometry(QRect(130, 180, 141, 19));
        label_11 = new QLabel(StatsDialog);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(30, 180, 69, 19));
        labelSlowest = new QLabel(StatsDialog);
        labelSlowest->setObjectName("labelSlowest");
        labelSlowest->setGeometry(QRect(130, 210, 151, 19));
        label_13 = new QLabel(StatsDialog);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(30, 210, 69, 19));
        labelCurrentStreak = new QLabel(StatsDialog);
        labelCurrentStreak->setObjectName("labelCurrentStreak");
        labelCurrentStreak->setGeometry(QRect(130, 250, 141, 19));
        label_15 = new QLabel(StatsDialog);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(30, 250, 69, 19));
        labelBestStreak = new QLabel(StatsDialog);
        labelBestStreak->setObjectName("labelBestStreak");
        labelBestStreak->setGeometry(QRect(130, 280, 141, 19));
        label_17 = new QLabel(StatsDialog);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(30, 280, 69, 19));
        progressWinRate = new QProgressBar(StatsDialog);
        progressWinRate->setObjectName("progressWinRate");
        progressWinRate->setGeometry(QRect(260, 110, 120, 23));
        progressWinRate->setValue(24);

        retranslateUi(StatsDialog);

        QMetaObject::connectSlotsByName(StatsDialog);
    } // setupUi

    void retranslateUi(QDialog *StatsDialog)
    {
        StatsDialog->setWindowTitle(QCoreApplication::translate("StatsDialog", "Dialog", nullptr));
        resetButton->setText(QCoreApplication::translate("StatsDialog", "\351\207\215\347\275\256", nullptr));
        label->setText(QCoreApplication::translate("StatsDialog", "\346\270\270\346\210\217\347\273\237\350\256\241", nullptr));
        label_2->setText(QCoreApplication::translate("StatsDialog", "\346\200\273\345\261\200\346\225\260:", nullptr));
        labelTotalGames->setText(QString());
        labelWins->setText(QString());
        label_5->setText(QCoreApplication::translate("StatsDialog", "\350\203\234\345\210\251\345\261\200\346\225\260:", nullptr));
        labelWinRate->setText(QString());
        label_7->setText(QCoreApplication::translate("StatsDialog", "\350\203\234\347\216\207:", nullptr));
        labelAvgGuess->setText(QString());
        label_9->setText(QCoreApplication::translate("StatsDialog", "\345\271\263\345\235\207\347\214\234\346\265\213\346\254\241\346\225\260:", nullptr));
        labelFastest->setText(QString());
        label_11->setText(QCoreApplication::translate("StatsDialog", "\346\234\200\345\277\253\347\214\234\344\270\255:", nullptr));
        labelSlowest->setText(QString());
        label_13->setText(QCoreApplication::translate("StatsDialog", "\346\234\200\346\205\242\347\214\234\344\270\255:", nullptr));
        labelCurrentStreak->setText(QString());
        label_15->setText(QCoreApplication::translate("StatsDialog", "\345\275\223\345\211\215\350\277\236\350\203\234:", nullptr));
        labelBestStreak->setText(QString());
        label_17->setText(QCoreApplication::translate("StatsDialog", "\346\234\200\351\253\230\350\277\236\350\203\234:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StatsDialog: public Ui_StatsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATSDIALOG_H

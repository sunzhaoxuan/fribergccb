#ifndef STATSDIALOG_H
#define STATSDIALOG_H

#include <QDialog>
#include "statsmanager.h"

namespace Ui {
class StatsDialog;
}

class StatsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit StatsDialog(StatsManager *statsManager,QWidget *parent = nullptr);
    ~StatsDialog();

private slots:
    void on_resetButton_clicked();

private:
    Ui::StatsDialog *ui;
    StatsManager *statsManager;

    void loadStats();
};

#endif // STATSDIALOG_H

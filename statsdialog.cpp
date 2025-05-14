#include "statsdialog.h"
#include "ui_statsdialog.h"

#include <QMessageBox>

StatsDialog::StatsDialog(StatsManager *statsManager,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::StatsDialog)
    , statsManager(statsManager)
{
    ui->setupUi(this);
    loadStats();
}

StatsDialog::~StatsDialog()
{
    delete ui;
}

void StatsDialog::loadStats()
{
    ui->labelTotalGames->setText(QString::number(statsManager->totalGames()));
    ui->labelWins->setText(QString::number(statsManager->winGames()));
    ui->labelWinRate->setText(QString::number(statsManager->winRate(), 'f', 1) + "%");
    ui->progressWinRate->setValue(static_cast<int>(statsManager->winRate()));

    ui->labelAvgGuess->setText(QString::number(statsManager->averageGuesses(), 'f', 1));
    ui->labelFastest->setText(QString::number(statsManager->fastestGuess()));
    ui->labelSlowest->setText(QString::number(statsManager->slowestGuess()));

    ui->labelCurrentStreak->setText(QString::number(statsManager->currentStreak()));
    ui->labelBestStreak->setText(QString::number(statsManager->bestStreak()));
}

void StatsDialog::on_resetButton_clicked()
{
    auto reply = QMessageBox::question(
        this,
        tr("确认重置"),
        tr("你确定要清除所有统计数据吗？此操作不可恢复。"),
        QMessageBox::Yes | QMessageBox::No
        );

    if (reply == QMessageBox::Yes) {
        statsManager->resetStats();
        loadStats();
        QMessageBox::information(this, tr("已重置"), tr("统计数据已被清除。"));
    }
}


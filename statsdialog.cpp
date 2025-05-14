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

    this->setWindowTitle("游戏统计");
    this->setStyleSheet(R"(
QDialog {
    background-color: #fdfdfd;
    border-radius: 12px;
}

QLabel {
    font-family: "Microsoft YaHei";
    font-size: 14px;
    color: #333;
}

QLabel#label {
    font-size: 18px;
    font-weight: bold;
    color: #2e7d32;
    qproperty-alignment: AlignCenter;
}

QPushButton {
    background-color: #4caf50;
    color: white;
    font-weight: bold;
    border-radius: 8px;
    padding: 6px 14px;
}

QPushButton:hover {
    background-color: #45a049;
}

QProgressBar {
    border: 1px solid #bbb;
    border-radius: 5px;
    background-color: #f1f1f1;
    text-align: center;
}

QProgressBar::chunk {
    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,
                                stop:0 #66bb6a, stop:1 #43a047);
    border-radius: 5px;
}
)");

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


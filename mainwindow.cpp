#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QTime>
#include <QDebug>
#include <QBrush>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("ccb");

    ui->suggestionlist->setStyleSheet("QListWidget { border: 1px solid gray; background: white; }");
    ui->suggestionlist->hide();
    ui->suggestionlist->raise();
    ui->countlabel->setText("剩余次数:10");

    ui->restartButton->hide();

    ui->historylist->setItemDelegate(new GuessItemDelegate(this));
    qRegisterMetaType<GuessResult>("GuessResult");

    srand(QTime::currentTime().msec());
    LoadCharacters();


    if (!characters.isEmpty()) {
        answer = characters[rand() % characters.size()];
    }

    connect(ui->lineEdit, &QLineEdit::textChanged, this, &MainWindow::UpdateSuggestionsSlot);
    connect(ui->suggestionlist, &QListWidget::itemClicked, this, &MainWindow::onSuggestionClickedSlot);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::LoadCharacters()
{
    QString path = QCoreApplication::applicationDirPath() + "/characters.json";
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly)) return;

    QByteArray data = file.readAll();

    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonArray arr = doc.array();
    for (const QJsonValue &val : arr) {
        QJsonObject obj = val.toObject();
        Character c;
        c.name = obj["name"].toString();
        QJsonArray tags = obj["tags"].toArray();
        for (const QJsonValue &t : tags) {
            c.tags << t.toString();
        }
        characters.append(c);
    }

}


void MainWindow::on_guessButton_clicked()
{

    QString input = ui->lineEdit->text().trimmed();
    Character *matched = nullptr;

    for(Character &c : characters)
    {
        if(c.name.trimmed() == input)
        {
            matched = &c;
            break;
        }
    }

    currentGuessCount++;

    ui->countlabel->setText("剩余次数:"+QString::number(10 - currentGuessCount));

    GuessResult result = GameLogic::processGuess(*matched, answer);

    QListWidgetItem* item = new QListWidgetItem();
    item->setData(Qt::UserRole, QVariant::fromValue(result));
    item->setSizeHint(QSize(300, 80));
    ui->historylist->addItem(item);

    if (matched->name == answer.name) {
        QMessageBox::information(this, "Win!", "你猜对了！人物是：" + answer.name);
        ui->guessButton->setEnabled(false);
        ui->lineEdit->setEnabled(false);
        ui->surrenderButton->hide();
        ui->restartButton->show();
    }

    if (currentGuessCount >= maxGuesses) {
        QMessageBox::information(this, "Lose!", "很遗憾，你没有猜中，正确答案是：" + answer.name);
        ui->lineEdit->setEnabled(false);
        ui->guessButton->setEnabled(false);
    }

    return;
}

int MainWindow::levenshteinDistance(const QString &s1, const QString &s2) {
    const int len1 = s1.length(), len2 = s2.length();
    QVector<QVector<int>> dp(len1 + 1, QVector<int>(len2 + 1));

    for (int i = 0; i <= len1; ++i) dp[i][0] = i;
    for (int j = 0; j <= len2; ++j) dp[0][j] = j;

    for (int i = 1; i <= len1; ++i) {
        for (int j = 1; j <= len2; ++j) {
            int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;
            dp[i][j] = std::min({
                dp[i - 1][j] + 1,
                dp[i][j - 1] + 1,
                dp[i - 1][j - 1] + cost
            });
        }
    }

    return dp[len1][len2];
}

void MainWindow::UpdateSuggestionsSlot(const QString &text)
{
    ui->suggestionlist->clear();

    QString input = text.trimmed();
    if(input.isEmpty())
    {
        ui->suggestionlist->hide();
        return;
    }

    QVector<QPair<int, Character>> results;
    for (const Character &c : characters) {
        int score = levenshteinDistance(input, c.name);
        results.append({score, c});
    }

    std::sort(results.begin(), results.end(), [](auto a, auto b) {
        return a.first < b.first;
    });

    int shown = 0;
    for (const auto &pair : results) {
        if (pair.first > 5) break;  //模糊匹配程度
        ui->suggestionlist->addItem(pair.second.name);
        shown++;
        if (shown >= 5) break;  //显示条目数
    }

    ui->suggestionlist->setVisible(shown > 0);
}

void MainWindow::onSuggestionClickedSlot(QListWidgetItem *item)
{
    QString name = item->text();
    ui->lineEdit->setText(name);

    on_guessButton_clicked();

    ui->lineEdit->clear();

    ui->suggestionlist->hide();
}


void MainWindow::on_restartButton_clicked()
{
    ui->historylist->clear();

    ui->guessButton->setEnabled(true);

    ui->lineEdit->setEnabled(true);

    ui->lineEdit->clear();

    ui->surrenderButton->show();

    ui->restartButton->hide();

    ui->countlabel->setText("剩余次数:10");

    currentGuessCount = 0;
}


void MainWindow::on_surrenderButton_clicked()
{
    ui->suggestionlist->hide();

    QMessageBox::information(this, "Lose!", "没想到吧！人物是：" + answer.name);

    ui->guessButton->setEnabled(false);

    ui->lineEdit->setEnabled(false);

    ui->surrenderButton->hide();

    ui->restartButton->show();

}


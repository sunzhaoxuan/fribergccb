#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "statsdialog.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QTime>
#include <QDebug>
#include <QBrush>
#include <QMessageBox>
#include <QKeyEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowFlags(Qt::FramelessWindowHint | Qt::Window);

    ui->titlebar->setStyleSheet(R"(
    QWidget#titleBar {
        background-color: #eeeeee;
        border-top-left-radius: 12px;
        border-top-right-radius: 12px;
    }
)");

    ui->minimizeButton->setStyleSheet(R"(
    QPushButton {
        background-color: transparent;
        border: none;
        font-size: 18px;
    }
    QPushButton:hover {
        background-color: #cccccc;
    }
)");

    ui->closeButton->setStyleSheet(R"(
    QPushButton {
        background-color: transparent;
        border: none;
        font-size: 18px;
    }
    QPushButton:hover {
        background-color: #e57373;
        color: white;
    }
)");

    ui->historylist->setStyleSheet(R"(
QListWidget {
    background-color: #fdfdfd;
    border: 1px solid #ccc;
    border-radius: 8px;
    padding: 4px;
    font-family: "Microsoft YaHei";
    font-size: 14px;
    color: #333;
}

QListWidget::item {
    padding: 10px 8px;
    margin: 4px 0;
    border-radius: 6px;
}

QListWidget::item:hover {
    background-color: #e0f2f1;
    color: #004d40;
}

QListWidget::item:selected {
    background-color: #a5d6a7;
    color: black;
}

QScrollBar:vertical {
    border: none;
    background: transparent;
    width: 8px;
    margin: 4px 0;
}

QScrollBar::handle:vertical {
    background: #c8e6c9;
    min-height: 20px;
    border-radius: 4px;
}

QScrollBar::add-line:vertical,
QScrollBar::sub-line:vertical {
    height: 0;
}

QScrollBar::add-page:vertical,
QScrollBar::sub-page:vertical {
    background: none;
}
)");

    this->setStyleSheet(R"(
    QLineEdit#lineEdit {
        border: 2px solid #ccc;
        border-radius: 10px;
        padding: 8px 12px;
        font-size: 16px;
        background-color: #fdfdfd;
    }

    QLineEdit#lineEdit:focus {
        border: 2px solid #66ccff;
        background-color: #f0faff;
    }

    QListWidget#suggestionlist {
        border: 1px solid #bbb;
        border-radius: 8px;
        background-color: #ffffff;
        font-size: 14px;
        padding: 4px;
    }

    QListWidget#suggestionlist::item {
        padding: 6px 10px;
    }

    QListWidget#suggestionlist::item:selected {
        background-color: #cceeff;
        font-weight: bold;
        color: #000;
        border-radius: 5px;
    }

    QListWidget#suggestionlist::item:hover {
        background-color: #e0f7ff;
    }
)");

    ui->suggestionlist->setStyleSheet("QListWidget { border: 1px solid gray; background: white; }");
    ui->suggestionlist->hide();
    ui->suggestionlist->raise();

    ui->countlabel->setText("剩余次数:5");

    ui->restartButton->hide();

    ui->historylist->setItemDelegate(new GuessItemDelegate(this));
    qRegisterMetaType<GuessResult>("GuessResult");

    srand(QTime::currentTime().msec());
    LoadCharacters();

    statsManager = new StatsManager(this);

    if (!characters.isEmpty()) {
        answer = characters[rand() % characters.size()];
    }

    connect(ui->lineEdit, &QLineEdit::textChanged, this, &MainWindow::UpdateSuggestionsSlot);
    connect(ui->suggestionlist, &QListWidget::itemClicked, this, &MainWindow::onSuggestionClickedSlot);
    connect(ui->closeButton, &QPushButton::clicked, this, &QWidget::close);
    connect(ui->minimizeButton, &QPushButton::clicked, this, &QWidget::showMinimized);
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
        c.id = obj["id"].toInt();
        c.pinyinFull = obj["pinyinFull"].toString();
        c.pinyinInitials = obj["pinyinInitials"].toString();
        QJsonArray tags = obj["tags"].toArray();
        for (const QJsonValue &t : tags) {
            c.tags << t.toString();
        }
        c.fetchDetailsFromApi();
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

    ui->countlabel->setText("剩余次数:"+QString::number(5 - currentGuessCount));

    GuessResult result = GameLogic::processGuess(*matched, answer);

    QListWidgetItem* item = new QListWidgetItem();
    item->setData(Qt::UserRole, QVariant::fromValue(result));
    item->setSizeHint(QSize(300, 80));
    ui->historylist->addItem(item);

    if (matched->name == answer.name) {

        ongameend(true);
    }

    if (currentGuessCount >= maxGuesses) {
        ongameend(false);
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

    bool isAlphaInput = std::all_of(input.begin(), input.end(), [](QChar ch) { //判断是否英文输入
        return ch.isLetter();
    });

    for (const Character &c : characters) {
        int nameScore = levenshteinDistance(input, c.name);
        int initialsScore = c.pinyinInitials.isEmpty() ? 100 : levenshteinDistance(input, c.pinyinInitials.toLower());
        int fullPinyinScore = c.pinyinFull.isEmpty() ? 100 : levenshteinDistance(input, c.pinyinFull.toLower());

        int score = std::min({nameScore, initialsScore, fullPinyinScore});
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

    ui->suggestionlist->setCurrentRow(0);
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

    ui->countlabel->setText("剩余次数:5");

    currentGuessCount = 0;

    answer = characters[rand() % characters.size()];
}


void MainWindow::on_surrenderButton_clicked()
{
    ongameend(false);
}

void MainWindow::ongameend(bool success)
{
    statsManager->recordGame(success, currentGuessCount);
    showEndGameDialog(success, answer);
    ui->suggestionlist->hide();
    ui->lineEdit->setEnabled(false);
    ui->guessButton->setEnabled(false);
    ui->surrenderButton->hide();
    ui->restartButton->show();
}

void MainWindow::keyPressEvent(QKeyEvent* event) {
    if (!ui->suggestionlist->isVisible()) {
        QMainWindow::keyPressEvent(event);
        return;
    }

    int currentRow = ui->suggestionlist->currentRow();
    int totalItems = ui->suggestionlist->count();

    switch (event->key()) {
    case Qt::Key_Down:
        ui->suggestionlist->setCurrentRow((currentRow + 1) % totalItems);
        break;

    case Qt::Key_Up:
        ui->suggestionlist->setCurrentRow((currentRow - 1 + totalItems) % totalItems);
        break;

    case Qt::Key_Return:
    case Qt::Key_Enter: {
        QListWidgetItem *item = ui->suggestionlist->currentItem();
        if (item) {
            onSuggestionClickedSlot(item);
        }
        break;
    }

    default:
        QMainWindow::keyPressEvent(event);
        break;
    }
}

void MainWindow::on_statsButton_clicked()
{
    StatsDialog dialog(statsManager, this);
    dialog.exec();
}


void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        dragging = true;
        dragPosition = event->globalPos() - this->frameGeometry().topLeft();
        event->accept();
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if (dragging && (event->buttons() & Qt::LeftButton)) {
        this->move(event->globalPos() - dragPosition);
        event->accept();
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    dragging = false;
}



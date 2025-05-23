#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "character.h"
#include "guessresult.h"
#include "gamelogic.h"
#include "guessitemdelegate.h"
#include "statsmanager.h"
#include "gameendmsg.h"
#include <QMainWindow>
#include <QVector>
#include <QStringList>
#include <QListWidgetItem>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_guessButton_clicked();

    void UpdateSuggestionsSlot(const QString &text);

    void onSuggestionClickedSlot(QListWidgetItem *item);

    void on_restartButton_clicked();

    void on_surrenderButton_clicked();

    void on_statsButton_clicked();

private:
    Ui::MainWindow *ui;
    void LoadCharacters();
    int levenshteinDistance(const QString &s1, const QString &s2);
    void DisplayTags(const Character& guess);
    void ongameend(bool success);
    QVector<Character> characters;
    Character answer;
    int maxGuesses = 5;
    int currentGuessCount = 0;
    StatsManager *statsManager;

    QPoint dragPosition;
    bool dragging = false;

protected:
    void keyPressEvent(QKeyEvent* event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
};
#endif // MAINWINDOW_H

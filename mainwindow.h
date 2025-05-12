#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QStringList>
#include <QListWidgetItem>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

struct Character{
    QString name;
    QStringList tags;
};

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

private:
    Ui::MainWindow *ui;
    void LoadCharacters();
    int levenshteinDistance(const QString &s1, const QString &s2);
    void DisplayTags(const Character& guess);
    QVector<Character> characters;
    Character answer;
};
#endif // MAINWINDOW_H

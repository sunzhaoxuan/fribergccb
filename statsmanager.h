#ifndef STATSMANAGER_H
#define STATSMANAGER_H

#include <QObject>
#include <QSettings>

class StatsManager : public QObject
{
    Q_OBJECT
public:
    explicit StatsManager(QObject *parent = nullptr);
    void recordGame(bool won, int guessCount);
    void resetStats();

    int totalGames() const;
    int winGames() const;
    double winRate() const;
    double averageGuesses() const;
    int fastestGuess() const;
    int slowestGuess() const;
    int currentStreak() const;
    int bestStreak() const;

private:
    QSettings settings;

signals:
};

#endif // STATSMANAGER_H

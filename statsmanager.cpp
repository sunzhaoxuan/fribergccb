#include "statsmanager.h"

StatsManager::StatsManager(QObject *parent)
    : QObject{parent}, settings("NKU", "ccb")
{}

void StatsManager::recordGame(bool won, int guessCount)
{
    int total = settings.value("stats/totalGames", 0).toInt() + 1;
    settings.setValue("stats/totalGames", total);

    int guessTotal = settings.value("stats/guessTotal", 0).toInt() + guessCount;
    settings.setValue("stats/guessTotal", guessTotal);

    if (won) {
        int wins = settings.value("stats/winGames", 0).toInt() + 1;
        settings.setValue("stats/winGames", wins);

        int current = settings.value("stats/currentStreak", 0).toInt() + 1;
        settings.setValue("stats/currentStreak", current);

        int best = settings.value("stats/bestStreak", 0).toInt();
        if (current > best)
            settings.setValue("stats/bestStreak", current);

        int fastest = settings.value("stats/fastest", 9999).toInt();
        if (guessCount < fastest)
            settings.setValue("stats/fastest", guessCount);

        int slowest = settings.value("stats/slowest", 0).toInt();
        if (guessCount > slowest)
            settings.setValue("stats/slowest", guessCount);
    } else {
        settings.setValue("stats/currentStreak", 0);
    }
}


void StatsManager::resetStats()
{
    settings.clear();
}

int StatsManager::totalGames() const { return settings.value("stats/totalGames", 0).toInt(); }
int StatsManager::winGames() const { return settings.value("stats/winGames", 0).toInt(); }

double StatsManager::winRate() const
{
    int total = totalGames();
    return total > 0 ? (double)winGames() / total * 100 : 0;
}

double StatsManager::averageGuesses() const
{
    int total = totalGames();
    return total > 0 ? (double)settings.value("stats/guessTotal", 0).toInt() / total : 0;
}

int StatsManager::fastestGuess() const { return settings.value("stats/fastest", 0).toInt(); }
int StatsManager::slowestGuess() const { return settings.value("stats/slowest", 0).toInt(); }
int StatsManager::currentStreak() const { return settings.value("stats/currentStreak", 0).toInt(); }
int StatsManager::bestStreak() const { return settings.value("stats/bestStreak", 0).toInt(); }

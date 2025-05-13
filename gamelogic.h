#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include "character.h"
#include "guessresult.h"
#include <QSet>

class GameLogic {
public:
    static GuessResult processGuess(const Character& guess, const Character& answer) {
        GuessResult result;
        result.guessedName = guess.name;
        result.tags = guess.tags;

        QSet<QString> answerTags(answer.tags.begin(), answer.tags.end());
        for (const QString& tag : guess.tags) {
            result.matched.append(answerTags.contains(tag));
        }
        return result;
    }
};


#endif // GAMELOGIC_H

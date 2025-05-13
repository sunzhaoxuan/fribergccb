#ifndef GUESSRESULT_H
#define GUESSRESULT_H

#include "qvariant.h"
#include <QString>
#include <QStringList>

struct GuessResult {
    QString guessedName;
    QStringList tags;
    QList<bool> matched;
};

Q_DECLARE_METATYPE(GuessResult)

#endif // GUESSRESULT_H

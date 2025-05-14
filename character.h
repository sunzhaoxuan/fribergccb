#ifndef CHARACTER_H
#define CHARACTER_H

#include <QString>
#include <QStringList>

class Character{
public:
    int id;
    QString name;
    QStringList tags;
    QString imageUrl;

    void fetchDetailsFromApi();
};

#endif // CHARACTER_H

#ifndef CHARACTER_H
#define CHARACTER_H

#include <QString>
#include <QStringList>
#include <QJsonObject>

class Character{
public:
    int id;
    QString name;
    QStringList tags;
    QString imageUrl;
    QString pinyinFull;
    QString pinyinInitials;

    void fetchDetailsFromApi();
    QJsonObject toJson() const;
};

#endif // CHARACTER_H

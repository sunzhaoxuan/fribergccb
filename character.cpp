#include "character.h"
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QEventLoop>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

void Character::fetchDetailsFromApi()
{
    QNetworkAccessManager manager;
    QEventLoop loop;
    QString url = QString("https://api.bgm.tv/v0/characters/%1").arg(id);

    QNetworkReply* reply = manager.get(QNetworkRequest(QUrl(url)));
    QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();

    if (reply->error() != QNetworkReply::NoError) {
        qWarning() << "Failed to fetch character info from API:" << reply->errorString();
        reply->deleteLater();
        return;
    }

    QByteArray data = reply->readAll();
    reply->deleteLater();

    QJsonDocument doc = QJsonDocument::fromJson(data);
    if (!doc.isObject()) {
        qWarning() << "Invalid JSON received";
        return;
    }

    QJsonObject obj = doc.object();

    if (obj.contains("images") && obj["images"].isObject()) {
        QJsonObject images = obj["images"].toObject();
        imageUrl = images["grid"].toString();
    }

}


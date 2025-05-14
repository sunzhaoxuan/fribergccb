#include "character.h"
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QEventLoop>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QTimer>

void Character::fetchDetailsFromApi()
{
    QNetworkAccessManager manager;
    QEventLoop loop;

    QNetworkRequest request(QUrl("https://api.bgm.tv/v0/characters/" + QString::number(id)));
    request.setHeader(QNetworkRequest::UserAgentHeader, "GuessCharacterGame/1.0");
    request.setRawHeader("Connection", "close");

    QNetworkReply *reply = manager.get(request);

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

QJsonObject Character::toJson() const {
    QJsonObject obj;
    obj["id"] = id;
    obj["name"] = name;
    obj["tags"] = QJsonArray::fromStringList(tags);
    obj["imageUrl"] = imageUrl;
    return obj;
}


#include "gameendmsg.h"
#include "character.h"

#include <QDialog>
#include <QVBoxLayout>
#include <QLabel>
#include <QDialogButtonBox>
#include <QPixmap>
#include <QUrl>
#include <QDesktopServices>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QEventLoop>


QPixmap loadImageFromUrl(const QString& url) {
    QNetworkAccessManager manager;
    QEventLoop loop;
    QNetworkReply* reply = manager.get(QNetworkRequest(QUrl(url)));
    QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();

    QPixmap pixmap;
    if (reply->error() == QNetworkReply::NoError) {
        pixmap.loadFromData(reply->readAll());
    }
    reply->deleteLater();
    return pixmap;
}

void showEndGameDialog(bool success, const Character& character) {
    QDialog dialog;
    dialog.setWindowTitle(success ? "Win！" : "Lose!");

    QVBoxLayout* layout = new QVBoxLayout(&dialog);

    QString url = QString("https://bgm.tv/character/%1").arg(character.id);
    QString status = success ? "你猜对了！" : "你没猜中。";
    QString name = QString("人物：%1").arg(character.name);
    QString linkHtml = QString("<a href='%1'>点击查看人物详情</a>").arg(url);

    QLabel* statusLabel = new QLabel(status);
    QLabel* nameLabel = new QLabel(name);
    QLabel* linkLabel = new QLabel(linkHtml);
    linkLabel->setTextFormat(Qt::RichText);
    linkLabel->setTextInteractionFlags(Qt::TextBrowserInteraction);
    linkLabel->setOpenExternalLinks(true);

    // 加载头像
    if (!character.imageUrl.isEmpty()) {
        QPixmap avatar = loadImageFromUrl(character.imageUrl);
        if (!avatar.isNull()) {
            QLabel* avatarLabel = new QLabel;
            avatarLabel->setPixmap(avatar.scaled(128, 128, Qt::KeepAspectRatio, Qt::SmoothTransformation));
            avatarLabel->setAlignment(Qt::AlignCenter);
            layout->addWidget(avatarLabel);
        }
    }

    layout->addWidget(statusLabel);
    layout->addWidget(nameLabel);
    layout->addWidget(linkLabel);

    QDialogButtonBox* buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok);
    layout->addWidget(buttonBox);
    QObject::connect(buttonBox, &QDialogButtonBox::accepted, &dialog, &QDialog::accept);

    dialog.exec();
}


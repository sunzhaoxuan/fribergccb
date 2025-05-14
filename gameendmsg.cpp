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
    dialog.setWindowTitle(success ? "Win！" : "Lose。");
    dialog.setFixedSize(400, 400);
    dialog.setStyleSheet(R"(
        QDialog {
            background-color: #fefefe;
            border: 1px solid #dcdcdc;
            border-radius: 12px;
        }
        QLabel {
            font-family: "Microsoft YaHei";
            font-size: 14px;
            color: #333;
        }
        QLabel#statusLabel {
            font-size: 18px;
            font-weight: bold;
            color: #2e7d32;
        }
        QLabel#statusLabel[fail="true"] {
            color: #c62828;
        }
        QLabel#nameLabel {
            font-size: 16px;
            color: #555;
        }
        QLabel#linkLabel {
            color: #1e88e5;
            font-weight: bold;
        }
        QDialogButtonBox QPushButton {
            background-color: #4caf50;
            color: white;
            border-radius: 6px;
            padding: 6px 16px;
        }
        QDialogButtonBox QPushButton:hover {
            background-color: #45a049;
        }
    )");

    QVBoxLayout* layout = new QVBoxLayout(&dialog);
    layout->setContentsMargins(20, 20, 20, 20);
    layout->setSpacing(15);

    QLabel* statusLabel = new QLabel(success ? "你猜对了！" : "你没猜中。");
    statusLabel->setObjectName("statusLabel");
    if (!success)
        statusLabel->setProperty("fail", true);

    QLabel* nameLabel = new QLabel(QString("人物：%1").arg(character.name));
    nameLabel->setObjectName("nameLabel");

    QString url = QString("https://bgm.tv/character/%1").arg(character.id);
    QLabel* linkLabel = new QLabel(QString("<a href='%1'>点击查看人物详情</a>").arg(url));
    linkLabel->setObjectName("linkLabel");
    linkLabel->setTextFormat(Qt::RichText);
    linkLabel->setTextInteractionFlags(Qt::TextBrowserInteraction);
    linkLabel->setOpenExternalLinks(true);

    if (!character.imageUrl.isEmpty()) {
        QPixmap avatar = loadImageFromUrl(character.imageUrl);
        if (!avatar.isNull()) {
            QLabel* avatarLabel = new QLabel;
            avatarLabel->setPixmap(avatar.scaled(150, 150, Qt::KeepAspectRatio, Qt::SmoothTransformation));
            avatarLabel->setAlignment(Qt::AlignCenter);
            layout->addWidget(avatarLabel);
        }
    }

    layout->addWidget(statusLabel, 0, Qt::AlignHCenter);
    layout->addWidget(nameLabel, 0, Qt::AlignHCenter);
    layout->addWidget(linkLabel, 0, Qt::AlignHCenter);

    // 按钮
    QDialogButtonBox* buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok);
    layout->addWidget(buttonBox, 0, Qt::AlignCenter);
    QObject::connect(buttonBox, &QDialogButtonBox::accepted, &dialog, &QDialog::accept);

    dialog.exec();
}



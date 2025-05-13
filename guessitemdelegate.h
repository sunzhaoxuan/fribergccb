#ifndef GUESSITEMDELEGATE_H
#define GUESSITEMDELEGATE_H

#include <QStyledItemDelegate>
#include <QPainter>
#include "guessresult.h"

class GuessItemDelegate : public QStyledItemDelegate {
public:
    using QStyledItemDelegate::QStyledItemDelegate;

    void paint(QPainter* painter, const QStyleOptionViewItem& option,
               const QModelIndex& index) const override {
        painter->save();
        painter->setRenderHint(QPainter::Antialiasing);

        GuessResult result = index.data(Qt::UserRole).value<GuessResult>();

        QRect r = option.rect;
        painter->drawText(r.left(), r.top() + 15, result.guessedName);

        int x = r.left() + 10;
        int y = r.top() + 35;
        QFont font = painter->font();
        font.setPointSize(10);
        painter->setFont(font);

        for (int i = 0; i < result.tags.size(); ++i) {
            QString tag = result.tags[i];
            QColor color = result.matched[i] ? Qt::darkGreen : Qt::black;
            painter->setPen(color);
            painter->drawText(x, y, tag);

            x += QFontMetrics(font).horizontalAdvance(tag + "  ");
            if (x > r.right() - 100) {
                x = r.left() + 10;
                y += 20;
            }
        }

        painter->restore();
    }

    QSize sizeHint(const QStyleOptionViewItem& option, const QModelIndex&) const override {
        return QSize(option.rect.width(), 80);
    }
};

#endif // GUESSITEMDELEGATE_H

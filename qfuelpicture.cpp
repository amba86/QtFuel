#include "qfuelpicture.h"

#include <QDebug>

QFuelPicture::QFuelPicture(const QString &path,
                           QSize size,
                           QWidget *parent) : QLabel(parent) {
    pmap = new QPixmap(path);
    this->size = size;

    setNum(0);
}

QFuelPicture::~QFuelPicture() {
    delete pmap;
}

void QFuelPicture::setNum(int num) {
    if (num / 256.0 < 0.33) {
        setPixmap(empty());
    } else if (num / 256.0 < 0.66) {
        setPixmap(halfFull());
    } else {
        setPixmap(full());
    }

    emit pictureChanged(pixmap());
}

QPixmap QFuelPicture::empty() {
    return overlay(QColor("#FF0000"));
}

QPixmap QFuelPicture::full() {
    return overlay(QColor("#00FF00"));
}

QPixmap QFuelPicture::halfFull() {
    return overlay(QColor("#FFFF00"));
}

QPixmap QFuelPicture::overlay(QColor color) {
    QPixmap map = pmap->copy();
    QPainter painter(&map);
    painter.setCompositionMode(QPainter::CompositionMode_SourceIn);
    painter.fillRect(map.rect(), color.rgb());
    painter.end();

    return map.scaled(size, Qt::KeepAspectRatio, Qt::SmoothTransformation);
}

#include "qfuelpicture.h"

#include <QDebug>

QFuelPicture::QFuelPicture(const QString &path,
                           QSize *size,
                           QColor *emptyColor,
                           QColor *fullColor,
                           QColor *halfFullColor,
                           QWidget *parent) : QLabel(parent) {
    pmap = new QPixmap(path);
    this->size = size;
    this->emptyColor = emptyColor;
    this->fullColor = fullColor;
    this->halfFullColor = halfFullColor;

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

QColor* QFuelPicture::getHalfFullColor() const {
    return halfFullColor;
}

void QFuelPicture::setHalfFullColor(QColor *value) {
    halfFullColor = value;
}

QColor* QFuelPicture::getFullColor() const {
    return fullColor;
}

void QFuelPicture::setFullColor(QColor *value) {
    fullColor = value;
}

QColor* QFuelPicture::getEmptyColor() const {
    return emptyColor;
}

void QFuelPicture::setEmptyColor(QColor *value) {
    emptyColor = value;
}

QPixmap QFuelPicture::empty() {
    return overlay(emptyColor);
}

QPixmap QFuelPicture::full() {
    return overlay(fullColor);
}

QPixmap QFuelPicture::halfFull() {
    return overlay(halfFullColor);
}

QPixmap QFuelPicture::overlay(QColor *color) {
    QPixmap map = pmap->copy();
    QPainter painter(&map);
    painter.setCompositionMode(QPainter::CompositionMode_SourceIn);
    painter.fillRect(map.rect(), color->rgb());
    painter.end();

    return map.scaled(*size, Qt::KeepAspectRatio, Qt::SmoothTransformation);
}

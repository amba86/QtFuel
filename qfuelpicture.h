#ifndef QFUELPICTURE_H
#define QFUELPICTURE_H

#include <QSize>
#include <QColor>
#include <QLabel>
#include <QPixmap>
#include <QPainter>

class QFuelPicture : public QLabel {
    Q_OBJECT

public:
    QFuelPicture(const QString &path,
                 QSize size,
                 QWidget *parent = nullptr);
    ~QFuelPicture() Q_DECL_OVERRIDE;

    QPixmap empty();
    QPixmap full();
    QPixmap halfFull();

public slots:
    void setNum(int num);

private:
    QSize size;
    QPixmap *pmap;

    QPixmap overlay(QColor color);

signals:
    void pictureChanged(QPixmap const *newPixmap);
};

#endif // QFUELPICTURE_H

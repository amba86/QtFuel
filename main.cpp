#include "qsensor.h"
#include "qbargraph.h"
#include "qfuelpicture.h"

#include <QApplication>
#include <QHBoxLayout>
#include <QWidget>
#include <QPixmap>
#include <QLabel>
#include <QSize>

// TODO: remove
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget widget;
    QPalette palette;
    palette.setColor(QPalette::Background, Qt::blue);

    QFuelPicture picture(":/assets/fuel.png", QSize(160, 160), &widget);

    QColor backgroundColor("#AAAAAA");
    QColor cursorColor("#FFFF00");
    QColor textColor("#000000");
    QColor progressColor("#FFFF00");
    QBrush progressBrush(progressColor);

    QBarGraph bar(&backgroundColor,
                  &cursorColor,
                  &textColor,
                  &progressColor,
                  &progressBrush,
                  &widget);
    bar.setCornerRadius(20);
    bar.setPadding(20);
    bar.setMinimum(0);
    bar.setMaximum(255);
    bar.setFixedHeight(100);

    QHBoxLayout layout(&widget);
    layout.addWidget(&picture);
    layout.addWidget(&bar);

    widget.setPalette(palette);
    widget.setLayout(&layout);
    widget.setFixedSize(640, 480);

    QSensor sensor(&widget);
    sensor.start();

    QObject::connect(&sensor, SIGNAL(valueChanged(int)), &bar, SLOT(setValue(int)));
    QObject::connect(&sensor, SIGNAL(valueChanged(int)), &picture, SLOT(setNum(int)));

    widget.show();
    return a.exec();
}

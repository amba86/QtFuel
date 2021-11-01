#include "qmodel.h"
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
    palette.setColor(QPalette::Background, QColor("#073B4C"));

    QSize scaledSize(160, 160);
    QColor emptyColor("#EF476F");
    QColor fullColor("#06D6A0");
    QColor halfFullColor("#FFD166");
    QFuelPicture picture(":/assets/fuel.png",
                         &scaledSize,
                         &emptyColor,
                         &fullColor,
                         &halfFullColor,
                         &widget);

    QColor backgroundColor("#0A4F66");
    QColor cursorColor("#118AB2");
    QColor textColor("#073B4C");
    QColor progressColor("#118AB2");
    QBrush progressBrush(progressColor);

    QBarGraph bar(&backgroundColor,
                  &cursorColor,
                  &textColor,
                  &progressColor,
                  &progressBrush,
                  &widget);
    bar.setCornerRadius(20);
    bar.setPadding(35);
    bar.setMinimum(0);
    bar.setMaximum(255);
    bar.setFixedHeight(100);

    QHBoxLayout layout(&widget);
    layout.addWidget(&picture);
    layout.addWidget(&bar);

    widget.setPalette(palette);
    widget.setLayout(&layout);
    widget.setFixedSize(640, 480);

    QModel model;

    QSensor sensor(&widget);
    sensor.start();

    QObject::connect(&sensor, SIGNAL(valueChanged(int)), &model, SLOT(setFuelLevel(int)));
    QObject::connect(&model, SIGNAL(fuelLevelChanged(int)), &bar, SLOT(setValue(int)));
    QObject::connect(&model, SIGNAL(fuelLevelChanged(int)), &picture, SLOT(setNum(int)));

    widget.show();
    return a.exec();
}

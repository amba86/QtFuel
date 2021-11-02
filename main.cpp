#include "qmodel.h"
#include "qsensor.h"
#include "qbargraph.h"
#include "qfuelpicture.h"

#include <QApplication>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QCheckBox>
#include <QWidget>
#include <QPixmap>
#include <QLabel>
#include <QSize>

int main(int argc, char *argv[]) {
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
    QColor textboxColor("#118AB2");
    QColor textColor("#073B4C");
    QColor progressColor("#118AB2");
    QBrush progressBrush(progressColor);

    QBarGraph bar(&backgroundColor,
                  &textboxColor,
                  &textColor,
                  &progressColor,
                  &progressBrush,
                  &widget);
    bar.setCornerRadius(20);
    bar.setPadding(35);
    bar.setMinimum(0);
    bar.setMaximum(255);
    bar.setFixedHeight(100);

    QCheckBox checkBox("100% &slope (45°)", &widget);

    QHBoxLayout hLayout(&widget);
    QVBoxLayout vLayout(&widget);
    vLayout.addStretch(6);
    vLayout.addWidget(&bar);
    vLayout.addStretch(4);
    vLayout.addWidget(&checkBox);
    vLayout.setAlignment(&checkBox, Qt::AlignRight);
    hLayout.addWidget(&picture);
    hLayout.addLayout(&vLayout);

    widget.setPalette(palette);
    widget.setLayout(&hLayout);
    widget.setFixedSize(640, 480);

    QModel model(&widget);
    QSensor sensor(&widget);
    sensor.start();

    QObject::connect(&checkBox, SIGNAL(stateChanged(int)), &model, SLOT(setSlope(int)));
    QObject::connect(&sensor, SIGNAL(valueChanged(int)), &model, SLOT(setFuelLevel(int)));
    QObject::connect(&model, SIGNAL(fuelLevelChanged(int)), &bar, SLOT(setValue(int)));
    QObject::connect(&model, SIGNAL(fuelLevelChanged(int)), &picture, SLOT(setFuelLevel(int)));

    widget.show();
    return a.exec();
}

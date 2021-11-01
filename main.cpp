#include "qbargraph.h"
#include "qfuelpicture.h"

#include <QApplication>
#include <QHBoxLayout>
#include <QWidget>
#include <QPixmap>
#include <QLabel>
#include <QSize>

// TODO: remove
#include <QSlider>
#include <QDebug>
#include <QPainter>
#include <QImage>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget widget;
    QPalette palette;
    palette.setColor(QPalette::Background, Qt::blue);

    QSlider *slider = new QSlider(Qt::Vertical, &widget);
    slider->setMinimum(0);
    slider->setMaximum(255);

    QFuelPicture *picture = new QFuelPicture(":/assets/fuel.png",
                                             QSize(160, 160),
                                             &widget);

    QBarGraph *bar = new QBarGraph(&widget);
    bar->setPadding(20);
    bar->setMinimum(0);
    bar->setMaximum(255);
    bar->setFixedHeight(100);
    bar->setCornerRadius(20);

    QHBoxLayout *layout = new QHBoxLayout(&widget);
    layout->addWidget(slider);
    layout->addWidget(picture);
    layout->addWidget(bar);

    QObject::connect(slider, SIGNAL(valueChanged(int)), bar, SLOT(setValue(int)));
    QObject::connect(slider, SIGNAL(valueChanged(int)), picture, SLOT(setNum(int)));

    widget.setPalette(palette);
    widget.setLayout(layout);
    widget.setFixedSize(640, 480);
    widget.show();
    return a.exec();
}

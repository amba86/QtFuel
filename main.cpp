#include "qbargraph.h"

#include <QApplication>
#include <QHBoxLayout>
#include <QWidget>

// TODO: remove
#include <QSlider>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget w;
    QPalette p;
    p.setColor(QPalette::Background, Qt::blue);

    QSlider *s = new QSlider(Qt::Vertical, &w);
    s->setMinimum(0);
    s->setMaximum(255);

    QBarGraph *b = new QBarGraph(&w);
    b->setPadding(20);
    b->setValue(0);
    b->setMinimum(0);
    b->setMaximum(255);
    b->setFixedHeight(100);
    b->setCornerRadius(20);

    QHBoxLayout *l = new QHBoxLayout(&w);
    l->addWidget(s);
    l->addWidget(b);

    QObject::connect(s, SIGNAL(valueChanged(int)), b, SLOT(setValue(int)));

    w.setPalette(p);
    w.setLayout(l);
    w.setFixedSize(640, 480);
    w.show();
    return a.exec();
}

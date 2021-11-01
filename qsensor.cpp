#include "qsensor.h"

#include <QDebug>
#include <QDateTime>
#include <QtMath>

QSensor::QSensor(QObject *parent = nullptr) : QThread(parent) {
    value = -256;
    ascending = true;
}

QSensor::~QSensor() {
    // NOP
}

void QSensor::run() {
    while (true) {
        if (ascending) {
            value++;

            if (value == 255) {
                ascending = false;
            }
        } else {
            value--;

            if (value == -255) {
                ascending = true;
            }
        }

        qDebug() << value;

        emit valueChanged(value);
        msleep(200);
    }
}
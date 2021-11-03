#include "qsensor.h"

#include <QtMath>

QSensor::QSensor(QObject *parent) : QThread(parent) {
    value = 0;
    angle = 0.0;
}

QSensor::~QSensor() {
    // NOP
}

void QSensor::run() {
    while (true) {
        value = -255 * cos(angle);
        angle += M_PI / 360;

        emit valueChanged(value);

        msleep(200);
    }
}

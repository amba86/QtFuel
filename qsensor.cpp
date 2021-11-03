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
        value = generateData(angle);
        angle = nextAngle(angle);

        emit valueChanged(value);

        msleep(200);
    }
}

int QSensor::generateData(double angle) {
    return -255 * cos(angle);
}

double QSensor::nextAngle(double angle) {
    return angle + M_PI / 360;
}

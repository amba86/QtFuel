#include "qsensor.h"

#include <QtMath>

QSensor::QSensor(QObject *parent) : QThread(parent) {
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

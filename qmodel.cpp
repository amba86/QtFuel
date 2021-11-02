#include "qmodel.h"

#include <QtMath>

QModel::QModel(QObject *parent) : QObject(parent) {
    slope = false;
    fuelLevel = 0;

    setSlope(0);
}

QModel::~QModel() {
    // NOP
}

int QModel::getFuelLevel() const {
    return fuelLevel;
}

void QModel::setSlope(int newValue) {
    if ((slope = (bool) newValue)) {
        threshold = 0.1;
    } else {
        threshold = 0.05;
    }
}

void QModel::setFuelLevel(int newValue) {
    int value = std::max(0, newValue);

    if (fuelLevel == value
            || (value != 0
                && value != 255
                && (fabs(fuelLevel - value) / 256.0) < threshold)) {
        return;
    }

    fuelLevel = value;

    emit fuelLevelChanged(fuelLevel);
}

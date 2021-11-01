#include "qmodel.h"

#include <QtMath>

QModel::QModel(QObject *parent) : QObject(parent) {
    fuelLevel = 0;
}

int QModel::getFuelLevel() const {
    return fuelLevel;
}

void QModel::setFuelLevel(int newValue) {
    int value = std::max(0, newValue);

    if (fuelLevel == value
            || (value != 0
                && value != 255
                && (fabs(fuelLevel - value) / 256.0) < 0.05)) {
        return;
    }

    fuelLevel = value;

    emit fuelLevelChanged(fuelLevel);
}

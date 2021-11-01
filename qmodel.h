#ifndef QMODEL_H
#define QMODEL_H

#include <QObject>

class QModel : public QObject
{
    Q_OBJECT
public:
    explicit QModel(QObject *parent = nullptr);

    int getFuelLevel() const;

public slots:
    void setFuelLevel(int newValue);

signals:
    void fuelLevelChanged(int newFuelLevel);

private:
    int fuelLevel;

};

#endif // QMODEL_H
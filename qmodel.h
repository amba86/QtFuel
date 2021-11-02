#ifndef QMODEL_H
#define QMODEL_H

#include <QObject>

class QModel : public QObject {
    Q_OBJECT

public:
    explicit QModel(QObject *parent = nullptr);
    ~QModel() Q_DECL_OVERRIDE;

    int getFuelLevel() const;

public slots:
    void setSlope(int newValue);
    void setFuelLevel(int newValue);

signals:
    void fuelLevelChanged(int newFuelLevel);

private:
    bool slope;
    int fuelLevel;
    double threshold;

};

#endif // QMODEL_H

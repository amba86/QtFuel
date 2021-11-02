#ifndef SENSOR_H
#define SENSOR_H

#include <QThread>

class QSensor : public QThread {
    Q_OBJECT

public:
    explicit QSensor(QObject *parent = nullptr);
    ~QSensor() Q_DECL_OVERRIDE;

signals:
    void valueChanged(int newValue);

protected:
    void run();

private:
    int value;
    double angle;

};

#endif // SENSOR_H

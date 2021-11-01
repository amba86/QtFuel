#ifndef SENSOR_H
#define SENSOR_H

#include <QThread>

class QSensor : public QThread {
    Q_OBJECT

public:
    QSensor(QObject *parent);
    ~QSensor();

protected:
    void run();

private:
    int value;
    bool ascending;

signals:
    void valueChanged(int newValue);
};

#endif // SENSOR_H
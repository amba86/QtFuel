#ifndef SENSOR_H
#define SENSOR_H

#include <QThread>

/*!
 * \brief The QSensor class simulates a physical fuel level sensor and generates data in the range -255 to 255.
 */
class QSensor : public QThread {
    Q_OBJECT

public:

    /*!
     * \brief QSensor Creates new sensor instance.
     * \param parent If parent is 0, the new widget becomes a window. If parent is another widget, this widget becomes a child window inside parent.
     */
    explicit QSensor(QObject *parent = nullptr);

    /*!
     * Destroys the instance.
     */
    ~QSensor() Q_DECL_OVERRIDE;

signals:

    /*!
     * \brief valueChanged Emits the valueChanged(int) signal when new data is created.
     * \param newValue The data representing the fuel level.
     */
    void valueChanged(int newValue);

protected:

    /*!
     * \brief run Generates new data every 200 ms using the cosine wave.
     */
    void run();

private:

    /*!
     * \brief value The data representing the fuel level.
     */
    int value;

    /*!
     * \brief angle The current cosine angle.
     */
    double angle;

    /*!
     * \brief generateValue Creates a new data based on the specified angle.
     * \param angle The current angle in degrees.
     * \return The new data.
     */
    int generateData(double angle);

    /*!
     * \brief nextAngle Calculates the next angle.
     * \param angle The current angle.
     * \return A calculated angle.
     */
    double nextAngle(double angle);

};

#endif // SENSOR_H

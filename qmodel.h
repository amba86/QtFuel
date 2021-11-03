#ifndef QMODEL_H
#define QMODEL_H

#include <QObject>

/*!
 * \brief The QModel class that receives external data and prepares it for viewing.
 */
class QModel : public QObject {
    Q_OBJECT

public:

    /*!
     * \brief QModel Creates new model instance.
     * \param parent If parent is 0, the new widget becomes a window. If parent is another widget, this widget becomes a child window inside parent.
     */
    explicit QModel(QObject *parent = nullptr);

    /*!
     * Destroys the model instance.
     */
    ~QModel() Q_DECL_OVERRIDE;

    /*!
     * \brief getFuelLevel Returns the fuel level.
     * \return The fuel level.
     */
    int getFuelLevel() const;

public slots:

    /*!
     * \brief setSlope Sets the slope.
     * \param newValue An integer value is converted to a boolean value.
     */
    void setSlope(int newValue);

    /*!
     * @brief setFuelLevel Sets the fuel level. The fuel level is set when
     * the range between the current value and the given value is greater than a threshold.
     * Emits the fuelLevelChanged(int) signal when the fuel level changes.
     * @param newValue The fuel level.
     */
    void setFuelLevel(int newValue);

signals:

    /*!
     * \brief fuelLevelChanged Emits the fuelLevelChanged(int) signal when the fuel level changes.
     * \param newFuelLevel The current fuel level.
     */
    void fuelLevelChanged(int newFuelLevel);

private:

    /*!
     * \brief slope Indicates slope state.
     */
    bool slope;

    /*!
     * \brief fuelLevel The current fuel level.
     */
    int fuelLevel;

    /*!
     * \brief threshold The fuel level is updated only when it is above the threshold of 5% (10% for slope).
     */
    double threshold;

};

#endif // QMODEL_H

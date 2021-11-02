#ifndef QFUELPICTURE_H
#define QFUELPICTURE_H

#include <QSize>
#include <QColor>
#include <QLabel>
#include <QPixmap>
#include <QPainter>

/*!
 * \brief Loads and displays an image, which is passed as a parameter.
 */
class QFuelPicture : public QLabel {
    Q_OBJECT

public:

    /*!
     * \brief QFuelPicture Creates a new object to display an image.
     * \param path A path to an image file.
     * \param size The size of the image.
     * \param emptyColor A color that indicates the empty fuel level.
     * \param fullColor A color that indicates the full fuel level.
     * \param halfFullColor A color that indicates the halffull fuel level.
     * \param parent If parent is 0, the new widget becomes a window. If parent is another widget, this widget becomes a child window inside parent.
     */
    QFuelPicture(const QString &path,
                 QSize *size,
                 QColor *emptyColor,
                 QColor *fullColor,
                 QColor *halfFullColor,
                 QWidget *parent = nullptr);

    /*!
     * \brief Destroys the picture.
     */
    ~QFuelPicture() Q_DECL_OVERRIDE;

    /*!
     * @brief empty Returns an image indicating the empty fuel level.
     * @return An image indicating the empty fuel level.
     */
    QPixmap empty();

    /*!
     * @brief full Returns an image indicating the full fuel level.
     * @return An image indicating the full fuel level.
     */
    QPixmap full();

    /*!
     * @brief halfFull Returns an image indicating the halffull fuel level.
     * @return An image indicating the halffull fuel level.
     */
    QPixmap halfFull();

    /*!
     * \brief getEmptyColor Returns a color that indicates the empty fuel level.
     * \return A color that indicates the empty fuel level.
     */
    QColor* getEmptyColor() const;

    /*!
     * \brief setEmptyColor Sets a color that indicates the empty fuel level.
     * \param value A color that indicates the empty fuel level.
     */
    void setEmptyColor(QColor *value);

    /*!
     * \brief getFullColor Returns a color that indicates the full fuel level.
     * \return A color that indicates the full fuel level.
     */
    QColor* getFullColor() const;

    /*!
     * \brief setFullColor Sets a color that indicates the full fuel level.
     * \param value A color that indicates the full fuel level.
     */
    void setFullColor(QColor *value);

    /*!
     * \brief getHalfFullColor Returns a color that indicates the halffull fuel level.
     * \return A color that indicates the halffull fuel level.
     */
    QColor* getHalfFullColor() const;

    /*!
     * \brief setHalfFullColor Sets a color that indicates the halffull fuel level.
     * \param value A color that indicates the halffull fuel level.
     */
    void setHalfFullColor(QColor *value);

public slots:

    /*!
     * \brief setFuelLevel Changes the color of the image depending on the fuel level. The fuel
     * level below 84 will be indicating as empty, between 84-167 as halfful and over 167 as full.
     * Emits the pictureChanged(QPixmap *) signal when the color changes.
     * \param fuelLevel The fuel level.
     */
    void setFuelLevel(int fuelLevel);

signals:

    /*!
     * \brief pictureChanged Emits the pictureChanged(QPixmap *) signal when the color of the image changes.
     * \param newPixmap The object of type \c QPixmap representing the current image.
     */
    void pictureChanged(QPixmap const *newPixmap);

private:

    /*!
     * \brief size The size of the image.
     */
    QSize *size;

    /*!
     * \brief pmap An image which was loaded.
     */
    QPixmap *pmap;

    /*!
     * \brief emptyColor A color that indicates the empty fuel level.
     */
    QColor *emptyColor;

    /*!
     * \brief fullColor A color that indicates the full fuel level.
     */
    QColor *fullColor;

    /*!
     * \brief halfFullColor A color that indicates the halffull fuel level.
     */
    QColor *halfFullColor;

    /*!
     * \brief overlay Draws an overlay over the image.
     * \param color The color of the overlay.
     * \return A colored picture.
     */
    QPixmap overlay(QColor *color);

};

#endif // QFUELPICTURE_H

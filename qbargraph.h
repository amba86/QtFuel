#ifndef QBARGRAPH_H
#define QBARGRAPH_H

#include <QProgressBar>

/*!
 * \brief Draws a progress bar with a text box under it.
 */
class QBarGraph : public QProgressBar {
    Q_OBJECT

public:

    /*!
    * \brief QBarGraph Creates a new progress bar.
    * \param backgroundColor A background color of the progress bar.
    * \param textboxColor A text box color of the progress bar.
    * \param textColor A text color of the progress bar.
    * \param progressColor A color of the current progress bar.
    * \param progressBrush A brush of the current progress bar. If set, then the color of the text box and the progress bar will be ignored.
    * \param parent If parent is 0, the new widget becomes a window. If parent is another widget, this widget becomes a child window inside parent.
    */
    explicit QBarGraph(QColor *backgroundColor = nullptr,
                       QColor *textboxColor = nullptr,
                       QColor *textColor = nullptr,
                       QColor *progressColor = nullptr,
                       QBrush *progressBrush = nullptr,
                       QWidget *parent = nullptr);

    /*!
     * \brief Destroys the progress bar.
     */
    ~QBarGraph() Q_DECL_OVERRIDE;

    /*!
     * \brief getBackgroundColor Returns the background color.
     * \return The background color.
     */
    QColor* getBackgroundColor() const;

    /*!
     * \brief setBackgroundColor Sets the background color.
     * \param value The background color.
     */
    void setBackgroundColor(QColor *value);

    /*!
     * \brief getTextboxColor Returns the text box color.
     * \return The text box color.
     */
    QColor* getTextboxColor() const;

    /*!
     * \brief setTextboxColor Sets the text box color.
     * \param value The text box color.
     */
    void setTextboxColor(QColor *value);

    /*!
     * \brief getTextColor Returns the text color.
     * \return The text box color.
     */
    QColor* getTextColor() const;

    /*!
     * \brief setTextColor Sets the text color.
     * \param value The text color.
     */
    void setTextColor(QColor *value);

    /*!
     * \brief getProgressColor Returns the current progress color.
     * \return The current progress color.
     */
    QColor* getProgressColor() const;

    /*!
     * \brief setProgressColor Sets the current progress color.
     * \param value The current progress color.
     */
    void setProgressColor(QColor *value);

    /*!
     * \brief getProgressBrush Returns the current progress brush.
     * \return The current progress brush.
     */
    QBrush* getProgressBrush() const;

    /*!
     * \brief setProgressBrush Sets the current progress brush.  If set, then the color of the text box and the progress bar will be ignored.
     * \param value The current progress brush.
     */
    void setProgressBrush(QBrush *value);

    /*!
     * \brief getCornerRadius Returns the corner radius of the progress bar.
     * \return The corner radius of the progress bar.
     */
    int getCornerRadius() const;

    /*!
     * \brief setCornerRadius Sets the corner radius of the progress bar.
     * \param value The corner radius of the progress bar.
     */
    void setCornerRadius(int value);

    /*!
     * \brief getPadding Returns the left and right padding of the progress bar.
     * \return The left and right padding of the progress bar.
     */
    int getPadding() const;

    /*!
     * \brief setPadding Sets the left and right padding of the progress bar. Defines the length of the text box.
     * \param value The left and right padding of the progress bar.
     */
    void setPadding(int value);

protected:

    /*!
     * @brief paintEvent Overrides the drawing of the default progress bar. First the background is drawn, then progress and finally the text box.
     * @param event Will not be used.
     */
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

private:
    /*!
     * \brief backgroundColor The background color of the progress bar.
     */
    QColor *backgroundColor;

    /*!
     * \brief textboxColor The text box color of the progress bar.
     */
    QColor *textboxColor;

    /*!
     * \brief textColor The text color of the progress bar.
     */
    QColor *textColor;

    /*!
     * \brief progressColor The color of the current progress.
     */
    QColor *progressColor;

    /*!
     * \brief progressBrush The brush of the current progress. If set, then the color of the text box and the progress bar will be ignored.
     */
    QBrush *progressBrush;

    /*!
     * \brief cornerRadius The corner radius of the progress bar.
     */
    int cornerRadius;

    /*!
     * \brief cursorOffset The offset between the progress bar and the text box.
     */
    int cursorOffset;

    /*!
     * \brief padding The left and right padding of the progress bar. Defines the length of the text box.
     */
    int padding;

    /*!
     * \brief progress Returns the current progress in pixels.
     * \return The current progress in pixels.
     */
    int progress();

    /*!
     * \brief paintBackground Draws the background of progress bar.
     * \param painter An object to paint on widgets.
     */
    void paintBackground(QPainter *painter);

    /*!
     * \brief paintProgress Draws the current progress of progress bar.
     * \param painter An object to paint on widgets.
     */
    void paintProgress(QPainter *painter);

    /*!
     * \brief paintTextbox Draws the text box of progress bar.
     * \param painter An object to paint on widgets.
     */
    void paintTextbox(QPainter *painter);

    /*!
     * \brief paintCursor Draws the cursor between the progress bar and the text box.
     * \param painter An object to paint on widgets.
     * \param rect The rectangle of the text box to draw the cursor in the top center of the text box.
     */
    void paintCursor(QPainter *painter, QRect rect);

    /*!
     * \brief paintText Draws the text inside the text box.
     * \param painter An object to paint on widgets.
     * \param rect The rectangle of the text box to draw the text inside the text box.
     */
    void paintText(QPainter *painter, QRect rect);
};

#endif // QBARGRAPH_H

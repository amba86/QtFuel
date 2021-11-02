#ifndef QBARGRAPH_H
#define QBARGRAPH_H

#include <QProgressBar>

class QBarGraph : public QProgressBar {
    Q_OBJECT

public:
   explicit QBarGraph(QColor *backgroundColor = nullptr,
              QColor *cursorColor = nullptr,
              QColor *textColor = nullptr,
              QColor *progressColor = nullptr,
              QBrush *progressBrush = nullptr,
              QWidget *parent = nullptr);

    ~QBarGraph() Q_DECL_OVERRIDE;

    QColor* getBackgroundColor() const;
    void setBackgroundColor(QColor *value);

    QColor* getCursorColor() const;
    void setCursorColor(QColor *value);

    QColor* getTextColor() const;
    void setTextColor(QColor *value);

    QColor* getProgressColor() const;
    void setProgressColor(QColor *value);

    QBrush* getProgressBrush() const;
    void setProgressBrush(QBrush *value);

    int getCornerRadius() const;
    void setCornerRadius(int value);

    int getPadding() const;
    void setPadding(int value);

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

private:
    QColor *backgroundColor;
    QColor *cursorColor;
    QColor *textColor;
    QColor *progressColor;

    QBrush *progressBrush;

    int cornerRadius;
    int cursorOffset;
    int padding;

    int progress();
    void paintBackground(QPainter *painter);
    void paintProgress(QPainter *painter);
    void paintTextbox(QPainter *painter);
    void paintCursor(QPainter *painter, QRect rect);
    void paintText(QPainter *painter, QRect rect);
};

#endif // QBARGRAPH_H

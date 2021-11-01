#ifndef QBARGRAPH_H
#define QBARGRAPH_H

#include <QProgressBar>

class QBarGraph : public QProgressBar {
    Q_OBJECT

public:
    QBarGraph(QWidget *parent = nullptr,
              QColor backgroundColor = Qt::gray,
              QColor cursorColor = Qt::yellow,
              QColor textColor = Qt::black,
              QColor progressColor = Qt::yellow,
              QBrush progressBrush = Qt::NoBrush,
              int cornerRadius = 0,
              int cursorOffset = 5,
              int padding = 0);

    ~QBarGraph() Q_DECL_OVERRIDE;

    QColor getBackgroundColor() const;
    void setBackgroundColor(const QColor &value);

    QColor getCursorColor() const;
    void setCursorColor(const QColor &value);

    QColor getTextColor() const;
    void setTextColor(const QColor &value);

    QColor getProgressColor() const;
    void setProgressColor(const QColor &value);

    QBrush getProgressBrush() const;
    void setProgressBrush(const QBrush &value);

    int getCornerRadius() const;
    void setCornerRadius(int value);

    int getCursorOffset() const;
    void setCursorOffset(int value);

    int getPadding() const;
    void setPadding(int value);

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
    void paintBackground(QPainter *painter);
    void paintTextbox(QPainter *painter);
    void paintProgress(QPainter *painter);

private:
    QColor backgroundColor;
    QColor cursorColor;
    QColor textColor;
    QColor progressColor;

    QBrush progressBrush;

    int cornerRadius;
    int cursorOffset;
    int padding;

    int progress();
    void paintCursor(QPainter *painter, QRect rect);
    void paintText(QPainter *painter, QRect rect);
};

#endif // QBARGRAPH_H

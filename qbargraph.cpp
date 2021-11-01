#include "qbargraph.h"

#include <QStylePainter>

QBarGraph::QBarGraph(QWidget *parent,
                     QColor backgroundColor,
                     QColor cursorColor,
                     QColor textColor,
                     QColor progressColor,
                     QBrush progressBrush,
                     int cornerRadius,
                     int cursorOffset,
                     int padding) : QProgressBar(parent) {
    this->backgroundColor = backgroundColor;
    this->cursorColor = cursorColor;
    this->textColor = textColor;
    this->progressColor = progressColor;
    this->progressBrush = progressBrush;
    this->cornerRadius = cornerRadius;
    this->cursorOffset = cursorOffset;
    this->padding = padding;

    setValue(0);
}

QBarGraph::~QBarGraph() {
    // NOP
}

void QBarGraph::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);

    // TODO: make member
    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing |
                           QPainter::TextAntialiasing);

    paintBackground(&painter);
    paintProgress(&painter);
    paintTextbox(&painter);
}

void QBarGraph::paintBackground(QPainter *painter) {
    painter->save();
    painter->setPen(Qt::NoPen);
    painter->setBrush(backgroundColor);

    QRect rect(padding, 0, width() - padding * 2, height() / 3);
    painter->drawRoundedRect(rect, cornerRadius, cornerRadius);

    painter->restore();
}

void QBarGraph::paintProgress(QPainter *painter) {
    painter->save();
    painter->setPen(Qt::NoPen);
    painter->setBrush(progressBrush == Qt::NoBrush ? progressColor : progressBrush);

    QRect rect(padding, 0, progress(), height() / 3);
    painter->drawRoundedRect(rect, cornerRadius, cornerRadius);

    painter->restore();
}

int QBarGraph::progress() {
    double step = value() / (double)(maximum() - minimum());
    int progress = (width() - padding * 2) * step;

    return progress;
}

void QBarGraph::paintTextbox(QPainter *painter) {
    painter->save();
    painter->setPen(Qt::NoPen);
    painter->setBrush(progressBrush == Qt::NoBrush ? cursorColor : progressBrush);

    QRect rect(progress(), height() / 3 + cursorOffset, padding * 2, height() / 3);
    painter->drawRoundedRect(rect, 4, 4);

    paintCursor(painter, rect);
    paintText(painter, rect);

    painter->restore();
}

void QBarGraph::paintCursor(QPainter *painter, QRect rect) {
    int centerX = rect.center().x();
    int y = height() / 3;
    QPolygon polygon;
    polygon.append(QPoint(centerX, y));
    polygon.append(QPoint(centerX + cursorOffset, y + cursorOffset));
    polygon.append(QPoint(centerX - cursorOffset, y + cursorOffset));
    painter->drawPolygon(polygon);
}

void QBarGraph::paintText(QPainter *painter, QRect rect) {
    double percent = value() / (double)(maximum() - minimum()) * 100;
    QString text = QString("%1%").arg(percent, 0, 'f', 0);
    painter->setPen(textColor);
    // TODO: set font
    //    painter->setFont();
    painter->drawText(rect, Qt::AlignCenter, text);
}

QColor QBarGraph::getBackgroundColor() const {
    return backgroundColor;
}

void QBarGraph::setBackgroundColor(const QColor &value) {
    backgroundColor = value;
}

QColor QBarGraph::getCursorColor() const {
    return cursorColor;
}

void QBarGraph::setCursorColor(const QColor &value) {
    cursorColor = value;
}

QColor QBarGraph::getTextColor() const {
    return textColor;
}

void QBarGraph::setTextColor(const QColor &value) {
    textColor = value;
}

QColor QBarGraph::getProgressColor() const {
    return progressColor;
}

void QBarGraph::setProgressColor(const QColor &value) {
    progressColor = value;
}

int QBarGraph::getCursorOffset() const {
    return cursorOffset;
}

void QBarGraph::setCursorOffset(int value) {
    cursorOffset = value;
}

QBrush QBarGraph::getProgressBrush() const {
    return progressBrush;
}

void QBarGraph::setProgressBrush(const QBrush &value) {
    progressBrush = value;
}

int QBarGraph::getCornerRadius() const {
    return cornerRadius;
}

void QBarGraph::setCornerRadius(int value) {
    cornerRadius = value;
}

int QBarGraph::getPadding() const {
    return padding;
}

void QBarGraph::setPadding(int value) {
    padding = value;
}

#include "qbargraph.h"

#include <QStylePainter>

QBarGraph::QBarGraph(QColor *backgroundColor,
                     QColor *cursorColor,
                     QColor *textColor,
                     QColor *progressColor,
                     QBrush *progressBrush,
                     QWidget *parent) : QProgressBar(parent) {
    this->backgroundColor = backgroundColor;
    this->cursorColor = cursorColor;
    this->textColor = textColor;
    this->progressColor = progressColor;
    this->progressBrush = progressBrush;
    this->cornerRadius = 0;
    this->cursorOffset = 5;
    this->padding = 0;

    setValue(0);
}

QBarGraph::~QBarGraph() {
    // NOP
}

void QBarGraph::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);

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
    painter->setBrush(*backgroundColor);

    QRect rect(padding, 0, width() - padding * 2, height() / 3);
    painter->drawRoundedRect(rect, cornerRadius, cornerRadius);

    painter->restore();
}

void QBarGraph::paintProgress(QPainter *painter) {
    painter->save();
    painter->setPen(Qt::NoPen);
    painter->setBrush(*progressBrush == Qt::NoBrush ? *progressColor : *progressBrush);

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
    painter->setBrush(*progressBrush == Qt::NoBrush ? *cursorColor : *progressBrush);

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
    QString text = QString("%1 %").arg(percent, 0, 'f', 0);
    painter->setPen(*textColor);
    painter->setFont(QFont("Lato", 10, QFont::Bold));
    painter->drawText(rect, Qt::AlignCenter, text);
}

QColor* QBarGraph::getBackgroundColor() const {
    return backgroundColor;
}

void QBarGraph::setBackgroundColor(QColor *value) {
    backgroundColor = value;
}

QColor* QBarGraph::getCursorColor() const {
    return cursorColor;
}

void QBarGraph::setCursorColor(QColor *value) {
    cursorColor = value;
}

QColor* QBarGraph::getTextColor() const {
    return textColor;
}

void QBarGraph::setTextColor(QColor *value) {
    textColor = value;
}

QColor* QBarGraph::getProgressColor() const {
    return progressColor;
}

void QBarGraph::setProgressColor(QColor *value) {
    progressColor = value;
}

QBrush* QBarGraph::getProgressBrush() const {
    return progressBrush;
}

void QBarGraph::setProgressBrush(QBrush *value) {
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

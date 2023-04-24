
#pragma once

#include <QGVDrawItem.h>

#include <QBrush>
#include <QPen>

class Rectangle : public QGVDrawItem
{
    Q_OBJECT

public:
    explicit Rectangle(const QGV::GeoRect& geoRect, QGV::ItemFlags flags, QColor color);

private:
    void onProjection(QGVMap* geoMap) override;
    void onUpdate() override;
    QPainterPath projShape() const override;
    void projPaint(QPainter* painter) override;
    QPointF projAnchor() const override;
    QTransform projTransform() const override;
    QString projTooltip(const QPointF& projPos) const override;
    void projOnMouseClick(const QPointF& projPos) override;
    void projOnMouseDoubleClick(const QPointF& projPos) override;
    void projOnObjectStartMove(const QPointF& projPos) override;
    void projOnObjectMovePos(const QPointF& projPos) override;
    void projOnObjectStopMove(const QPointF& projPos) override;

private:
    QGV::GeoRect mGeoRect;
    QRectF mProjRect;
    QColor mColor;
};

#pragma once

#include <QWidget>

#include "QGVCamera.h"
#include "QGVGlobal.h"
#include "QGVProjection.h"

class QGVItem;
class QGVDrawItem;
class QGVWidget;
class QGVMapQGScene;
class QGVMapQGView;

class QGV_LIB_DECL QGVMap : public QWidget
{
    Q_OBJECT

public:
    explicit QGVMap(QWidget* parent = 0);
    ~QGVMap();

    const QGVCameraState getCamera() const;
    void cameraTo(const QGVCameraActions& actions, bool animation = false);
    void flyTo(const QGVCameraActions& actions);

    void setProjection(QGV::Projection id);
    void setProjection(QGVProjection* projection);
    QGVProjection* getProjection() const;

    void setMouseActions(QGV::MouseActions actions);
    void setMouseAction(QGV::MouseAction action, bool enabled = true);
    QGV::MouseActions getMouseActions() const;
    bool isMouseAction(QGV::MouseAction action) const;

    QGVItem* rootItem() const;
    QGVMapQGView* geoView() const;

    void addItem(QGVItem* item);
    void removeItem(QGVItem* item);
    void deleteItems();
    int countItems() const;
    QGVItem* getItem(int index) const;

    void addWidget(QGVWidget* widget);
    void removeWidget(QGVWidget* widget);
    void deleteWidgets();
    int countWidgets() const;
    QGVWidget* getWigdet(int index) const;

    void select(QGVItem* item);
    void unselect(QGVItem* item);
    void unselectAll();
    QSet<QGVItem*> getSelections() const;

    QList<QGVDrawItem*> search(const QPointF& projPos, Qt::ItemSelectionMode mode = Qt::ContainsItemShape) const;
    QList<QGVDrawItem*> search(const QRectF& projRect, Qt::ItemSelectionMode mode = Qt::ContainsItemShape) const;
    QList<QGVDrawItem*> search(const QPolygonF& projPolygon, Qt::ItemSelectionMode mode = Qt::ContainsItemShape) const;

    QPixmap grabMapView(bool includeWidgets = true) const;

    QPointF mapToProj(QPoint pos);
    QPoint mapFromProj(QPointF projPos);

    void refreshMap();
    void refreshProjection();
    void anchoreWidgets();

    virtual void onMapState(QGV::MapState state);
    virtual void onMapCamera(const QGVCameraState& oldState, const QGVCameraState& newState);

public:
    void mouseMoveEvent(QMouseEvent* event ) ;
    void mousePressEvent(QMouseEvent* event ) ;
    void drawLineBetweenCoords(const QGV::GeoPos& startCoords, const QGV::GeoPos& endCoords);
public:
    void addPath(const QPainterPath& path, const QColor& color);
    QPointF geoToPixel(const QGV::GeoPos & geoPos) const;

public:
    QPixmap m_pixmap;
Q_SIGNALS:
    void projectionChanged();
    void scaleChanged();
    void azimuthChanged();
    void areaChanged();
    void itemsChanged(QGVItem* parent);
    void stateChanged(QGV::MapState state);
    void itemClicked(QGVItem* item, QPointF projPos);
    void itemDoubleClicked(QGVItem* item, QPointF projPos);
    void mapMouseMove(QPointF projPos);
    void mapMousePress(QGV::GeoPos projPos);

private:
    QScopedPointer<QGVProjection> mProjection;
    QScopedPointer<QGVMapQGView> mQGView;
    QScopedPointer<QGVItem> mRootItem;
    QList<QGVWidget*> mWidgets;
    QSet<QGVItem*> mSelections;
};

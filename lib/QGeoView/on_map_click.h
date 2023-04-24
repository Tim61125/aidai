#ifndef ON_MAP_CLICK_H
#define ON_MAP_CLICK_H
#include <QObject>
#include <QPointF>
#include <QGVMap.h>

class on_map_click : public QGVMap {
    Q_OBJECT

public:
    on_map_click(QWidget *parent = nullptr) : QGVMap(parent) {}

public:
    void mousePressEvent(QMouseEvent *event) override;
};


#endif // ON_MAP_CLICK_H

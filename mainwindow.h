#include <QMainWindow>
#include <QWidget>
#include <QQuickWidget>
#include <QNetworkAccessManager>
#include <QNetworkDiskCache>
#include <QGVWidgetScale.h>
#include <QGVWidgetZoom.h>
#include <QGraphicsView>
#include "demoitem.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    class MapView : public QGraphicsView
    {
    public:
        explicit MapView(QWidget *parent = nullptr);
        virtual ~MapView();


    protected:
        //void mousePressEvent(QMouseEvent *event) override;
    };

public:
    MainWindow(QWidget *parent = nullptr);
    //void on_map_clicked(QMouseEvent* event);

public:
    ~MainWindow();

private slots:
    void init();
    void on_pushButton_2_clicked();
    void on_pushButton_4_clicked();


void mousePress(QGV::GeoPos  coords);
public:
    void addPath(const QPainterPath& path, const QColor& color);

private:
    std::vector<QGV::GeoPos> coordsList;
private:
    Ui::MainWindow* ui;
    QNetworkAccessManager* mManager;
    QNetworkDiskCache* mCache;
    DemoItem* mCurrentItem;
    QList<DemoItem*> mDemo;
    QGVMap* map;
};


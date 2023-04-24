#include "mainwindow.h"
#include "samples/background.h"
#include "samples/customtiles.h"
#include "samples/flags.h"
#include "samples/items.h"
#include "samples/mouse.h"
#include "samples/utilities.h"
#include "samples/widgets.h"
#include "ui_mainwindow.h"
#include <QtLocation>
#include <QAction>
#include <QClipboard>
#include <QDir>
#include <QGVDrawItem.h>
#include <QQuickView>
#include <QMessageBox>
#include "on_map_click.h"
#include "QGVMap.h"
#include <QPainter>
using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : ui(new Ui::MainWindow)


{
    ui->setupUi(this);

   // connect(ui->mapWidget, &QGVMap::mousePressEvent, ui->mapWidget, &QGVMap::handleMousePress);
    // Создание экземпляра класса on_map_click
    connect(ui->geoMap, &QGVMap::mapMousePress, this, &MainWindow::mousePress);




    // получаем указатель на виджет, на котором отображается карта
   // QGVMapQGView* geoMapWidget = ui->geoMap->geoView();

    // подключаем обработчик события нажатия на мышь к виджету
   // connect(ui->geoMap, &QWidget::mouseMoveEvent, this, &MainWindow::on_map_clicked);
    //qInfo() << "Широта: " << "1" << ", Долгота: " << "2";


    //connect(ui->geoMap, &QMapControl::mousePressEvent, this, &MainWindow::map_click);

    //connect(ui->geoMap, &QMapControl::mousePressEvent, this, &MainWindow::map_click);
   /*

    auto actPosition = new QAction("Print position", this);
    ui->geoMap->addAction(actPosition);
    connect(actPosition, &QAction::triggered, actPosition, [this]() {
        auto cam = ui->geoMap->getCamera();
        auto rect = cam.getProjection()->projToGeo(cam.projRect());
        auto pos = cam.getProjection()->projToGeo(cam.projRect().center());
        qInfo() << "current geo-rect" << rect;
        qInfo() << "current geo-center" << pos;
    });



    auto actSelectView = new QAction("Select all (view)", this);
    ui->geoMap->addAction(actSelectView);
    connect(actSelectView, &QAction::triggered, actSelectView, [this]() {
        ui->geoMap->unselectAll();
        auto selection = ui->geoMap->search(ui->geoMap->getCamera().projRect());
        for (auto item : selection) {
            item->select();
        }
    });*/
    /*
    auto actPosition = new MouseDemo("Print position", this);
    ui->geoMap->addAction(actPosition);
    connect(actPosition, &MouseDemo::triggered, actPosition, [this](){
        auto geoPos = geoMap()->getProjection()->projToGeo(projPos);
        qInfo() << "current geo-rect" << rect;
        qInfo() << "current geo-center" << pos;
    });
*/
    QPushButton *pushbutton = ui->pushButton;
   // QLineEdit *latEdit = ui->lineEdit;
    QObject::connect(pushbutton, &QPushButton::clicked, [this]() {
        //double latitude = latEdit->text().toDouble();
        //double longitude = latEdit->text().toDouble();
        auto target = QGV::GeoRect(QGV::GeoPos(42.457804, 76.164155), QGV::GeoPos(42.450984, 76.183362));
        ui->geoMap->cameraTo(QGVCameraActions(ui->geoMap).scaleTo(target), true);
        QGVMap *map = new QGVMap();


    });
    QQuickWidget *panel = new QQuickWidget;
    panel->setSource(QUrl("qrc:/panel.qml"));
    ui->horizontalLayout_4->addWidget(panel);

    QQuickWidget *camera = new QQuickWidget;
    camera->setSource(QUrl("qrc:/camera.qml"));
    ui->horizontalLayout_3->addWidget(camera);
    QMetaObject::invokeMethod(this, "init", Qt::QueuedConnection);

}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::init()
{

    QDir("cacheDir").removeRecursively();
    mCache = new QNetworkDiskCache(this);
    mCache->setCacheDirectory("cacheDir");
    mManager = new QNetworkAccessManager(this);
    mManager->setCache(mCache);
    QGV::setNetworkManager(mManager);
    DemoItem* item = new BackgroundDemo(ui->geoMap, this);
    DemoItem* mouseItem = new MouseDemo(ui->geoMap, this);
    item->init();
    mouseItem->init();
    auto target = ui->geoMap->getProjection()->boundaryGeoRect();
    ui->geoMap->cameraTo(QGVCameraActions(ui->geoMap).scaleTo(target));

}
void MainWindow::on_pushButton_2_clicked()
{
     QMessageBox::information(this, tr("Button clicked"), tr("The button was clicked!"));
}


void MainWindow::on_pushButton_4_clicked()
{
     QDockWidget *dock = new QDockWidget("My Widget", this);
     dock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
     dock->setWidget(ui->dockWidget_3);
     dock->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
     dock->setFeatures(QDockWidget::NoDockWidgetFeatures);
     // Отключение перемещения и изменения размера
     dock->setFeatures(QDockWidget::NoDockWidgetFeatures);
     dock->setMinimumSize(200, 200);
     dock->setMaximumSize(400, 400);
     // Установка нового виджета для заголовка панели (убирает заголовок)
     dock->setTitleBarWidget(new QWidget());

     addDockWidget(Qt::LeftDockWidgetArea, dock);
     dock->show();

     // Включение перемещения и изменения размера
     dock->setFeatures(QDockWidget::DockWidgetMovable | QDockWidget::DockWidgetFloatable);
}

//void MainWindow::on_map_clicked(QMouseEvent* event)
//{ ифин ша нщг пшму ещ ьу ш лтщц црфе нщг цфте
     //QGVMapQGView* geoMapWidget = ui->geoMap->geoView();
     //QPoint pos = QCursor::pos();
     //QPointF coords = geoMapWidget->mapToGeo(pos);

     //qDebug() << "Широта: " << coords.y() << ", Долгота: " << coords.x();
    // qInfo() << "Широта: " << "1" << ", Долгота: " << "2";
//}
// void MouseDemo::onMouseMovee(QPoint projPos)
//{
//     /*
//     * Current projection position can be converted to geo-coordinates and
//     * printed by corresponding functions
//     */
//     auto geoPos = geoMap()->getProjection()->projToGeo(projPos);
//     mText->setText(QString("<b>%1, %2</b>").arg(geoPos.latToString()).arg(geoPos.lonToString()));
//}
void MainWindow::mousePress(QGV::GeoPos coords) {
     coordsList.push_back(coords);

     // Draw a polyline between the coordinates in coordsList
     if (coordsList.size() >= 2) {
         // create a new path for each line
         QPainterPath linePath;
         linePath.moveTo(ui->geoMap->geoToPixel(coordsList.at(coordsList.size()-2)));
         linePath.lineTo(ui->geoMap->geoToPixel(coordsList.at(coordsList.size()-1)));

         // draw the path on the map
         ui->geoMap->update(); // add this line
         ui->geoMap->addPath(linePath, QColor(Qt::red));
         ui->geoMap->update();
     }
}


   //QVector<QPointF> m_coordsArray;
         //QPoint pos = event->pos(); // Получаем координаты мыши
         //QPoint coord = ui->geoMap->mapToProj(coords); // Преобразуем координаты в географические координаты
         // Записываем координаты в массив
         //m_coordsArray.append(coords);

         // Выводим координаты в консоль
        //qInfo() << "Координаты: " << coords;





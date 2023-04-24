QT += gui widgets network

DEFINES += QGV_EXPORT

SOURCES += \
    $$PWD/QGVCamera.cpp \
    $$PWD/QGVDrawItem.cpp \
    $$PWD/QGVGlobal.cpp \
    $$PWD/QGVUtils.cpp \
    $$PWD/QGVImage.cpp \
    $$PWD/QGVItem.cpp \
    $$PWD/QGVLayer.cpp \
    $$PWD/QGVLayerBing.cpp \
    $$PWD/QGVLayerGoogle.cpp \
    $$PWD/QGVLayerOSM.cpp \
    $$PWD/QGVLayerTiles.cpp \
    $$PWD/QGVLayerTilesOnline.cpp \
    $$PWD/QGVMap.cpp \
    $$PWD/QGVMapQGItem.cpp \
    $$PWD/QGVMapQGView.cpp \
    $$PWD/QGVMapRubberBand.cpp \
    $$PWD/QGVProjection.cpp \
    $$PWD/QGVProjectionEPSG3857.cpp \
    $$PWD/QGVWidget.cpp \
    $$PWD/QGVWidgetCompass.cpp \
    $$PWD/QGVWidgetScale.cpp \
    $$PWD/QGVWidgetText.cpp \
    $$PWD/QGVWidgetZoom.cpp

HEADERS += \
    $$PWD/QGeoView/QGVCamera.h \
    $$PWD/QGeoView/QGVDrawItem.h \
    $$PWD/QGeoView/QGVGlobal.h \
    $$PWD/QGeoView/QGVUtils.h \
    $$PWD/QGeoView/QGVImage.h \
    $$PWD/QGeoView/QGVItem.h \
    $$PWD/QGeoView/QGVLayer.h \
    $$PWD/QGeoView/QGVLayerBing.h \
    $$PWD/QGeoView/QGVLayerGoogle.h \
    $$PWD/QGeoView/QGVLayerOSM.h \
    $$PWD/QGeoView/QGVLayerTiles.h \
    $$PWD/QGeoView/QGVLayerTilesOnline.h \
    $$PWD/QGeoView/QGVMap.h \
    $$PWD/QGeoView/QGVMapQGItem.h \
    $$PWD/QGeoView/QGVMapQGView.h \
    $$PWD/QGeoView/QGVMapRubberBand.h \
    $$PWD/QGeoView/QGVProjection.h \
    $$PWD/QGeoView/QGVProjectionEPSG3857.h \
    $$PWD/QGeoView/QGVWidget.h \
    $$PWD/QGeoView/QGVWidgetCompass.h \
    $$PWD/QGeoView/QGVWidgetScale.h \
    $$PWD/QGeoView/QGVWidgetText.h \
    $$PWD/QGeoView/QGVWidgetZoom.h \
    $$PWD/on_map_click.h

INCLUDEPATH += \
    $$PWD/QGeoView/

FORMS +=

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_AUTOMOC ON)

# Set the QT version
find_package(Qt6 COMPONENTS Core QUIET)
if (NOT Qt6_FOUND)
    set(QT_VERSION 5 CACHE STRING "Qt version for QGeoView")
else()
    set(QT_VERSION 6 CACHE STRING "Qt version for QGeoView")
endif()

find_package(Qt${QT_VERSION} REQUIRED COMPONENTS
     Core
     Gui
     Widgets
     Network
)

add_library(qgeoview SHARED
    QGeoView/QGVGlobal.h
    QGeoView/QGVUtils.h
    QGeoView/QGVProjection.h
    QGeoView/QGVProjectionEPSG3857.h
    QGeoView/QGVCamera.h
    QGeoView/QGVMap.h
    QGeoView/QGVMapQGItem.h
    QGeoView/QGVMapQGView.h
    QGeoView/QGVMapRubberBand.h
    QGeoView/QGVItem.h
    QGeoView/QGVDrawItem.h
    QGeoView/QGVLayer.h
    QGeoView/QGVImage.h
    QGeoView/QGVLayerTiles.h
    QGeoView/QGVLayerTilesOnline.h
    QGeoView/QGVLayerGoogle.h
    QGeoView/QGVLayerBing.h
    QGeoView/QGVLayerOSM.h
    QGeoView/QGVWidget.h
    QGeoView/QGVWidgetCompass.h
    QGeoView/QGVWidgetScale.h
    QGeoView/QGVWidgetZoom.h
    QGeoView/QGVWidgetText.h
    QGVUtils.cpp
    QGVGlobal.cpp
    QGVProjection.cpp
    QGVProjectionEPSG3857.cpp
    QGVCamera.cpp
    QGVMap.cpp
    QGVMapQGItem.cpp
    QGVMapQGView.cpp
    QGVMapRubberBand.cpp
    QGVItem.cpp
    QGVDrawItem.cpp
    QGVLayer.cpp
    QGVImage.cpp
    QGVLayerTiles.cpp
    QGVLayerTilesOnline.cpp
    QGVLayerGoogle.cpp
    QGVLayerBing.cpp
    QGVLayerOSM.cpp
    QGVWidget.cpp
    QGVWidgetCompass.cpp
    QGVWidgetScale.cpp
    QGVWidgetZoom.cpp
    QGVWidgetText.cpp
)

target_include_directories(qgeoview
    PUBLIC
        QGeoView
)

target_compile_definitions(qgeoview
    PRIVATE
        QGV_EXPORT
)


target_link_libraries(qgeoview
    PRIVATE
        Qt${QT_VERSION}::Core
        Qt${QT_VERSION}::Gui
        Qt${QT_VERSION}::Widgets
        Qt${QT_VERSION}::Network
)

add_library(QGeoView ALIAS qgeoview)

install(TARGETS qgeoview LIBRARY
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib/static
)

install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/
    DESTINATION include
    FILES_MATCHING PATTERN "*.h*"
)

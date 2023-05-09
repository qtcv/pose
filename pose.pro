win32:{
    include(platform_win32.pri)
}

unix:{
    include(platform_unix.pri)
}


QT += quick

DEFINES += QT_DEPRECATED_WARNINGS
DEFINES += APP_VERSION="\\\"V$${POSE_VERSION}\\\""
CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        src/main.cpp

resources.files = src/main.qml
resources.prefix = /$${TARGET}
RESOURCES += resources

TRANSLATIONS += \
    src/pose_zh_CN.ts
CONFIG += lrelease
CONFIG += embed_translations

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target



# 输出配置
build_type =
CONFIG(debug, debug|release) {
    build_type = build_debug
} else {
    build_type = build_release
}

DESTDIR     = $$build_type/out
OBJECTS_DIR = $$build_type/obj
MOC_DIR     = $$build_type/moc
RCC_DIR     = $$build_type/rcc
UI_DIR      = $$build_type/ui

# 平台配置
win32:{
    INCLUDEPATH += $${OPENCV_DIR}\include\opencv2 \
                    $${OPENCV_DIR}\include

    LIBS += $${OPENCV_DIR}\x64\mingw\lib\libopencv_*.a

    VERSION = $${POSE_VERSION}.000
    RC_ICONS = "img\yoga.ico"
    QMAKE_TARGET_PRODUCT = "pose"
    QMAKE_TARGET_DESCRIPTION = "pose based on Qt $$[QT_VERSION]"
}

unix:!macx:{
    QMAKE_RPATHDIR=$ORIGIN
    QMAKE_LFLAGS += -no-pie

    INCLUDEPATH += -I $${OPENCV_DIR}/include/opencv4
    DEPENDPATH +=$${OPENCV_DIR}/include/opencv4

    INCLUDEPATH += -I $${OPENCV_DIR}/include
    DEPENDPATH +=$${OPENCV_DIR}/include

    LIBS += -L $${OPENCV_DIR}/lib -lopencv_imgproc
    LIBS += -L $${OPENCV_DIR}/lib -lopencv_core

}

macx:{
    QMAKE_RPATHDIR=$ORIGIN
    ICON = "img/yoga.icns"
    QMAKE_INFO_PLIST= macos/Info.plist

    INCLUDEPATH += -I $${OPENCV_DIR}/include/opencv4
    DEPENDPATH +=$${OPENCV_DIR}/include/opencv4

    INCLUDEPATH += -I $${OPENCV_DIR}/include
    DEPENDPATH +=$${OPENCV_DIR}/include

    LIBS += -L $${OPENCV_DIR}/lib -lopencv_imgproc
    LIBS += -L $${OPENCV_DIR}/lib -lopencv_core
    LIBS += -L $${OPENCV_DIR}/lib -lopencv_videoio
    LIBS += -L $${OPENCV_DIR}/lib -lopencv_objdetect

}

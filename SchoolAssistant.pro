#-------------------------------------------------
#
# Project created by QtCreator 2019-11-02T16:06:50
#
#-------------------------------------------------

QT       += core
QT       += gui
QT       += sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SchoolAssistant
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        Controllers/Data/contextdb.cpp \
        Controllers/Data/nametestcontroller.cpp \
        Controllers/Data/questiontestcontroller.cpp \
        Controllers/Data/wronganswertestcontroller.cpp \
        Controllers/applicationcontroller.cpp \
        Controllers/conditiontestcontroller.cpp \
        Controllers/countinganswerstestcontroller.cpp \
        Controllers/questionanswertestcontroller.cpp \
        Controllers/timercontroller.cpp \
        Models/nametest.cpp \
        Models/questiontest.cpp \
        Models/wronganswertest.cpp \
        Views/checklayout.cpp \
        Views/conditiontestview.cpp \
        Views/helper.cpp \
        Views/mainview.cpp \
        Views/questionanswerview.cpp \
        main.cpp

HEADERS += \
    Controllers/Data/contextdb.h \
    Controllers/Data/nametestcontroller.h \
    Controllers/Data/questiontestcontroller.h \
    Controllers/Data/wronganswertestcontroller.h \
    Controllers/applicationcontroller.h \
    Controllers/conditiontestcontroller.h \
    Controllers/countinganswerstestcontroller.h \
    Controllers/questionanswertestcontroller.h \
    Controllers/timercontroller.h \
    Models/nametest.h \
    Models/questiontest.h \
    Models/wronganswertest.h \
    Views/checklayout.h \
    Views/conditiontestview.h \
    Views/helper.h \
    Views/mainview.h \
    Views/questionanswerview.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Controller/controller_calc.cpp \
    Controller/controller_credit.cpp \
    Controller/controller_deposit.cpp \
    View/credit_calculate.cpp \
    View/deposit_calculate.cpp \
    View/dialog.cpp \
    View/main.cpp \
    View/mainwindow.cpp \
    Model/model_calc.cpp \
    Model/model_credit.cpp \
    Model/model_deposit.cpp \
    View/qcustomplot.cpp

HEADERS += \
    Controller/controller_calc.h \
    Controller/controller_credit.h \
    Controller/controller_deposit.h \
    View/credit_calculate.h \
    View/deposit_calculate.h \
    View/dialog.h \
    View/mainwindow.h \
    Model/model_calc.h \
    Model/model_credit.h \
    Model/model_deposit.h \
    View/qcustomplot.h

FORMS += \
    View/credit_calculate.ui \
    View/deposit_calculate.ui \
    View/dialog.ui \
    View/mainwindow.ui

CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

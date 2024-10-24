QT       += core gui
QT       += widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    src/bank.cpp \
    src/bank_account.cpp \
    src/bank_fields.cpp \
    src/function.cpp \
    src/inner_logic.cpp \
    src/mainwindow.cpp \
    src/user_data.cpp

HEADERS += \
    include/inner_logic.h \
    include/mainwindow.h \
    include/ui_mainwindow.h \
    include/user_data.h \
    include/bank_account.h \
    include/bank_fields.h \
    include/bank.h \
    include/function.h \
    include/mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

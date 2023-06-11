QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    dialog.cpp \
    item.cpp \
    list.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    dialog.h \
    item.h \
    list.h \
    mainwindow.h

FORMS += \
    dialog.ui \
    list.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    ../image/0.jpg \
    ../image/1.jpg \
    ../image/2.jpg \
    ../image/3.jpg \
    ../image/4.jpg \
    ../image/5.jpg \
    ../image/6.jpg \
    ../image/7.jpg \
    ../image/8.jpg \
    ../image/Ooo.jpg \
    ../image/ask.jpg \
    ../image/blank1.jpg \
    ../image/blood.jpg \
    ../image/error.jpg \
    ../image/flag.jpg \
    ../image/mine.jpg \
    ../image/smile.jpg \
    0.jpg \
    image/1.jpg \
    image/2.jpg \
    image/3.jpg \
    image/4.jpg \
    image/5.jpg \
    image/6.jpg \
    image/7.jpg \
    image/8.jpg \
    image/Ooo.jpg \
    image/ask.jpg \
    image/blank1.jpg \
    image/blood.jpg \
    image/error.jpg \
    image/flag.jpg \
    image/mine.jpg \
    image/smile.jpg
    RC_ICONS = logo.ico
    QT += multimedia

RESOURCES += \
    resources.qrc \


#-------------------------------------------------
#
# Project created by QtCreator 2017-05-06T19:09:47
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Starship-Battle-System
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    nbproject/private/cpp_standard_headers_indexer.cpp \
    nbproject/private/c_standard_headers_indexer.c \
    src/ship/abstractship.cpp \
    src/ship/ship.cpp \
    src/ship/abstracthull.cpp \
    src/ship/armor.cpp \
    src/utils/constants.cpp \
    src/ship/component/abstractcomponent.cpp \
    src/ship/component/energycomponent.cpp \
    src/ship/component/thruster.cpp \
    src/ship/component/abstractgenerator.cpp \
    src/ship/component/stagegenerator.cpp \
    src/diceExpression/diceexpression.cpp \
    src/diceExpression/subexpression.cpp \
    src/diceExpression/constexpression.cpp \
    src/diceExpression/dice.cpp \
    src/diceExpression/binaryoperator.cpp \
    src/diceExpression/sum.cpp \
    src/utils/utils.cpp \
    src/ship/component/generatorstage.cpp \
    src/ship/component/stopedgeneratorstage.cpp \
    src/ship/component/vepgenerator.cpp \
    src/ship/component/electronsailgenerator.cpp \
    src/ship/basichull.cpp \
    src/ship/reinforcedhull.cpp

HEADERS  += mainwindow.h \
    src/ship/iship.h \
    src/ship/abstractship.h \
    src/ship/ship.h \
    src/ship/abstracthull.h \
    src/ship/armor.h \
    src/ship/component/icomponent.h \
    src/ship/component/abstractcomponent.h \
    src/ship/component/energycomponent.h \
    src/ship/component/thruster.h \
    src/ship/component/abstractgenerator.h \
    src/ship/component/stagegenerator.h \
    src/diceExpression/diceexpression.h \
    src/diceExpression/subexpression.h \
    src/diceExpression/constexpression.h \
    src/diceExpression/dice.h \
    src/diceExpression/binaryoperator.h \
    src/diceExpression/sum.h \
    src/ship/component/generatorstage.h \
    src/ship/component/stopedgeneratorstage.h \
    src/ship/component/vepgenerator.h \
    src/ship/component/electronsailgenerator.h \
    src/ship/basichull.h \
    src/ship/reinforcedhull.h

FORMS    += mainwindow.ui

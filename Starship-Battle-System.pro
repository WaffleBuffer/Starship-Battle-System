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
    src/ship/component/energyComponents/abstractgenerator.cpp \
    src/ship/component/energyComponents/stagegenerator.cpp \
    src/diceExpression/diceexpression.cpp \
    src/diceExpression/subexpression.cpp \
    src/diceExpression/constexpression.cpp \
    src/diceExpression/dice.cpp \
    src/diceExpression/binaryoperator.cpp \
    src/diceExpression/sum.cpp \
    src/utils/utils.cpp \
    src/ship/component/energyComponents/generatorstage.cpp \
    src/ship/component/energyComponents/vepgenerator.cpp \
    src/ship/component/energyComponents/electronsailgenerator.cpp \
    src/ship/basichull.cpp \
    src/ship/reinforcedhull.cpp \
    src/ship/component/sensor.cpp \
    src/ship/component/energyprovidable.cpp \
    src/ship/component/navthruster.cpp \
    src/ship/component/translationthruster.cpp \
    src/ship/component/energyComponents/stoppedgeneratorstage.cpp \
    src/ship/component/rotationthruster.cpp \
    src/utils/shipexception.cpp \
    src/order/shiporder.cpp \
    src/ship/shipcontrol.cpp \
    src/order/provideenergyorder.cpp \
    src/utils/observable.cpp \
    src/utils/observer.cpp \
    src/ship/damage.cpp \
    src/utils/weaponattack.cpp \
    src/utils/myobject.cpp \
    src/ship/damageable.cpp \
    src/ship/component/shield.cpp \
    src/ship/component/weapons/torpedo.cpp \
    src/ship/component/weapons/abstractweapon.cpp \
    src/ship/component/energyComponents/accumulator.cpp \
    src/ship/component/energyComponents/stabilizator.cpp \
    src/utils/orderexception.cpp \
    src/utils/moveable.cpp \
    src/utils/movement.cpp \
    src/utils/vectorialmovement.cpp \
    src/ship/iship.cpp

HEADERS  += mainwindow.h \
    src/ship/iship.h \
    src/ship/abstractship.h \
    src/ship/ship.h \
    src/ship/abstracthull.h \
    src/ship/armor.h \
    src/ship/component/icomponent.h \
    src/ship/component/abstractcomponent.h \
    src/ship/component/energyComponents/abstractgenerator.h \
    src/ship/component/energyComponents/stagegenerator.h \
    src/diceExpression/diceexpression.h \
    src/diceExpression/subexpression.h \
    src/diceExpression/constexpression.h \
    src/diceExpression/dice.h \
    src/diceExpression/binaryoperator.h \
    src/diceExpression/sum.h \
    src/ship/component/energyComponents/generatorstage.h \
    src/ship/component/energyComponents/vepgenerator.h \
    src/ship/component/energyComponents/electronsailgenerator.h \
    src/ship/basichull.h \
    src/ship/reinforcedhull.h \
    src/ship/component/sensor.h \
    src/ship/component/energyprovidable.h \
    src/ship/component/navthruster.h \
    src/ship/component/translationthruster.h \
    src/ship/component/energyComponents/stoppedgeneratorstage.h \
    src/ship/component/rotationthruster.h \
    src/utils/shipexception.h \
    src/order/shiporder.h \
    src/ship/shipcontrol.h \
    src/order/provideenergyorder.h \
    src/utils/observable.h \
    src/utils/observer.h \
    src/ship/damage.h \
    src/utils/weaponattack.h \
    src/utils/myobject.h \
    src/ship/damageable.h \
    src/ship/component/shield.h \
    src/ship/component/weapons/torpedo.h \
    src/ship/component/weapons/abstractweapon.h \
    src/ship/component/energyComponents/accumulator.h \
    src/ship/component/energyComponents/stabilizator.h \
    src/utils/orderexception.h \
    src/utils/moveable.h \
    src/utils/movement.h \
    src/utils/vectorialmovement.h

FORMS    += mainwindow.ui
